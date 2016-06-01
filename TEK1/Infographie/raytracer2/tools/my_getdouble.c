/*
** my_getdouble.c for my_getdouble in /home/uberti_l
**
** Made by louis-emile uberti-ares
** Login   <uberti_l@epitech.net>
**
** Started on  Mon Feb 15 12:46:27 2016 louis-emile uberti-ares
** Last update Mon Feb 15 13:24:16 2016 louis-emile uberti-ares
*/

int		get_double_lenght(char *str)
{
  int		lenght;
  int		i;

  i = 0;
  lenght = 1;
  while (str[i] != '\0')
    {
      if (str[i] == '-')
	i += 1;
      if ((str[i] >= '0') && (str[i] <= '9'))
	lenght *= 10;
      if (str[i] == '.')
	return (lenght / 10);
      i += 1;
    }
  return (lenght / 10);
}

double		get_after_dot(char *str, int i, double nb)
{
  double	from_dot;

  from_dot = 10.;
  while (str[i] != '\0')
    {
      if ((str[i] == '0') && (str[i + 1] == '\0'))
	return (nb);
      else
	nb = nb + (double)((str[i] - 48) / from_dot);
      i += 1;
      from_dot *= 10;
    }
  return (nb);
}

double		my_getdouble(char *str)
{
  double	nb;
  int		lenght;
  int		idx;

  idx = 0;
  lenght = get_double_lenght(str);
  nb = 0;
  while (str[idx] != '\0')
    {
      (str[idx] == '-') ? (idx += 1) : (0);
      if (str[idx] == '.')
	{
	  if (str[0] == '-')
	    return (-get_after_dot(str, idx + 1, nb));
	  else
	    return (get_after_dot(str, idx + 1, nb));
	}
      else
	{
	  nb = nb + lenght * (str[idx] - 48);
	  lenght /= 10;
	}
      idx += 1;
    }
  return (nb);
}
