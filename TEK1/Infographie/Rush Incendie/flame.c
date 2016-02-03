/*
** flame.c for flame in /home/uberti_l/rendu/gfx_incendie
**
** Made by louis-emile uberti-ares
** Login   <uberti_l@epitech.net>
**
** Started on  Fri Dec  4 23:14:39 2015 louis-emile uberti-ares
** Last update Sun Dec  6 22:11:45 2015 louis-emile uberti-ares
*/

#include <time.h>
#include <lapin.h>
#include "include/flame.h"

void			set_color(t_fire *fire)
{
  int			i;
  int			j;

  j = HEIGHT - 1;
  while (j >= 1)
    {
      i = 0;
      while (i <= WIDTH)
	{
	  fire->anim[j][i] += fire->anim[j + 1][i];
	  fire->anim[j][i] += fire->anim[j + 1][i - 1];
	  fire->anim[j][i] += fire->anim[j + 1][i + 1];
	  fire->anim[j][i] += fire->anim[j + 2][i];
	  fire->anim[j][i] /= 5;
	  fire->pos.x = i;
	  fire->pos.y = j;
	  tekpixel(fire->pix, &fire->pos, fire->gradient[fire->anim[j][i]]);
	  i += 1;
	}
      j -= 1;
    }
}

void			fixed_col(t_fire *fire)
{
  int			i;
  int			j;

  j = 0;
  while (j <= HEIGHT)
    {
      i = 0;
      while (i++ <= WIDTH)
	fire->anim[j][i] = 0;
      j += 1;
    }
}

void			random_col(t_fire *fire)
{
  int			i;
  int			j;

  j = HEIGHT;
  while (j <= HEIGHT + 1)
    {
      i = 0;
      while (i++ <= WIDTH)
	fire->anim[j][i] = rand() % 128;
      j += 1;
    }
}

t_bunny_response	main_loop(void *_fire)
{
  t_fire		*fire;

  fire = _fire;
  random_col(fire);
  set_color(fire);
  bunny_blit(&fire->win->buffer, &fire->pix->clipable, NULL);
  bunny_display(fire->win);
  return (GO_ON);
}

int			main(void)
{
  t_fire		*fire;

  if ((fire = bunny_malloc(sizeof(t_fire))) == NULL)
    return (1);
  fire->win = bunny_start(WIDTH, HEIGHT, false, "Incendie uberti_l | peixot_a");
  fire->pix = bunny_new_pixelarray(WIDTH, HEIGHT);
  fixed_col(fire);
  set_gradient(fire);
  set_background(fire->pix, 0x00000000);
  bunny_set_loop_main_function(main_loop);
  bunny_loop(fire->win, 60, fire);
  free_all(fire);
  return (0);
}
