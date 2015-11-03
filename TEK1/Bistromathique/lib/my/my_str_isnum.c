/*
** my_str_isnum.c for my_str_isnum in /home/uberti_l/rendu/Piscine_C_J06/ex_12
**
** Made by louis-emile uberti-ares
** Login   <uberti_l@epitech.net>
**
** Started on  Mon Oct 12 22:37:42 2015 louis-emile uberti-ares
** Last update Tue Oct 13 09:23:55 2015 louis-emile uberti-ares
*/

int	my_str_isnum(char *str)
{
  int	count;
  int	garbage;

  garbage = 1;
  count = 0;
  while (str[count] != '\0')
    {
      if ((str[count] < 48) || (str[count] > 57))
	{
	  garbage = 0;
	  break;
	}
      count = count + 1;
    }
  if (garbage == 0)
    return (0);
  else
    return (1);
}
