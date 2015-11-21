/*
** my_strncat.c for my_strncat in /home/uberti_l/rendu/Piscine_C_J07/ex_03
**
** Made by louis-emile uberti-ares
** Login   <uberti_l@epitech.net>
**
** Started on  Wed Oct  7 09:32:41 2015 louis-emile uberti-ares
** Last update Wed Oct  7 21:23:37 2015 louis-emile uberti-ares
*/

char	*my_strncat(char *dest, char *src, int nb)
{
  int	i;
  int	a;

  i = 0;
  a = 0;
  while (dest[a] != '\0')
    {
      a = a + 1;
    }
  while ((src[i] != '\0') && (i < nb))
    {
      src[i-1] = '\0';
      dest[a] = src[i];
      a = a + 1;
      i = i + 1;
    }
  return (dest);
}
