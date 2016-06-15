/*
** parser.h for parser in /home/uberti_l/rendu/Unix/PSU_2015_42sh
**
** Made by louis-emile uberti-ares
** Login   <uberti_l@epitech.net>
**
** Started on  Tue May 10 11:45:19 2016 louis-emile uberti-ares
** Last update Sun Jun  5 23:42:05 2016 alexis papadimitriou
*/

#ifndef PARSER_H_
# define PARSER_H_

/*
** STRUCTURES
*/

typedef struct s_shell	t_shell;

typedef struct		s_tree
{
  int			token;
  char			**left;
  struct s_tree		*up;
  struct s_tree		*right;
}			t_tree;

typedef struct		s_parsing
{
  int			token;
  int			(*f)(t_shell *, t_tree *, int);
}			t_parsing;

/*
** FUNCTIONS
*/

void		init_parsing_tab(t_parsing *);
int		start_parser(t_shell *shell);
int		parsing_and_exec(t_shell *, t_tree *);
int		open_pipe(t_shell *, t_tree *, int);
int		open_r_redir(t_shell *, t_tree *, int);
int		open_rr_redir(t_shell *, t_tree *, int);
int		open_l_redir(t_shell *, t_tree *, int);
int		open_ll_redir(t_shell *, t_tree *, int);
int		token_and(t_shell *, t_tree *, int);
int		token_or(t_shell *, t_tree *, int);
int		token_end(t_shell *, t_tree *, int);
char		**find_globings(char **);
char		*new_command(char **, int);
char		**glob_wildcard(char **, int);

#endif /* !PARSER_H_ */
