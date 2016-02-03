/*
** mysh.h for mysh in /home/uberti_l/rendu/Unix/PSU_2015_minishell1/include
**
** Made by louis-emile uberti-ares
** Login   <uberti_l@epitech.net>
**
** Started on  Mon Jan  4 12:52:03 2016 louis-emile uberti-ares
** Last update Sun Jan 24 22:51:33 2016 louis-emile uberti-ares
*/

#ifndef MYSH_H_
# define MYSH_H_
# define READ_SIZE (1000)

typedef struct s_shell
{
  char		**env;
  char		*buffer;
  char		*cd_move;
  char		*old_dir;
  int		status;
  int		env_row;
  int		size_one;
  int		size_two;
}		t_shell;

typedef struct s_check
{
  char		*str;
  int		(*func)(t_shell *shell);
}		t_check;

int		my_putstr(char *str);
int		my_putstr_err(char *str);
int		my_strlen(char *str);
int		my_getnbr(char *str);
int		check_buffer(t_shell *shell, t_check *check);
int		my_strcmp(char *s1, char *s2);
int		unstrict_cmp(char *s1, char *s2);
int		my_cd(t_shell *shell);
int		display_help();
int		copy_env(t_shell *shell, char **env);
int		do_execve(char **env, char **args);
int		free_all_on_exit(t_shell *shell);
int		free_old_env(t_shell *shell);
int		free_tab(char **tab);
int		show_env(t_shell *shell);
int		my_setenv(t_shell *shell);
int		change_env_line(t_shell *shell, char **args, int line);
int		my_unsetenv(t_shell *shell);
void		fork_handler(t_shell *shell, char **args);
void		my_putchar(char c);
void		signal_sigint(int signum);
void		free_them(char **args, char **path);
char		*my_strdup(char *src);
char		*my_strcpy(char *dest, char *src);
char		*toolcpy(char *dest, char *src);
char		*envline_cpy(char *dest, char *env);
char		*get_next_line(const int fd);
char		**my_str_to_wordtab(char *str);
char		**my_path_to_wordtab(char *str);
char		**fill_exec(char **exec, char **path, char *todo, int i);
char		**get_exec(char **path, char *todo);
char		**find_path(char **env);
char		**my_tab_to_tab(char **tab);

#endif /* !MYSH_H_ */
