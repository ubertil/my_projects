/*
** free_all.c for free_all in /home/uberti_l/rendu/Unix/PSU_2015_42sh
**
** Made by louis-emile uberti-ares
** Login   <uberti_l@epitech.net>
**
** Started on  Wed May 11 12:00:57 2016 louis-emile uberti-ares
** Last update Sun Jun  5 15:57:58 2016 louis-emile uberti-ares
*/

#include <stdlib.h>
#include "shell.h"
#include "env.h"
#include "alias.h"

int		free_alias(t_alias *alias)
{
  t_alias	*curr;

  while ((curr = alias) != NULL)
    {
      alias = alias->next;
      free(curr->command);
      free(curr->replace);
      free(curr);
    }
  return (0);
}

int		free_tree(t_tree *tree)
{
  t_tree	*curr;
  int		i;

  while ((curr = tree) != NULL)
    {
      tree = tree->right;
      i = -1;
      while (curr->left != NULL && curr->left[++i] != NULL)
	free(curr->left[i]);
      free(curr->left);
      free(curr);
    }
  free(tree);
  tree = NULL;
  return (0);
}

int		free_args(char **tab)
{
  int		i;

  i = 0;
  while (tab != NULL && tab[i] != NULL)
    free(tab[i++]);
  free(tab);
  return (0);
}

void		free_all(t_shell *shell)
{
  free_env(shell->env);
  free(shell->tokens);
  free(shell->builtins);
  if (shell->alias != NULL)
    free_alias(shell->alias);
  if (shell->command_name != NULL)
    free(shell->command_name);
  free(shell->hist_name);
  free(shell);
}
