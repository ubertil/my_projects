/*
** tools.h for tools in /home/uberti_l/rendu/Unix/PSU_2015_42sh
**
** Made by louis-emile uberti-ares
** Login   <uberti_l@epitech.net>
**
** Started on  Thu May  5 14:49:11 2016 louis-emile uberti-ares
** Last update Sun Jun  5 15:51:54 2016 louis-emile uberti-ares
*/

#ifndef TOOLS_H_
# define TOOLS_H_

/*
** STRUCTURES
*/

typedef struct s_shell	t_shell;

/*
** FUNCTIONS
*/

void		my_putstr(const char *str);
int		is_space(const char *str);
int		my_getnbr(char *str);
void		my_put_nbr(const int nb, const int fd);
int		match(char *s1, char *s2);
int		is_separator(const char *sep, const char letter);
int		args_size(char **tab);
char		*my_concat(const int mem, char **args);
char		*get_shell_line(const int fd);
char		**my_str_to_wordtab(const char *str, const char *sep);

#endif /* !TOOLS_H_ */
