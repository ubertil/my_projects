/*
** my_str_isprintable.c for my_str_isprintable in /home/uberti_l/rendu/Piscine_C_J06/ex_15
**
** Made by louis-emile uberti-ares
** Login   <uberti_l@epitech.net>
**
** Started on  Tue Oct 13 09:25:10 2015 louis-emile uberti-ares
** Last update Tue Oct 13 09:30:20 2015 louis-emile uberti-ares
*/

int	my_str_isprintable(char *str)
{
  int	garbage;
  int	count;

  garbage = 1;
  count = 0;
  while (str[count] != '\0')
    {
      if ((str[count] < 32) || (str[count] == 127))
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
