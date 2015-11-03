/*
** my_strncpy.c for my_strncpy in /home/uberti_l/rendu/Piscine_C_J06
**
** Made by louis-emile uberti-ares
** Login   <uberti_l@epitech.net>
**
** Started on  Mon Oct  5 10:50:19 2015 louis-emile uberti-ares
** Last update Wed Oct 14 17:52:07 2015 louis-emile uberti-ares
*/

char	*my_strncpy(char *dest, char *src, int nb)
{
  int	i;

  i = 0;
  while ((i < nb) && (src[i] != '\0'))
    {
      dest[i] = src[i];
      i = i + 1;
      dest[nb] = '\0';
    }
  return (dest);
}
