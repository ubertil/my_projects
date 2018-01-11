//
// Trade.cpp for Trade in /home/uberti_l/rendu/Maths/trade
//
// Made by Lous-Emile Uberti-Ares
// Login   <uberti_l@epitech.net>
//
// Started on  Sun Jun 11 20:01:49 2017 Lous-Emile Uberti-Ares
// Last update Sun Jun 11 20:25:23 2017 Lous-Emile Uberti-Ares
//

#include <iostream>
#include <string>
#include <math.h>
#include <fstream>
#include "Trade.hh"

Trade::Trade(double _money) : money(_money) {}

void		Trade::generateGraph(void)
{
  std::ofstream	stockAction("stock.dat");
  std::ofstream	histogram("histo.dat");
  std::ofstream	MACD("MACD.dat");
  std::ofstream	money("money.dat");
  std::ofstream	macdAvg("macdAverage.dat");
  int		i;

  i = 0;
  if (stockAction.fail() || histogram.fail() ||
      MACD.fail() || money.fail() || macdAvg.fail())
    {
      std::cerr << "Could not create graph files." << std::endl;
      std::cerr << "No write permission ?" << std::endl;
      return ;
    }
  for (double &e : this->histoStock)
    {
      stockAction << i << " " << e << std::endl;
      ++i;
    }
  stockAction.close();
  i = this->histoStock.size() - this->histoMACD.size();;
  for (double &e : this->histoMACD)
    {
      histogram << i << " " << e << std::endl;
      ++i;
    }
  histogram.close();
  i = this->histoStock.size() - this->MACDhisto.size();
  for (double &e : this->MACDhisto)
    {
      MACD << i << " " << e << std::endl;
      ++i;
    }
  MACD.close();
  i = 0;
  for (double &e : this->histoMoney)
    {
      money << i << " " << e << std::endl;
      ++i;
    }
  money.close();
  i = this->histoMoney.size() - this->histoAvg9.size();
  for (double &e : this->histoAvg9)
    {
      macdAvg << i << " " << e << std::endl;
      ++i;
    }
  macdAvg.close();
}

void		Trade::setMACD(double stockValue)
{
  double	constante12 = 2.f / 13.f;
  double	constante26 = 2.f / 27.f;

  this->prevAvg12 = this->avg12;
  this->avg12 = (stockValue - this->prevAvg12) * constante12 + this->prevAvg12;
  this->prevAvg26 = this->avg26;
  this->avg26 = (stockValue - this->prevAvg26) * constante26 + this->prevAvg26;
  this->macd = this->avg12 - this->avg26;
  this->MACDhisto.push_back(this->macd);
}

void	Trade::setSMA(double stockValue)
{
  if (this->vec12.size() == 12)
    this->vec12.pop_front();
  this->vec12.push_back(stockValue);
  if (this->vec26.size() == 26)
    this->vec26.pop_front();
  this->vec26.push_back(stockValue);
}

void	Trade::buy(double stockValue)
{
  int	maxToBuy;

  maxToBuy = this->money / stockValue;
  if ((maxToBuy * stockValue) + (maxToBuy * stockValue * 0.0015) > this->money)
    --maxToBuy;
  this->stockAmount += maxToBuy;
  this->money -= ((maxToBuy * stockValue) + (maxToBuy * stockValue * 0.0015));
  if (maxToBuy == 0)
    std::cout << "wait" << std::endl;
  else
    std::cout << "buy " << maxToBuy << std::endl;
}

void	Trade::sell(double stockValue)
{
  this->money += (this->stockAmount * stockValue);
  this->money -= (this->stockAmount * stockValue * 0.0015);

  if (this->stockAmount > 0)
    std::cout << "sell " << this->stockAmount << std::endl;
  else
    std::cout << "wait" << std::endl;
  this->stockAmount = 0;
}

void	Trade::brewingMoney(void)
{
  double	constante9 = 2.f / 10.f;
  double	stockValue;
  int		i(1);
  std::string	line;
  this->stockAmount = 0;
  this->avg9 = 0;

  while (true)
    {
      std::cin >> line;
      if (line == "--end--")
	break ;
      stockValue = std::stod(line);
      if (i - 1 < 26)
	this->setSMA(stockValue);
      if (i - 1 == 26)
	{
	  for (double e : this->vec12)
	    this->avg12 += e;
	  this->avg12 /= 12;
	  for (double e : this->vec26)
	    this->avg26 += e;
	  this->avg26 /= 26;
	}
      if (i - 1 >= 26)
	{
	  this->setMACD(stockValue);
	  if (this->vec9.size() < 9)
	    this->vec9.push_back(this->macd);
	  if (this->vec9.size() == 9)
	    {
	      if (this->avg9 == 0)
		{
		  for (double &e : this->vec9)
		    this->avg9 += e;
		  this->avg9 /= 9;
		}
	      else
		{
		  this->prevAvg9 = this->avg9;
		  this->avg9 = (this->macd - this->prevAvg9) * constante9 + this->prevAvg9;
		  this->histoAvg9.push_back(this->avg9);
		  this->histoMACD.push_back(this->macd - this->avg9);
		}
	      if (this->histoMACD.size() > 1)
		{
		  if (this->macd > this->avg9 && this->histoMACD.back() < this->histoMACD.at(this->histoMACD.size() - 2))
		    this->buy(stockValue);
		  else if (this->macd < this->avg9 && this->histoMACD.back() > this->histoMACD.at(this->histoMACD.size() - 2))
		    this->sell(stockValue);
		  else
		    std::cout << "wait" << std::endl;
		}
	      else
		std::cout << "wait" << std::endl;
	      this->histoStock.push_back(stockValue);
	      this->histoMoney.push_back(this->money);
	    }
	  else
	    std::cout << "wait" << std::endl;
	}
      else
	std::cout << "wait" << std::endl;
      ++i;
    }
  this->sell(stockValue);
}
