/*
** info.h for info.h in /home/nicolas.trognot/rendu/Reseau/PSU_2016_zappy/include/graphic
**
** Made by Nicolas TROGNOT
** Login   <nicolas.trognot@epitech.net>
**
** Started on  Sun Jul  2 18:59:17 2017 Nicolas TROGNOT
** Last update Sun Jul  2 19:42:18 2017 grella_c
*/

#ifndef INFO_H_
# define INFO_H_
# include <stdbool.h>
# include "graphic/drawing.h"

typedef struct		s_core t_core;

typedef struct		s_info
{
  bool			display_client;
  int32_t		client_id_to_display;
  bool			display_case;
  t_pos			pos_case_to_display;
}			t_info;

t_info			*init_info();
void			free_info(t_info *info);
void			handle_click(t_core *core, SDL_MouseMotionEvent *pos);

#endif /* !INFO_H_ */
