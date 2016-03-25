/*
** setup_term.c for setup_term in /Users/uberti_l/rendu/Unix/PSU_2015_tetris
**
** Made by Louis-Emile Uberti
** Login   <uberti_l@epitech.net>
**
** Started on  Thu Mar 17 12:06:33 2016 Louis-Emile Uberti
** Last update Sun Mar 20 20:42:39 2016 louis-emile uberti-ares
*/

#include <term.h>
#include <stdlib.h>
#include "../include/tetris.h"

char		*get_term(char *str)
{
  char		*term;
  int		i;
  int		lenght;

  i = 0;
  while (str[i - 1] != '=')
    i += 1;
  lenght = i;
  while (str[lenght] != '\0')
    lenght += 1;
  lenght = lenght - i;
  if ((term = malloc(lenght + 1)) == NULL)
    return (NULL);
  lenght = 0;
  while (str[i] != '\0')
    term[lenght++] = str[i++];
  term[lenght] = '\0';
  return (term);
}

void		get_capacities(t_tetris *game)
{
  game->left_key = my_strdup(tigetstr("kcub1"));
  game->right_key = my_strdup(tigetstr("kcuf1"));
  game->turn_key = my_strdup(tigetstr("kcuu1"));
  game->drop_key = my_strdup(tigetstr("kcud1"));
}

int		setup_term(t_tetris *game, char **env)
{
  int		i;
  int		ret;
  char		*s;

  i = 0;
  while ((my_strncmp("TERM=", env[i], 4) != 0) && (env[i + 1] != NULL))
    i += 1;
  s = tigetstr("smkx");
  (env[i] != NULL) ? (setupterm(get_term(env[i]), 1, &ret)) : (exit(1));
  if ((ret < 1) || (s == NULL))
    {
      my_putstr_err("Error : Setupterm() failed. Exiting\n");
      return (1);
    }
  get_capacities(game);
  return (0);
}
