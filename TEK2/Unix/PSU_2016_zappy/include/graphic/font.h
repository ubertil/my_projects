/*
** font.h for font.h in /home/nicolas.trognot/rendu/Reseau/PSU_2016_zappy/include/graphic
**
** Made by Nicolas TROGNOT
** Login   <nicolas.trognot@epitech.net>
**
** Started on  Sun Jul  2 18:59:04 2017 Nicolas TROGNOT
** Last update Sun Jul  2 18:59:08 2017 Nicolas TROGNOT
*/

#ifndef FONT_H_
# define FONT_H_
# define PATH_TO_FONT "resources/VROUM.font"
# include <SDL/SDL_ttf.h>
# include <stdbool.h>
# include "graphic/drawing.h"

typedef struct		s_font
{
  uint8_t		data[470][5];
  float			scale_x;
  float			scale_y;
  t_color		color;
}			t_font;

t_font			*init_font();
void			free_font(t_font *font);
void			render_font(SDL_Surface *pix, const char *str,
				    t_font *font, t_pos pos);

#endif /* !FONT_H_ */
