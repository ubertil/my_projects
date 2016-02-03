/*
** my_unsetenv.c for my_unsetenv in /home/uberti_l/rendu/Unix/PSU_2015_minishell1
**
** Made by louis-emile uberti-ares
** Login   <uberti_l@epitech.net>
**
** Started on  Wed Jan  6 20:35:30 2016 louis-emile uberti-ares
** Last update Sun Jan 24 22:50:03 2016 louis-emile uberti-ares
*/

#include "include/mysh.h"
#include <stdlib.h>

int		special_env_cpy(t_shell *shell, char **env, int skip)
{
  int		i;
  int		j;

  i = 0;
  j = 0;
  if ((shell->env = malloc(sizeof(char *) * (shell->env_row + 1))) == NULL)
    exit(84);
  while (env[i] != NULL)
    {
      if (i == skip)
	i += 1;
      if (env[i] != NULL)
	{
	  if ((shell->env[j] = malloc(my_strlen(env[i]) + 1)) == NULL)
	    exit(84);
	  shell->env[j] = my_strcpy(shell->env[j], env[i]);
	  i += 1;
	  j += 1;
	}
    }
  shell->env[j] = NULL;
  return (0);
}

int		unsetenv_line(t_shell *shell, char *to_find)
{
  int		i;
  char		**new_env;

  i = 0;
  while ((unstrict_cmp(shell->env[i], to_find) != 0)
	 && (shell->env[i + 1] != NULL))
    i += 1;
  if (unstrict_cmp(shell->env[i], to_find) == 0)
    {
      shell->env_row -= 1;
      new_env = my_tab_to_tab(shell->env);
      free_old_env(shell);
      special_env_cpy(shell, new_env, i);
      free_tab(new_env);
    }
  return (0);
}

int		my_unsetenv(t_shell *shell)
{
  char		**args;

  args = my_str_to_wordtab(shell->buffer);
  if ((args[1] == NULL) || (shell->env == NULL))
    return (0);
  else
    unsetenv_line(shell, args[1]);
  return (0);
}
