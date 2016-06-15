/*
** my_getnbr.c for my_getnbr.c in /home/trogno_n/rendu/Piscine_C_J04
**
** Made by nicolas trognot
** Login   <trogno_n@epitech.net>
**
** Started on  Thu Oct  1 20:00:29 2015 nicolas trognot
** Last update Fri Dec 25 10:16:47 2015 nicolas trognot
*/

#include "tools.h"

int	my_getlen(char *str, int start)
{
  int	length;
  int	my_init;
  int	is_finished;

  is_finished = 0;
  my_init = 0;
  length = 1;
  while ((str[start] != '\0') && (is_finished == 0))
    {
      if ((str[start] >= 48) && (str[start] <= 57) && (my_init == 0))
	my_init = 1;
      if ((my_init == 1) && ((str[start] < 48) || (str[start] > 57)))
	{
	  is_finished = 1;
	  my_init = 0;
	}
      length = (my_init == 1) ? (length * 10) : (length);
      start = start + 1;
    }
  return (length);
}

int	my_getnum(char *str, int idx, int length)
{
  int	my_init;
  int	is_finished;
  int	my_num;

  is_finished = 0;
  my_init = 0;
  my_num = 0;
  while ((str[idx] != '\0') && (is_finished == 0))
    {
      if ((str[idx] >= 48) && (str[idx] <= 57) && (my_init == 0))
	my_init = 1;
      if ((my_init == 1) && ((str[idx] < 48) || (str[idx] > 57)))
	{
	  is_finished = 1;
	  my_init = 0;
	}
      if (my_init == 1)
	{
	  my_num = my_num + length * (str[idx] - 48);
	  length = length / 10;
	}
      idx = idx + 1;
    }
  return (my_num);
}

int	my_getsign(char *str)
{
  int	first_nb_founded;
  int	rang;
  int	ret;

  rang = 1;
  first_nb_founded = 0;
  while ((str[rang] != '\0') && (first_nb_founded == 0))
    {
      if ((str[rang] >= 48) && (str[rang] <= 57))
	first_nb_founded = 1;
      rang = rang + 1;
    }
  ret = my_getnum(str, rang - 2, my_getlen(str, rang - 2) / 10);
  if (str[rang - 2] == 45)
    ret = -ret;
  return (ret);
}

int	my_getnbr(char *str)
{
  int	signe;

  if (my_strlen((str)) == 1)
    return (str[0] - 48);
  signe = 0;
  signe = my_getsign(str);
  return (signe);
}
