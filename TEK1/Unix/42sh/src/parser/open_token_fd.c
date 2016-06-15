/*
1;4205;0c** open_token_fd.c for open_token_fd in /home/uberti_l/rendu/Unix/PSU_2015_42sh
OB**
** Made by louis-emile uberti-ares
** Login   <uberti_l@epitech.net>
**
** Started on  Tue May 10 16:43:08 2016 louis-emile uberti-ares
** Last update Sun Jun  5 23:37:40 2016 alexis papadimitriou
*/

#include <unistd.h>
#include <stdlib.h>
#include <fcntl.h>
#include <stdio.h>
#include "parser.h"
#include "shell.h"

int		open_pipe(t_shell *shell, t_tree *current, int fd_idx)
{
  if (pipe(shell->fd_tab[fd_idx]) == -1 ||
      dup2(shell->fd_tab[fd_idx][0], 0) == -1)
    return (-1);
  if (do_execve(shell, current->left) == -1)
    {
      dprintf(2, "%s", EXEC_FAILED);
      return (-1);
    }
  if (dup2(shell->fd_tab[fd_idx][1], 1) == -1)
    return (-1);
  return (0);
}

int		open_r_redir(t_shell *shell, t_tree *current, int fd_idx)
{
  if ((shell->fd_tab[fd_idx][1] =
       open(current->left[0], O_CREAT | O_RDWR | O_TRUNC, 420)) == -1 ||
      dup2(shell->fd_tab[fd_idx][1], 1) == -1)
    return (-1);
  return (0);
}

int		open_rr_redir(t_shell *shell, t_tree *current, int fd_idx)
{
  if ((shell->fd_tab[fd_idx][1] =
       open(current->left[0], O_CREAT | O_RDWR | O_APPEND, 420)) == -1 ||
      dup2(shell->fd_tab[fd_idx][1], 1))
    return (-1);
  return (0);
}

int		open_l_redir(t_shell *shell, t_tree *current, int fd_idx)
{
  if ((shell->fd_tab[fd_idx][0] = open(current->left[0], O_RDONLY)) == -1)
    {
      dprintf(2, "%s: %s", current->left[0], NO_FILE_DIR);
      return (-1);
    }
  if (dup2(shell->fd_tab[fd_idx][0], 0) == -1)
    return (-1);
  return (0);
}

int		open_ll_redir(t_shell *shell, t_tree *current, int fd_idx)
{
  if ((shell->fd_tab[fd_idx][0] = open(current->left[0], O_RDONLY)) == -1)
    {
      dprintf(2, "%s: %s", current->left[0], NO_FILE_DIR);
      return (-1);
    }
  if (dup2(shell->fd_tab[fd_idx][0], 0) == -1)
    return (-1);
  return (0);
}
