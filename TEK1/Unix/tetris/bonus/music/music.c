/*
** music.c for music in /home/uberti_l
**
** Made by louis-emile uberti-ares
** Login   <uberti_l@epitech.net>
**
** Started on  Sun Mar 20 15:20:58 2016 louis-emile uberti-ares
** Last update Sun Mar 20 23:10:00 2016 louis-emile uberti-ares
*/

#include <lapin.h>
#include <unistd.h>

t_bunny_music	*tetris;

void		force_quit_music(void)
{
  (tetris != NULL) ? (bunny_delete_sound(tetris)) : (0);
}

void		game_over_sound(void)
{
  t_bunny_music	*over;
  int		usleep_done;

  if ((over = bunny_load_music("music/game_over.ogg")) == NULL)
    return;
  (tetris != NULL) ? (bunny_delete_sound(tetris)) : (0);
  bunny_sound_play(over);
  sleep(5);
  usleep_done = 1;
  if (usleep_done == 1)
    bunny_delete_sound(over);
}

void		music(void)
{
  if ((tetris = bunny_load_music("music/Tetris_theme.ogg")) == NULL)
    return;
  bunny_sound_play(tetris);
  bunny_sound_loop(tetris, 1);
}
