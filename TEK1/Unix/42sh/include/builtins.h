/*
** builtins.h for 42sh in /home/papadi_a/work/epitech/PSU/PSU_2015_42sh/src
**
** Made by alexis papadimitriou
** Login   <papadi_a@epitech.net>
**
** Started on  Fri May  6 12:16:48 2016 alexis papadimitriou
** Last update Sun Jun  5 16:47:16 2016 come grellard
*/

#ifndef BUILTINS_H_
# define BUILTINS_H_
# define CD_ERR_NO_FILE ": No such file or directory.\n"
# define CD_PERMISSION_DENIED ": Permission denied.\n"
# define CD_TOO_MANY "cd: Too many arguments.\n"
# define EXIT_TOO_MANY_OPEN "Too many ('s.\n"
# define EXIT_TOO_MANY_CLOSE "Too many )'s.\n"
# define EXIT_ERR_EXPRESSION "exit: Expression Syntax.\n"
# define EXIT_ERR_BADLY_FORMED "exit: Badly formed number.\n"

typedef struct s_shell	t_shell;

/*
** FUNCTIONS
*/

int			init_builtins(t_shell *shell);
int			source_bashrc(t_shell *shell, char **args);
int			my_cd(t_shell *shell, char **args);
int			my_echo(t_shell *shell, char **args);
int			my_exit(t_shell *shell, char **args);
char			*get_current_path(void);

#endif /* !BUILTINS_H_ */
