/*
** timer_handle.c for timer_handle in /Users/uberti_l/rendu/Unix/PSU_2015_tetris
**
** Made by Louis-Emile Uberti
** Login   <uberti_l@epitech.net>
**
** Started on  Wed Mar 16 12:28:04 2016 Louis-Emile Uberti
** Last update Fri Mar 25 17:56:19 2016 louis-emile uberti-ares
*/

#include <time.h>
#include <unistd.h>
#include "../include/tetris.h"

void		init_time(time_t *old, time_t *new)
{
  *old = time(NULL);
  *new = time(NULL);
}

void		timer(t_tetris *game)
{
  static time_t old = 0;
  static time_t new = 0;

  if (old == 0)
    init_time(&old, &new);
  new = time(NULL);
  if ((old % (3600 * 60 * 600)) - (new % (3600 * 60 * 6000)) <= -1)
    game->timer[4] += 1;
  if (game->timer[4] > 20000)
    game->timer[4] = 1;
  if ((old % (3600 * 60 * 60)) - (new % (3600 * 60 * 60)) <= -1)
    {
      old = time(NULL);
      game->timer[3] += 1;
    }
  (game->timer[3] == 10) ? (game->timer[2] += 1, game->timer[3] = 0) : (0);
  (game->timer[2] == 6) ? (game->timer[1] += 1, game->timer[2] = 0) : (0);
  (game->timer[1] == 10) ? (game->timer[0] += 1, game->timer[1] = 0) : (0);
}
