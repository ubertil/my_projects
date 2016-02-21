/*
** allum.h for allum in /home/uberti_l/rendu/Prog_elem/CPE_2015_Allum1/include
**
** Made by louis-emile uberti-ares
** Login   <uberti_l@epitech.net>
**
** Started on  Mon Feb  8 11:23:45 2016 louis-emile uberti-ares
** Last update Sun Feb 21 22:13:11 2016 louis-emile uberti-ares
*/

#ifndef ALLUM_H_
# define ALLUM_H_
# define READ_SIZE (24)

typedef struct	s_allum
{
  char		**board;
  char		*line;
  char		*matches;
  int		*lines;
  int		select_line;
  int		select_matches;
  int		nb_lines;
  int		ia_win;
}		t_allum;

int		my_putstr(char *str);
int		my_getnbr(char *str);
int		my_strlen(char *str);
int		ia_play(t_allum *allum);
int		check_error(t_allum *allum);
int		is_nbr(char *str);
void		disp_board(t_allum *allum);
void		free_all(t_allum *allum);
void		my_putchar(char c);
void		first_prompt(void);
void		prompt_player(t_allum *allum);
void		my_putstr_err(char *str);
char		*get_shell_line(const int fd);
char		*my_strdup(char *str);

#endif /* !ALLUM_H_ */
