/*
** my_strcat.c for my_strcat in /home/uberti_l/rendu/Piscine_C_J07/ex_02
**
** Made by louis-emile uberti-ares
** Login   <uberti_l@epitech.net>
**
** Started on  Tue Oct  6 17:39:09 2015 louis-emile uberti-ares
** Last update Wed Oct 14 17:36:17 2015 louis-emile uberti-ares
*/

char	*my_strcat(char *dest, char *src)
{
  int	i;
  int	a;

  i = 0;
  a = 0;
  while (dest[i] != '\0')
    {
      i = i + 1;
    }
  while (src[i] != '\0')
    {
      dest[i] = src[a];
      a = a + 1;
      i = i + 2;
      dest[i] = '\0';
      i = i - 1;
    }
  return (dest);
}
