/*
** tools_div.c for tools_div.c in /home/trogno_n/rendu/Piscine_C_div
**
** Made by nicolas trognot
** Login   <trogno_n@epitech.net>
**
** Started on  Sat Oct 31 16:53:48 2015 nicolas trognot
** Last update Sat Oct 31 18:11:18 2015 louis-emile uberti-ares
*/

#include <stdlib.h>
#include "include/bistromathique.h"
#include "include/my.h"

int   add_zero(t_div *d)
{
  my_strcat(d->temp_fact, "0\0");
  my_strcat(d->temp_cmp, "0\0");
  return (0);
}

int     remove_zero(t_div *d)
{
  d->temp_cmp[my_strlen(d->temp_cmp) - 1] = EOS;
  d->temp_fact[my_strlen(d->temp_fact) - 1] = EOS;
  return (0);
}

char    *get_minus(char *str)
{
  int   i;

  i = my_strlen(str) - 1;
  while (i >= 0)
    {
      str[i + 1] = str[i];
      i = i - 1;
    }
  str[0] = '-';
  return (str);
}

int     check_digits(t_div *d)
{
  if ((my_do_op_sub_cmp(d->temp_cmp, d->dvd, 0, 0) == 0) &&
      (my_strlen(d->temp_cmp) == 1) && (my_strlen(d->dvs) == 1))
    return (1);
  else
    return (0);
}

char    *check_neg(t_div *d, char *n, int mode, int i)
{
  if (mode == 1)
    {
      if ((n[0] == '-') && (n[1] != '\0'))
        {
          while (n[i] != '\0')
            {
              n[i - 1] = n[i];
              i = i + 1;
            }
          n[i - 1] = n[i];
          d->is_neg = d->is_neg + 1;
        }
    }
  else
    {
      if (d->is_neg == 1)
        {
          n = get_minus(n);
        }
    }
  return (n);
}
