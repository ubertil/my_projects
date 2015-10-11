/*
** my_putstr.c for my_putstr in /home/uberti_l/day04
**
** Made by louis-emile uberti-ares
** Login   <uberti_l@epitech.net>
**
** Started on  Thu Oct  1 09:56:42 2015 louis-emile uberti-ares
** Last update Wed Oct  7 20:09:27 2015 louis-emile uberti-ares
*/

int	my_putstr(char *str)
{
  int	letsgo;

  letsgo = 0;
  while (str[letsgo] != '\0')
    {
      my_putchar(str[letsgo]);
      letsgo = letsgo + 1;
    }
}
