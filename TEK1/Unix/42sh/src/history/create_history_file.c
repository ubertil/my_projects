/*
** create_history_file.c for create_history_file.c in /home/rahil_f/rendu/PSU_2015_42sh/felix
**
** Made by felix rahil
** Login   <rahil_f@epitech.net>
**
** Started on  Mon May 30 14:58:20 2016 felix rahil
** Last update Sun Jun  5 16:19:20 2016 louis-emile uberti-ares
*/

#include <string.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>
#include "tools.h"
#include "shell.h"
#include "builtins.h"
#include "history.h"

int		find_hist_place(t_shell *shell)
{
  char		*pwd;

  shell->hist_name = NULL;
  if (((pwd = get_current_path()) == NULL) ||
      ((shell->hist_name =
	malloc(strlen(pwd) + strlen(HIST_FILE) + 2)) == NULL))
    return (-1);
  memset(shell->hist_name, '\0', strlen(pwd) + strlen(HIST_FILE));
  if (((shell->hist_name = strcat(shell->hist_name, pwd)) == NULL) ||
      ((shell->hist_name = strcat(shell->hist_name, "/")) == NULL) ||
      ((shell->hist_name = strcat(shell->hist_name, HIST_FILE)) == NULL))
    {
      free(pwd);
      return (-1);
    }
  free(pwd);
  return (0);
}

static int	find_nb_history(t_shell *shell)
{
  int		fd;
  char		*str;

  shell->nb_line = 0;
  if ((fd = open(shell->hist_name, O_RDONLY)) == -1)
    return (0);
  str = NULL;
  while ((str = get_shell_line(fd)) != NULL)
    {
      shell->nb_line += 1;
      free(str);
    }
  close(fd);
  return (0);
}

int	add_line_to_history(t_shell *shell, const char *buffer)
{
  int	fd;

  if (shell->nb_line == -1 && find_nb_history(shell) == -1)
    return (-1);
  if (is_space(buffer) == 1)
    return (0);
  if ((fd = open(shell->hist_name, O_CREAT | O_APPEND | O_WRONLY, 444)) == -1)
    return (-1);
  shell->nb_line += 1;
  my_put_nbr(shell->nb_line, fd);
  write(fd, "\t", 1);
  write(fd, buffer, strlen(buffer));
  write(fd, "\n", 1);
  close(fd);
  return (0);
}
