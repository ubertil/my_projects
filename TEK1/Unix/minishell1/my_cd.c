/*
** my_cd.c for my_cd in /home/uberti_l/rendu/Unix/PSU_2015_minishell1
**
** Made by louis-emile uberti-ares
** Login   <uberti_l@epitech.net>
**
** Started on  Mon Jan 18 14:04:55 2016 louis-emile uberti-ares
** Last update Sun Jan 24 22:06:38 2016 louis-emile uberti-ares
*/

#include "include/mysh.h"
#include <stdlib.h>
#include <unistd.h>

void	set_oldpwd_and_pwd(t_shell *shell)
{
  int	i;

  free(shell->buffer);
  if ((shell->buffer = malloc(my_strlen(shell->old_dir) + 20)) == NULL)
    exit(84);
  shell->buffer = my_strcpy(shell->buffer, "setenv ");
  shell->buffer = toolcpy(shell->buffer, "OLDPWD");
  i = my_strlen(shell->buffer);
  shell->buffer[i] = ' ';
  shell->buffer[i + 1] = '\0';
  shell->buffer = toolcpy(shell->buffer, shell->old_dir);
  my_setenv(shell);
  free(shell->buffer);
  if ((shell->buffer = malloc(my_strlen(shell->cd_move) + 20)) == NULL)
    exit(84);
  shell->buffer = my_strcpy(shell->buffer, "setenv ");
  shell->buffer = toolcpy(shell->buffer, "PWD");
  i = my_strlen(shell->buffer);
  shell->buffer[i] = ' ';
  shell->buffer[i + 1] = '\0';
  shell->buffer = toolcpy(shell->buffer, shell->cd_move);
  my_setenv(shell);
}

void	find_oldpwd(t_shell *shell)
{
  int	i;

  i = 0;
  if (shell->env == NULL)
    return;
  while ((unstrict_cmp(shell->env[i], "OLDPWD=") != 0)
	 && (shell->env[i + 1] != NULL))
    i += 1;
  if (unstrict_cmp(shell->env[i], "OLDPWD=") == 0)
    {
      if ((shell->old_dir = malloc(my_strlen(shell->env[i]))) == NULL)
	exit(84);
      shell->old_dir = envline_cpy(shell->old_dir, shell->env[i]);
    }
  else
    return;
}

int	my_cd_go_back(t_shell *shell)
{
  if (shell->old_dir == NULL)
    {
      my_putstr_err(": No such file or directory.\n");
      return (1);
    }
  my_putstr(shell->old_dir);
  my_putchar('\n');
  chdir(shell->old_dir);
  free(shell->old_dir);
  find_oldpwd(shell);
  set_oldpwd_and_pwd(shell);
  free(shell->cd_move);
  return (0);
}

int	move_to_it(t_shell *shell)
{
  if (shell->old_dir == NULL)
    find_oldpwd(shell);
  if (shell->cd_move[0] == '-')
    {
      my_cd_go_back(shell);
      return (0);
    }
  if (chdir(shell->cd_move) == -1)
    {
      my_putstr_err(shell->cd_move);
      my_putstr_err(": No such file or directory.\n");
      return (1);
    }
  free(shell->cd_move);
  if ((shell->cd_move = malloc(100)) == NULL)
    exit(84);
  getcwd(shell->cd_move, 100);
  set_oldpwd_and_pwd(shell);
  free(shell->cd_move);
  find_oldpwd(shell);
  return (0);
}

int	my_cd(t_shell *shell)
{
  char	**args;
  int	i;

  i = 0;
  args = my_str_to_wordtab(shell->buffer);
  if (args[1] != NULL)
    {
      if ((shell->cd_move = malloc(my_strlen(args[1]) + 1)) == NULL)
	exit(84);
      shell->cd_move = my_strcpy(shell->cd_move, args[1]);
      move_to_it(shell);
    }
  else if (shell->env != NULL)
    {
      while (unstrict_cmp(shell->env[i], "HOME=") != 0)
	i += 1;
      if ((shell->cd_move = malloc(my_strlen(shell->env[i]))) == NULL)
	exit(84);
      shell->cd_move = envline_cpy(shell->cd_move, shell->env[i]);
      move_to_it(shell);
    }
  free_tab(args);
  return (0);
}
