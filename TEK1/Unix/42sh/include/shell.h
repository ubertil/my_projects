/*
** shell.h for shell in /home/uberti_l/rendu/Unix/PSU_2015_42sh
**
** Made by louis-emile uberti-ares
** Login   <uberti_l@epitech.net>
**
** Started on  Thu May  5 14:46:59 2016 louis-emile uberti-ares
** Last update Sun Jun  5 16:02:28 2016 louis-emile uberti-ares
*/

#ifndef SHELL_H_
# define SHELL_H_
# define SEGFAULT "Segmentation Fault\n"
# define FLOAT "Floating point exception\n"
# define FORK_FAIL "Error: Fork Failed. Aborting.\n"
# define NULL_CMD "Invalid null command.\n"
# define OUTPUT_ERR "Ambigious output redirect.\n"
# define INPUT_ERR "Ambigious input redirect.\n"
# define MISSING_NAME "Missing name for redirect.\n"
# define NO_FILE_DIR "No such file or directory.\n"
# define BAD_TOKEN "Error: Bad token.\n"
# define EXEC_FAILED "Error: Failed to execute command\n"
# define DUP_FAIL "Error: Failed the dup function failed.\n"
# include "parser.h"
# include "tokens.h"

/*
** STRUCTURES
*/

typedef struct			s_builtins
{
  char				*cmd;
  int				(*builtin)(t_shell *, char **);
}				t_builtins;

typedef struct	s_env		t_env;
typedef struct	s_alias		t_alias;
typedef struct	s_parsing	t_parsing;

typedef struct			s_shell
{
  int				i;
  int				exit;
  int				status;
  int				nb_line;
  int				erased;
  int				do_nothing;
  int				nb_children;
  int				base_in_out[2];
  int				**fd_tab;
  char				should_i_exit;
  char				*command_name;
  char				*hist_name;
  char				*alias_name;
  char				**tokens;
  t_env				*env;
  t_alias			*alias;
  t_builtins			*builtins;
  t_parsing			tk_parsing[NB_TOKEN - 1];
  t_tree			*tree;
}				t_shell;

/*
** FUNCTIONS
*/

void			free_all(t_shell *);
int			free_tree(t_tree *);
int			free_args(char **);
int			error_check(t_shell *, const char *);
int			aff_prompt(void);
int			init_signals(void);
int			do_execve(t_shell *, char **);
int			fill_tree(t_shell *, char *);
int			check_null_command(t_shell *, char **);
int			check_other_ambigious(t_shell *, char **);
char			*sanitize_command(char *, t_shell *);
char			**append_path(char **, char **);
char			**get_tab_env(t_env *);

#endif /* !SHELL_H_ */
