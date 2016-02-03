/*
** flame.c for flame in /home/uberti_l/rendu/gfx_incendie
**
** Made by louis-emile uberti-ares
** Login   <uberti_l@epitech.net>
**
** Started on  Fri Dec  4 23:14:39 2015 louis-emile uberti-ares
** Last update Sat Dec  5 16:33:02 2015 louis-emile uberti-ares
*/

#include <time.h>
#include <stdio.h>
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
      while (i < WIDTH)
	{
	  fire->anim[j][i] += (float)(fire->anim[j][i - 1] / 8);
	  fire->anim[j][i] += (float)(fire->anim[j][i + 1] / 8);
	  fire->anim[j][i] += (float)(fire->anim[j + 1][i - 1] / 8);
	  fire->anim[j][i] += (float)(fire->anim[j - 1][i + 1] / 8);
	  fire->anim[j][i] += (float)(fire->anim[j + 2][i - 1] / 8);
	  fire->anim[j][i] += (float)(fire->anim[j + 2][i] / 8);
	  fire->anim[j][i] += (float)(fire->anim[j + 2][i + 1] / 8);
	  fire->anim[j][i] /= (float)1.85;
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

  i = 0;
  while (i < HEIGHT)
    {
      j = 0;
      while (j++ < WIDTH)
	fire->anim[i][j] = rand() % 128;
      i += 1;
    }
}

void			random_col(t_fire *fire)
{
  int			i;
  int			j;

  i = HEIGHT;
  while (i < HEIGHT + 2)
    {
      j = 0;
      while (j++ < WIDTH)
	fire->anim[i][j] = rand() % 128;
      i += 1;
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
  fire->win = bunny_start(WIDTH, HEIGHT, false, "Effet de flamme uberti_l");
  fire->pix = bunny_new_pixelarray(WIDTH, HEIGHT);
  set_gradient(fire);
  set_background(fire->pix, 0x00000000);
  fixed_col(fire);
  bunny_set_loop_main_function(main_loop);
  bunny_loop(fire->win, 60, fire);
  free_all(fire);
  return (0);
}
