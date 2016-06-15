/*
** init_tree.c for init binary tree in /home/grella_c/rendu/PSU_2015_42sh/src/lexer
**
** Made by come grellard
** Login   <grella_c@epitech.net>
**
** Started on  Tue May 10 14:46:33 2016 come grellard
** Last update Sun Jun  5 15:10:10 2016 louis-emile uberti-ares
*/

#include <string.h>
#include <stdlib.h>
#include "shell.h"
#include "tools.h"

static int	nothing_more(t_shell *shell)
{
  shell->tree->left = NULL;
  shell->tree->right = NULL;
  shell->do_nothing = 1;
  return (0);
}

static char	**get_left(char **commands, int token_idx)
{
  char		**left;
  int		i;

  i = -1;
  if ((left = malloc(sizeof(char *) * (token_idx + 1))) == NULL)
    return (NULL);
  while (++i < token_idx)
    if ((left[i] = strdup(commands[i])) == NULL)
      return (NULL);
  left[i] = NULL;
  return (left);
}

static int	last_command(t_shell *shell, char **commands, const int i)
{
  shell->tree->token = 7;
  shell->tree->left = get_left(commands, i);
  shell->tree->right = NULL;
  while (shell->tree->up != NULL)
    shell->tree = shell->tree->up;
  free_args(commands);
  return (0);
}

static int	is_token(char **tokens, char *str)
{
  int		i;

  i = -1;
  if (str == NULL)
    return (-1);
  while (tokens[++i] != NULL)
    if (strcmp(tokens[i], str) == 0)
      return (i);
  return (-1);
}

int		fill_tree(t_shell *shell, char *command_line)
{
  t_tree	*up;
  char		**commands;
  int		i;

  if ((commands = my_str_to_wordtab(command_line, " \t")) == NULL)
    return (nothing_more(shell));
  i = -1;
  while (commands != NULL && commands[++i] != NULL)
    {
      if ((is_token(shell->tokens, commands[i]) >= 0) &&
	  ((shell->tree->right = malloc(sizeof(t_tree))) != NULL))
	{
	  shell->tree->token = is_token(shell->tokens, commands[i]);
	  if ((shell->tree->left = get_left(commands, i)) == NULL)
	    return (-1);
	  up = shell->tree;
	  shell->tree = shell->tree->right;
	  shell->tree->up = up;
	  return (fill_tree(shell, new_command(commands, i)));
	}
    }
  return (last_command(shell, commands, i));
}
