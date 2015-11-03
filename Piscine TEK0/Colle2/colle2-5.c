/*
** colle2-5.c for colle2-5 in /home/uberti_l/rendu/Piscine_C_colles-Semaine_02
**
** Made by louis-emile uberti-ares
** Login   <uberti_l@epitech.net>
**
** Started on  Sat Oct 10 13:24:09 2015 louis-emile uberti-ares
** Last update Sun Oct 11 10:36:30 2015 louis-emile uberti-ares
*/

#include <unistd.h>
#include <stdlib.h>

int	my_mouvement_back(int user_value, int x, char *str)
{
  while (x >= 0)
    {
      str[(x - 1)] = 42;
      str[x] = 32;
      x = x - 1;
      str[(user_value - 1)] = 124;
      my_putchar('\r');
      my_putstr(str);
      usleep(20000);
    }
  my_putchar('\r');
  str[0] = 42;
  my_putstr(str);
}

int	my_mouvement(char **argv, int user_value, int size, char *str)
{
  int	x;

  x = 0;
  my_putstr(str);
  my_putstr("Now we wait");
  usleep(1000000);
  while (x < (user_value - 1))
    {
      my_putchar('\r');
      my_putstr(str);
      usleep(20000);
      str[(x + 1)] = 42 ;
      str[x] = 32;
      x = x + 1;
    }
  my_mouvement_back(user_value, x, str);
}

int	my_while(char **argv, int user_value, int size, char *str)
{
  int	i;

  i = 0;
  while (argv[1][i] != '\0')
    {
      str[(i + 1)] = argv[1][i];
      i = i + 1;
    }
  while (i != (user_value - 1))
    {
      str[(i + 1)] = 32;
      i = i + 1;
    }
  str[i] = 124;
  my_mouvement(argv, user_value, size, str);
}

char	my_arena_v2(int argc, char **argv)
{
  char	*str;
  int	user_value;
  int	size;

  user_value = my_getnbr(argv[2]);
  size = my_strlen(argv[1]);
  str = malloc(user_value);
  str[0] = 42;
  if (user_value >= (3 + size))
    my_while(argv, user_value, size, str);
  else
    {
      my_putstr("Size too small");
      my_putchar('\n');
    }
}
