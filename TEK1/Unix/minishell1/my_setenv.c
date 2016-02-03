/*
** my_setenv.c for my_setenv in /home/uberti_l/rendu/Unix/PSU_2015_minishell1
**
** Made by louis-emile uberti-ares
** Login   <uberti_l@epitech.net>
**
** Started on  Wed Jan  6 20:34:26 2016 louis-emile uberti-ares
** Last update Sun Jan 24 22:41:19 2016 louis-emile uberti-ares
*/

#include "include/mysh.h"
#include <stdlib.h>

char		**malloc_new_env(t_shell *shell, char **env)
{
  int		i;
  char		**new_env;

  i = 0;
  while (env[i] != NULL)
    i += 1;
  if ((new_env = malloc(sizeof(char *) * (i + 2))) == NULL)
    exit(84);
  i = 0;
  while (env[i] != NULL)
    {
      if ((new_env[i] = malloc(my_strlen(env[i]) + 1)) == NULL)
	exit (84);
      new_env[i] = my_strcpy(new_env[i], env[i]);
      i += 1;
    }
  if ((new_env[i] = malloc(shell->size_one + shell->size_two)) == NULL)
    exit(84);
  new_env[i + 1] = NULL;
  return (new_env);
}

char		*fill_new_line(t_shell *shell, char **args)
{
  int		i;
  char		*tmp;

  if ((tmp = malloc(shell->size_one + shell->size_two)) == NULL)
    exit(84);
  tmp[0] = '\0';
  shell->env_row += 1;
  tmp = toolcpy(tmp, args[1]);
  i = my_strlen(tmp);
  tmp[i] = '=';
  tmp[i + 1] = '\0';
  if (args[2] == NULL)
    return (tmp);
  tmp = toolcpy(tmp, args[2]);
  return (tmp);
}

char		**create_env(t_shell *shell)
{
  char		**env;

  if ((env = malloc(sizeof(char *) * 3)) == NULL)
    exit(84);
  if ((env[0] = malloc(shell->size_two + shell->size_one)) == NULL)
    exit(84);
  env[1] = NULL;
  return (env);
}

int		add_line(t_shell *shell, char **args)
{
  char		**new_env;
  char		*new_line;
  int		i;

  i = 0;
  shell->size_one = my_strlen(args[1]);
  if (args[2] == NULL)
    shell->size_two = 3;
  else
    shell->size_two = my_strlen(args[2]) + 2;
  if (shell->env != NULL)
    new_env = malloc_new_env(shell, shell->env);
  else
    new_env = create_env(shell);
  new_line = fill_new_line(shell, args);
  while (new_env[i + 1] != NULL)
    i += 1;
  new_env[i] = my_strcpy(new_env[i], new_line);
  if (shell->env != NULL)
    free_old_env(shell);
  copy_env(shell, new_env);
  free(new_line);
  free_tab(new_env);
  return (0);
}

int		my_setenv(t_shell *shell)
{
  int		i;
  char		**args;

  i = 0;
  args = my_str_to_wordtab(shell->buffer);
  if (args[1] == NULL)
    {
      show_env(shell);
      free_tab(args);
      return (0);
    }
  if (shell->env != NULL)
    while ((unstrict_cmp(shell->env[i], args[1]) != 0)
	   && (shell->env[i + 1] != NULL))
      i += 1;
  if ((unstrict_cmp(shell->env[i], args[1])) == 0)
    change_env_line(shell, args, i);
  else
    add_line(shell, args);
  free_tab(args);
  return (0);
}
