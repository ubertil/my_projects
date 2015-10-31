/*
** my_div.c for my_div.c in /home/trogno_n/rendu/Piscine_C_div
**
** Made by nicolas trognot
** Login   <trogno_n@epitech.net>
**
** Started on  Wed Oct 28 11:26:34 2015 nicolas trognot
** Last update Sat Oct 31 18:14:35 2015 louis-emile uberti-ares
*/

#include <stdlib.h>
#include "include/bistromathique.h"
#include "include/my.h"

t_div	*init_my_mod(char *n1, char *n2)
{
  t_div	*d;
  d = malloc(sizeof(t_div));
  if (d == NULL)
    return (NULL);
  d->length = my_strlen(n2) + 1;
  d->dvd = malloc(my_strlen(n1) + 1);
  d->dvs = malloc(my_strlen(n2) + 1);
  d->temp_fact = malloc(my_strlen(n1) + 1);
  d->temp_cmp = malloc(my_strlen(n1) + 1);
  d->total = malloc(my_strlen(n2) + 1);
  d->mod = malloc(my_strlen(n1) + 1);
  if ((d->dvd == NULL) || (d->dvs == NULL))
    return (NULL);
  if ((d->temp_fact == NULL) || (d->temp_cmp == NULL))
    return (NULL);
  if (d->total == NULL)
    return (NULL);
  d->temp_cmp[my_strlen(n2) + 1] = EOS;
  my_strcpy(d->dvd, n1);
  my_strcpy(d->dvs, n2);
  my_strcpy(d->mod, "0");
  my_strcpy(d->temp_cmp, d->dvs);
  my_strcpy(d->temp_fact, "1");
  my_strcpy(d->total, "0");
  return (d);
}

char	*my_modulo(char *n1, char *n2)
{
  t_div *d;

  d = init_my_mod(n1, n2);
  if ((d != NULL) && (my_str_isnum(d->dvd) == 1) && (my_str_isnum(d->dvs) == 1))
    if (d->dvs[0] != '0')
      {
	while (d->dvd[0] != '-')
	  {
	    if ((my_do_op_sub_cmp(d->dvs, d->dvd, 0, 0) == 0) &&
		(d->mod[0] == '0'))
	      my_strcpy(d->mod, d->dvd);
	    my_strcpy(d->temp_cmp, d->dvs);
	    my_strcpy(d->temp_fact, "1");
	    while (my_do_op_sub_cmp(d->temp_cmp, d->dvd, 0, 0) == 1)
	      add_zero(d);
	    (check_digits(d) == 1) ? (add_zero(d)) : (1);
	    remove_zero(d);
	    if (check_digits(d) == 1)
	      d->temp_fact = add_sub(d->temp_fact, "-1");
	    get_minus(d->temp_cmp);
	    d->total = add_sub(d->total, d->temp_fact);
	    d->dvd = add_sub(d->dvd, d->temp_cmp);
	  }
	free(d);
	return (d->mod);
      }
    else
      my_putstr(DIV_0);
  return (0);
}
