/*
** my_strlen.c for my_strlen in /home/uberti_l/rendu/102cipher
**
** Made by louis-emile uberti-ares
** Login   <uberti_l@epitech.net>
**
** Started on  Mon Nov 16 11:39:12 2015 louis-emile uberti-ares
** Last update Mon Nov 16 11:40:53 2015 louis-emile uberti-ares
*/

int	my_strlen(char *str)
{
  int	i;

  i = 0;
  while (str[i] != '\0')
    i = i + 1;
  return (i);
}
