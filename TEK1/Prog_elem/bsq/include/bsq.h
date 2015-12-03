/*
** bsq.h for bsq in /home/uberti_l/rendu/CPE_2015_bsq/include
**
** Made by louis-emile uberti-ares
** Login   <uberti_l@epitech.net>
**
** Started on  Tue Nov 24 15:58:31 2015 louis-emile uberti-ares
** Last update Tue Dec  1 11:19:24 2015 louis-emile uberti-ares
*/

#ifndef BSQ_H_
# define BSQ_H_

typedef struct	s_stock
{
  unsigned int	lenght;
  int		fd;
  char		**map;
  int		nb_lines;
}		t_stock;

void		my_printf(const char *format, ...);
void		fill_my_map(t_stock *a);
void		find_my_cube(t_stock *a);
int		my_putstr(char *str);
void		my_putchar(char c);

#endif /* !BSQ_H */
