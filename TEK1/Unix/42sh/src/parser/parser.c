/*
** parser.c for parser in /home/uberti_l/rendu/Unix/PSU_2015_42sh
**
** Made by louis-emile uberti-ares
** Login   <uberti_l@epitech.net>
**
** Started on  Tue May 10 14:44:28 2016 louis-emile uberti-ares
** Last update Sun Jun  5 23:38:08 2016 alexis papadimitriou
*/

#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>
#include <stdio.h>
#include "shell.h"
#include "tools.h"
#include "tokens.h"

static void	free_fd_tab(t_shell *shell)
{
  int		idx;

  idx = -1;
  while (shell->fd_tab[++idx] != NULL)
    {
      if (shell->fd_tab[idx][0] != -2)
	close(shell->fd_tab[idx][0]);
      if (shell->fd_tab[idx][1] != -2)
	close(shell->fd_tab[idx][1]);
      free(shell->fd_tab[idx]);
    }
  free(shell->fd_tab);
  shell->fd_tab = NULL;
}

static int	waiting_all_children(t_shell *shell)
{
  int		idx;

  idx = -1;
  free_fd_tab(shell);
  while (++idx < shell->nb_children)
    {
      wait(&shell->status);
      WIFSIGNALED(shell->status);
      if (WTERMSIG(shell->status) == SIGSEGV)
	fprintf(stderr, "%s", SEGFAULT);
      else if (WTERMSIG(shell->status) == SIGFPE)
	fprintf(stderr, "%s", FLOAT);
    }
  shell->nb_children = 0;
  return (0);
}

static int	open_and_exec(t_shell *shell, t_tree *tree)
{
  t_tree	*current;
  int		idx;
  int		fd_idx;

  current = tree;
  fd_idx = 0;
  while (current->up != NULL)
    {
      idx = 0;
      while (idx != current->up->token)
	idx += 1;
      if (shell->tk_parsing[idx].f(shell, current, fd_idx++) == -1)
	return (-1);
      current = current->up;
    }
  if (do_execve(shell, current->left) == -1)
    return (-1);
  waiting_all_children(shell);
  if (dup2(shell->base_in_out[0], 0) == -1 ||
      dup2(shell->base_in_out[1], 1) == -1)
    return (-1);
  return (0);
}

static int	set_fd_tab(t_shell *shell, t_tree *current, int nb_token)
{
  int		idx;

  if ((shell->fd_tab = malloc(sizeof(int *) * (nb_token + 1))) == NULL)
    return (-1);
  shell->fd_tab[nb_token] = NULL;
  idx = -1;
  while (++idx < nb_token)
    {
      if ((shell->fd_tab[idx] = malloc(sizeof(int) * 2)) == NULL)
	return (-1);
      shell->fd_tab[idx][0] = -2;
      shell->fd_tab[idx][1] = -2;
    }
  if (open_and_exec(shell, current) == -1)
    return (-1);
  return (0);
}

int		start_parser(t_shell *shell)
{
  t_tree	*current_token;
  int		nb_token;

  if (shell->do_nothing == 1)
    {
      shell->do_nothing = 0;
      return (0);
    }
  nb_token = 0;
  current_token = shell->tree;
  while (current_token->token != TK_END)
    {
      if (current_token->token < TK_AND)
	nb_token += 1;
      current_token = current_token->right;
    }
  return (set_fd_tab(shell, current_token, nb_token));
}
