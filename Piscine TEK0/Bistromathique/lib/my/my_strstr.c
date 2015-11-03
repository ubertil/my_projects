/*
** my_strstr.c for my_strstr in /home/uberti_l/rendu/Piscine_C_J06/ex_05
**
** Made by louis-emile uberti-ares
** Login   <uberti_l@epitech.net>
**
** Started on  Mon Oct 12 19:48:42 2015 louis-emile uberti-ares
** Last update Mon Oct 12 19:59:12 2015 louis-emile uberti-ares
*/

int	my_putstr_found(char *str, int count2)
{
  while (str[count2] != '\0')
    {
      my_putchar(str[count2]);
      count2 = count2 + 1;
    }
}

char	*my_strstr(char *str, char *to_find)
{
  int	count1;
  int	count2;

  count1 = 0;
  count2 = 0;
  while ((to_find[count1] != '\0') && (str[count2] != '\0'))
    {
      if (str[count1] == to_find[count2])
	{
	  count1 = count1 + 1;
	  count2 = count2 + 1;
	}
      else
	{
	  count1 = 0;
	  count2 = count2 + 1;
	}
    }
  if (count1 > 0)
    {
      count2 = count2 - count1;
      my_putstr_found(str, count2);
    }
  else
    return (0);
}
