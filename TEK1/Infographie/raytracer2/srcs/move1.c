/*
** move1.c for move1 in /home/uberti_l/rendu/Infographie/gfx_raytracer2
**
** Made by louis-emile uberti-ares
** Login   <uberti_l@epitech.net>
**
** Started on  Thu May 19 05:02:03 2016 louis-emile uberti-ares
** Last update Sun May 22 17:19:48 2016 louis-emile uberti-ares
*/

#include "raytracer2.h"

void		move2(t_bunny_event_state state,
		      t_bunny_keysym key,
		      t_rtc *rtc)
{
  if (state == GO_DOWN && key == BKS_S)
    rtc->cam_pos[2] += 0.05;
  if (state == GO_DOWN && key == BKS_Z)
    rtc->cam_pos[2] -= 0.05;
  if (state == GO_DOWN && key == BKS_SPACE)
    bunny_save_pixelarray(rtc->cam, "rendu.png");
}

void		move1(t_bunny_event_state state,
		      t_bunny_keysym key,
		      t_rtc *rtc)
{
  if (state == GO_DOWN && key == BKS_DOWN)
    rtc->cam_pos[1] -= 0.05;
  if (state == GO_DOWN && key == BKS_UP)
    rtc->cam_pos[1] += 0.05;
  if (state == GO_DOWN && key == BKS_LEFT)
    rtc->cam_pos[0] += 0.05;
  if (state == GO_DOWN && key == BKS_RIGHT)
    rtc->cam_pos[0] -= 0.05;
}
