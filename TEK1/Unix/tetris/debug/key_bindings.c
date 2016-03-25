/*
** key_bindings1.c for key_bindings in /home/uberti_l/rendu/Unix/PSU_2015_tetris
**
** Made by louis-emile uberti-ares
** Login   <uberti_l@epitech.net>
**
** Started on  Mon Feb 22 16:27:14 2016 louis-emile uberti-ares
** Last update Sat Mar 19 22:14:58 2016 Louis-Emile Uberti
*/

#include <stdlib.h>
#include <unistd.h>
#include "../include/tetris.h"

void		bind_left(t_tetris *game, char *key)
{
  if (my_strncmp(key, "--k", 2) == 0)
    {
      free(game->left_key);
      game->left_key = dupkey(key);
    }
  else if (key != NULL)
    {
      free(game->left_key);
      game->left_key = my_strdup(key);
      game->idx += 1;
    }
  game->option_done = 1;
}

void		bind_right(t_tetris *game, char *key)
{
  if (my_strncmp(key, "--k", 2) == 0)
    {
      free(game->right_key);
      game->right_key = dupkey(key);
    }
  else if (key != NULL)
    {
      free(game->right_key);
      game->right_key = my_strdup(key);
      game->idx += 1;
    }
  game->option_done = 1;
}

void		bind_drop(t_tetris *game, char *key)
{
  if (my_strncmp(key, "--k", 2) == 0)
    {
      free(game->drop_key);
      game->drop_key = dupkey(key);
    }
  else if (key != NULL)
    {
      free(game->drop_key);
      game->drop_key = my_strdup(key);
      game->idx += 1;
    }
  game->option_done = 1;
}

void		bind_quit(t_tetris *game, char *key)
{
  if (my_strncmp(key, "--k", 2) == 0)
    {
      free(game->quit_key);
      game->quit_key = dupkey(key);
    }
  else if (key != NULL)
    {
      free(game->quit_key);
      game->quit_key = my_strdup(key);
      game->idx += 1;
    }
  game->option_done = 1;
}

void		bind_pause(t_tetris *game, char *key)
{
  if (my_strncmp(key, "--k", 2) == 0)
    {
      free(game->pause_key);
      game->pause_key = dupkey(key);
    }
  else if (key != NULL)
    {
      free(game->pause_key);
      game->pause_key = my_strdup(key);
      game->idx += 1;
    }
  game->option_done = 1;
}
