/*
** my_putstr.c for my_putstr in /home/uberti_l/day04
**
** Made by louis-emile uberti-ares
** Login   <uberti_l@epitech.net>
**
** Started on  Thu Oct  1 09:56:42 2015 louis-emile uberti-ares
** Last update Thu Nov 12 11:43:04 2015 louis-emile uberti-ares
*/

void	my_putchar(char c);

int	my_putstr(char *str)
{
  int	i;
  int	count;

  i = 0;
  count = 0;
  while (str[i] != '\0')
    {
      my_putchar(str[i]);
      i = i + 1;
      count = count + 1;
    }
  return (count);
}
