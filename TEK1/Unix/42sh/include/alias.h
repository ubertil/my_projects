/*
** alias.h for alias in /home/uberti_l/rendu/Unix/PSU_2015_42sh
**
** Made by louis-emile uberti-ares
** Login   <uberti_l@epitech.net>
**
** Started on  Mon May 23 16:45:05 2016 louis-emile uberti-ares
** Last update Sun Jun  5 16:46:51 2016 come grellard
*/

#ifndef ALIAS_H_
# define ALIAS_H_
# define NO_FILE "source: filename argument required.\n"
# define USAGE "source: usage: source filename.\n"
# define ALIAS_USAGE "Usage: alias [alias-name[=string]...]\n"
# define ERR_ALIAS "alias: command not found. Check your syntax line "

typedef struct s_shell	t_shell;

typedef struct		s_alias
{
  char			*command;
  char			*replace;
  struct s_alias	*next;
}			t_alias;

int			free_alias(t_alias *alias);
int			alias_input(t_shell *shell, char **args);
char			**alias_to_command(t_shell *shell, char **args);

#endif /* !ALIAS_H_ */
