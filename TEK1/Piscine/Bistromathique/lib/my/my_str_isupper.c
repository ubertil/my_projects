/*
** my_str_isupper.c for my_str_isupper in /home/uberti_l/rendu/Piscine_C_J06/ex_14
**
** Made by louis-emile uberti-ares
** Login   <uberti_l@epitech.net>
**
** Started on  Tue Oct 13 09:20:36 2015 louis-emile uberti-ares
** Last update Tue Oct 13 09:23:48 2015 louis-emile uberti-ares
*/

int	my_str_isupper(char *str)
{
  int	garbage;
  int	count;

  garbage = 1;
  count = 0;
  while (str[count] != '\0')
    {
      if ((str[count] < 65 ) || (str[count] > 90))
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
