/*
** my_strlen.c for my_strlen.c in /home/trognot/rendu/IA/dante
**
** Made by nicolas trognot
** Login   <nicolas.trognot@epitech.eu>
**
** Started on  Wed May 18 13:39:21 2016 nicolas trognot
** Last update Wed May 18 13:39:21 2016 nicolas trognot
*/

int	my_strlen(const char *str)
{
  int	i;

  if (!str)
    return (0);
  i = 0;
  while (str[i])
    i++;
  return (i);
}
