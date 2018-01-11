#pragma once
# include <list>
# include <vector>


class	Trade
{
private:
  double		macd;
  double		avg9;
  double		avg12;
  double		avg26;
  double		prevAvg9;
  double		prevAvg12;
  double		prevAvg26;
  double		money;
  int			stockAmount;
  std::list<double>	vec9;
  std::list<double>	vec12;
  std::list<double>	vec26;
  std::vector<double>	histoMACD;
  std::vector<double>	histoAvg9;
  std::vector<double>	MACDhisto;
  std::vector<double>	histoStock;
  std::vector<double>	histoMoney;
public:
  Trade(double _money);
  Trade(const Trade &cpy) = delete;
  Trade&		operator=(const Trade &cpy) = delete;
  ~Trade(void) = default;
  void			setMACD(double stockValue);
  void			setSMA(double stockValue);
  void			brewingMoney(void);
  void			buy(double stockValue);
  void			sell(double stockValue);
  void			generateGraph(void);
};
