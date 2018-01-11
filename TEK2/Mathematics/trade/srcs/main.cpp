//
// main.cpp for main in /home/uberti_l/rendu/Maths/trade/srcs
//
// Made by Lous-Emile Uberti-Ares
// Login   <uberti_l@epitech.net>
//
// Started on  Tue Jun  6 00:14:19 2017 Lous-Emile Uberti-Ares
// Last update Wed Jun  7 20:25:09 2017 Lous-Emile Uberti-Ares
//

#include <memory>
#include <exception>
#include <iostream>
#include "Trade.hh"

int		main(void)
{
  double	money;
  int		days;

  std::cin >> money;
  std::cin >> days;
  (void)days;
  Trade		trader(money);
  try
    {
      trader.brewingMoney();
      trader.generateGraph();
    }
  catch (const std::exception &err)
    {
      std::cerr << "trade: error on " << err.what() << std::endl;
      std::cerr << "Aborting execution" << std::endl;
    }
  return (0);
}
