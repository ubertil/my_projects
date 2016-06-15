/*
** source_bashrc.c for source_bashrc in /home/uberti_l/rendu/Unix/PSU_2015_42sh
**
** Made by louis-emile uberti-ares
** Login   <uberti_l@epitech.net>
**
** Started on  Mon May 30 15:07:02 2016 louis-emile uberti-ares
** Last update Sun Jun  5 16:10:42 2016 louis-emile uberti-ares
*/

#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include <string.h>
#include <stdlib.h>
#include "alias.h"
#include "tools.h"
#include "shell.h"

static char	*get_alias_name(const char *str, const int idx)
{
  char		*command;
  char		**args;

  command = NULL;
  if (((args = my_str_to_wordtab(str, " ='")) == NULL) ||
      (args[1] == NULL))
    {
      fprintf(stderr, "%s%d\n", ERR_ALIAS, idx);
      return (NULL);
    }
  if ((strcmp(args[0], "alias") != 0) ||
      ((command = strdup(args[1])) == NULL))
    {
      free_args(args);
      return (NULL);
    }
  free_args(args);
  return (command);
}

static char	*get_replace_alias(const char *str, const int idx)
{
  int		i;
  int		save;
  char		*replace;

  i = 0;
  while (str[i] != '\0' && str[i] != '=')
    ++i;
  save = i + 1;
  if (str[i] != '=')
    {
      fprintf(stderr, "%s%d\n", ERR_ALIAS, idx);
      return (NULL);
    }
  if ((replace = malloc(strlen(str) - save + 1)) == NULL)
    return (NULL);
  i = 0;
  if (str[save] == '\'')
    ++save;
  while (str[save] != '\'' && str[save] != '\0')
    replace[i++] = str[save++];
  replace[i] = '\0';
  return (replace);
}

static t_alias	*add_alias(const char *str, const int idx, t_alias **old)
{
  t_alias	*new;

  if (((new = malloc(sizeof(t_alias))) == NULL) ||
      ((new->command = get_alias_name(str, idx)) == NULL) ||
      ((new->replace = get_replace_alias(str, idx)) == NULL))
    return (NULL);
  new->next = *old;
  return (new);
}

int		source_bashrc(t_shell *shell, char **args)
{
  int		fd;
  int		idx;
  char		*str;

  free_alias(shell->alias);
  shell->alias = NULL;
  if ((args[1] == NULL) || (fd = open(args[1], O_APPEND | O_RDONLY)) == -1)
    {
      fprintf(stderr, "%s%s", NO_FILE, USAGE);
      return (0);
    }
  idx = 0;
  while ((str = get_shell_line(fd)) != NULL)
    {
      ++idx;
      if ((shell->alias = add_alias(str, idx, &shell->alias)) == NULL)
	{
	  close(fd);
	  return (0);
	}
      free(str);
    }
  close(fd);
  return (0);
}
