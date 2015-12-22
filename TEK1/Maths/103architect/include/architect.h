/*
** architect.h for architect in /home/uberti_l/rendu/103architect/include
**
** Made by louis-emile uberti-ares
** Login   <uberti_l@epitech.net>
**
** Started on  Wed Dec  9 13:30:48 2015 louis-emile uberti-ares
** Last update Thu Dec 10 13:36:08 2015 louis-emile uberti-ares
*/

#ifndef ARCHITECT_H_
# define ARCHITECT_H_

typedef struct	s_num
{
  float		number;
  struct s_num	*next;
}		t_num;

typedef struct	s_fla
{
  char		flags;
  struct s_fla *next;
}		t_fla;

typedef struct	s_info
{
  t_fla		*flags;
  t_num		*numbers;
  int		disp_matrix;
}		t_info;

typedef struct	s_list
{
  char		letter;
  int		(*func)(t_info *info);
}		t_list;

t_info		*parseur_argv(int ac, char **av);
int		do_translation(t_info *info);
int		do_homothety(t_info *info);
int		do_rotation(t_info *info);
int		do_symmetry(t_info *info);

#endif /* !ARCHITECT_H_ */
