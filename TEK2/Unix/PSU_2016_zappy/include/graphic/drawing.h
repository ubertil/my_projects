/*
** drawing.h for zappy in /home/papadi_a/work/epitech/Tek2/PSU/PSU_2016_zappy
**
** Made by alexis papadimitriou
** Login   <papadi_a@epitech.net>
**
** Started on  Tue Jun 27 12:00:35 2017 alexis papadimitriou
** Last update Sun Jul  2 19:40:54 2017 grella_c
*/

#ifndef DRAWING_H_
# define DRAWING_H_
# define R 0
# define G 1
# define B 2
# define A 3
# define BLACK 0xFF000000
# define RED 0xFFFF0000
# define GREEN 0xFF00FF00
# define BLUE 0xFF0000FF
# define PURPLE 0xFFFF00FF
# define TEAL 0xFF00FFFF
# define YELLOW 0xFFFFFF00
# define WHITE 0xFFFFFFFF
# define PINK 0xFFFF7777
# define PINK2 0XFFFF69B4
# include <SDL/SDL.h>
# include <stdint.h>

typedef union	u_color
{
  uint32_t	full;
  uint8_t	argb[4];
}		t_color;

typedef struct	s_pos
{
  int32_t	x;
  int32_t	y;
}		t_pos;

void		putpixel(SDL_Surface *pix, int32_t x, int32_t y, uint32_t c);
void		putpixel_a(SDL_Surface *pix, int32_t x, int32_t y, uint32_t c);
uint32_t	getpixel(const SDL_Surface *pix, int32_t x, int32_t y);
void		fill(SDL_Surface *pix, uint32_t c);
void		blit_surface(SDL_Surface *pix, const SDL_Surface *src,
			     int32_t x, int32_t y);
SDL_Surface	*stretch(SDL_Surface *pix, uint32_t size);

#endif /* !DRAWING_H_ */
