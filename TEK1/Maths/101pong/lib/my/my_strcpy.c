/*
** my_strcpy.c for my_strcpy in /home/uberti_l/rendu/Piscine_C_J06
**
** Made by louis-emile uberti-ares
** Login   <uberti_l@epitech.net>
**
** Started on  Mon Oct  5 09:35:33 2015 louis-emile uberti-ares
** Last update Fri Oct 30 13:34:23 2015 louis-emile uberti-ares
*/

char	*my_strcpy(char *dest, char *src)
{
  int	i;
  int	count;

  count = my_strlen(dest);
  while (src[i] != '\0')
    {
      dest[count] = src[i];
      count = count + 1;
      i = i + 1;
    }
  dest[count] = '\0';
  return (dest);
}
