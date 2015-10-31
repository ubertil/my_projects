/*
** my_show_wordtab.c for my_show_wordtab in /home/uberti_l/rendu/Piscine_C_J08/ex_03
**
** Made by louis-emile uberti-ares
** Login   <uberti_l@epitech.net>
**
** Started on  Thu Oct  8 14:44:09 2015 louis-emile uberti-ares
** Last update Wed Oct 14 17:34:42 2015 louis-emile uberti-ares
*/

#include <stdlib.h>

int	my_show_wordtab(char **tab)
{
  int	i;
  int	a;
  int	b;
  char	*str;

  i = 0;
  a = 0;
  b = 0;
  str = malloc(sizeof(tab));
  while (tab[i] != 0)
    {
      a = 0;
      while (tab[i][a] != '\0')
	{
	  str[b] = tab[i][a];
	  a = a + 1;
	  b = b + 1;
	}
      str[b] = '\n';
      b = b + 1;
      i = i + 1;
    }
  my_putstr(str);
}
