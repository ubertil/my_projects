#ifndef FLAME_H_
# define FLAME_H_
# define WIDTH 800
# define HEIGHT 800

#include <lapin.h>

typedef struct		s_fire
{
  t_bunny_window	*win;
  t_bunny_pixelarray	*pix;
  t_bunny_position	pos;
  unsigned int		gradient[128];
  int			anim[HEIGHT + 2][WIDTH];
}			t_fire;

void			tekpixel(t_bunny_pixelarray *pix,
				 t_bunny_position *pos,
				 unsigned int color);

void			set_background(t_bunny_pixelarray *pix,
				       unsigned int color);

void			free_all(t_fire *fire);

unsigned int		tekgetpixel(t_bunny_pixelarray *pix,
				    t_bunny_position *pos);

void			set_gradient(t_fire *fire);

#endif /* FLAME_H_ */
