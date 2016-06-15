/*
** tools.h for tools in /Users/uberti_l/rendu/IA/dante
**
** Made by Louis-Emile Uberti
** Login   <uberti_l@epitech.net>
**
** Started on  Tue May  3 14:12:44 2016 Louis-Emile Uberti
** Last update Tue May  3 14:18:06 2016 Louis-Emile Uberti
*/

#ifndef TOOLS_H_
#define TOOLS_H_

void	my_putstr(char *str);
int	my_puterr(char *str);
int	isnbr(char *str);
int	my_strcmp(char *s1, char *s2);
int	my_strlen(char *str);
char	*my_strdup(char *str);
char	*get_next_line(const int fd);
char	**my_tabdup(char **tab);
char	**my_str_to_wordtab(const char *str);

#endif /* !TOOLS_H_ */
