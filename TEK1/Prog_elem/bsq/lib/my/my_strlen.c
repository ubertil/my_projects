/*
** my_strlen.c for my_strlen in /home/uberti_l/day04
**
** Made by louis-emile uberti-ares
** Login   <uberti_l@epitech.net>
**
** Started on  Thu Oct  1 09:57:52 2015 louis-emile uberti-ares
** Last update Tue Nov 10 16:08:44 2015 louis-emile uberti-ares
*/

int	my_strlen(char *str)
{
  int	count;

  count = 0;
  while (str[count] != '\0')
      count = count + 1;
  return (count);
}
