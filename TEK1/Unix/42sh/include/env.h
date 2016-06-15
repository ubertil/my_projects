/*
** env.h for env in /home/uberti_l/rendu/Unix/PSU_2015_42sh
**
** Made by louis-emile uberti-ares
** Login   <uberti_l@epitech.net>
**
** Started on  Fri May  6 12:35:06 2016 louis-emile uberti-ares
** Last update Sun Jun  5 16:46:33 2016 come grellard
*/

#ifndef ENV_H_
# define ENV_H_
# define ERR_CREAT "Error: env: Creation impossible. Aborting.\n"
# define UNSETENV_ARGS "unsetenv: Too few arguments.\n"
# define SETENV_TOO_MANY_ARGS "setenv: Too many arguments.\n"
# define SETENV_ERR_LETTER "setenv: Variable name must begin with a letter.\n"
# define NO_REF ": Undefined variable.\n"
# define ILLEGAL "Illegal variable name.\n"

/*
** STRUCTURES
*/

typedef struct s_shell	t_shell;

typedef struct		s_env
{
  char			*line;
  struct s_env		*next;
}			t_env;

/*
** FUNCTIONS
*/

int			free_env(t_env *env);
int			copy_env(t_shell *sh, char **env);
char			*my_getenv(t_shell *shell, char *name);
int			update_env(t_shell *sh, char *str);
int			my_setenv(t_shell *shell, char **args);
int			my_env(t_shell *shell, char **args);
int			my_unsetenv(t_shell *shell, char **args);
char			**get_env_variable(t_shell *shell, char **args);
t_env			*add_env_line(const char *str, t_env **old);
t_env			*reverse_env(t_env *root);

#endif /* !ENV_H_ */
