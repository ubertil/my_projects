/*
** 101pong.h for 101pong in /home/uberti_l/rendu/101pong/include
**
** Made by louis-emile uberti-ares
** Login   <uberti_l@epitech.net>
**
** Started on  Mon Nov  2 20:22:39 2015 louis-emile uberti-ares
** Last update Mon Nov  9 11:29:40 2015 louis-emile uberti-ares
** Last update Tue Nov  3 16:17:42 2015 louis-emile uberti-ares
*/

#ifndef PONG_H_
# define PONG_H_

/*
** STRUCTURES
*/

struct			s_stock
{
  float		x0;
  float		y0;
  float		z0;
  float		x1;
  float		y1;
  float		z1;
  float		x;
  float		y;
  float		z;
  float		xt;
  float		yt;
  float		zt;
  int		n;
  float		angle;
  float		norme_v;
  unsigned int	mode;
};

typedef struct	s_stock t_stock;

/*
**  PROTOTYPES
*/

void		my_init(char **av);
int		my_calculus(t_stock *a);
int		my_final_return(t_stock *a);
t_stock		*ball_coordinates(t_stock *a);
t_stock		*speed_vector(t_stock *a);

#endif /* !PONG_H_ */
