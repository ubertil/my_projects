/*
** my.h for my.h in /home/uberti_l/pushswap/include
**
** Made by louis-emile uberti-ares
** Login   <uberti_l@epitech.net>
**
** Started on  Tue Nov 17 16:46:01 2015 louis-emile uberti-ares
** Last update Wed Nov 18 17:31:01 2015 louis-emile uberti-ares
*/

#ifndef MY_H_
# define MY_H_

typedef struct	s_swap
{
  int		nb;
  struct s_swap	*next;
}		t_swap;

typedef struct	s_list
{
  t_swap	*l_a;
  t_swap	*l_b;
  int		idx_la;
  int		perm;
}		t_list;

int		my_getnbr(char *str);
int		init_my_tab(int nb, t_swap **a);
void		pushswap(t_list *a);
int		my_put_nbr(int nb);

#endif /* !MY_H_ */
