/*
** bsq.h for bsq in /home/uberti_l/rendu/CPE_2015_bsq/include
**
** Made by louis-emile uberti-ares
** Login   <uberti_l@epitech.net>
**
** Started on  Tue Nov 24 15:58:31 2015 louis-emile uberti-ares
** Last update Mon Dec 21 20:32:16 2015 louis-emile uberti-ares
*/

#ifndef BSQ_H_
# define BSQ_H_

typedef struct	s_bsq
{
  char		*final;
  int		**M;
  int		**S;
  unsigned int	nb_lines;
  unsigned int	lenght;
  unsigned int	idx;
  unsigned int	lines;
  unsigned int	row;
  unsigned int	columns;
  int		max;
  int		size;
}		t_bsq;

int		my_putstr_err(char *str);
void		my_putchar(char c);
int		my_putstr(char *str);
int		my_getnbr(char *str);
void		free_all(t_bsq *bsq, char *file);
void		my_core(t_bsq *bsq, char *file);
void		find_square(t_bsq *bsq);
void		find_coordinates(t_bsq *bsq);
void		display_square(t_bsq *bsq, char *file);
void		init_my_bsq(t_bsq *bsq, char *file);

#endif /* !BSQ_H */
