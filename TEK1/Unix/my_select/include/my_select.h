/*
** my_select.h for my_select in /home/uberti_l/rendu/PSU_2015_my_select/include
**
** Made by louis-emile uberti-ares
** Login   <uberti_l@epitech.net>
**
** Started on  Mon Nov 30 21:07:30 2015 louis-emile uberti-ares
** Last update Wed Dec  2 16:33:10 2015 louis-emile uberti-ares
*/

#ifndef MY_SELECT_H_
# define MY_SELECT_H_

typedef struct	s_arg
{
  char		*arg;
  struct s_arg	*next;
  struct s_arg	*prev;
}		t_arg;

typedef struct	s_select
{
  int		cursor;
  int		nb_arg;
  int		key;
}		my_select;

void		print(t_arg *a);
t_arg		*init_arg();
void		free_all(t_arg *a);
void		init_my_argv(char *str, t_arg *a);
void		go_up(t_arg *a);
void		go_down(t_arg *a);
void		my_send(t_arg *a);
int		my_putstr(char *str);
void		my_putchar(char c);
int		my_strlen(char *str);
char		*my_strdup(char *src);

#endif /* !MY_SELECT_H_ */
