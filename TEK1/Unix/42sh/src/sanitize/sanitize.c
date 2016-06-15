/*
** sanitize.c for sanitize.c in /home/trognot/rendu/PSU/PSU_2015_42sh/src/sanitize
**
** Made by nicolas trognot
** Login   <nicolas.trognot@epitech.eu>
**
** Started on  Tue May 10 18:31:58 2016 nicolas trognot
** Last update Mon May 30 17:10:29 2016 louis-emile uberti-ares
*/

#include <string.h>
#include <stdlib.h>
#include "shell.h"
#include "tools.h"

char		*add_space(char *str, int idx)
{
  char		*str_in;
  int		i;
  int		j;

  if ((str_in = malloc(sizeof(char) * (strlen(str) + 2))) == NULL)
    return (NULL);
  i = 0;
  j = 0;
  while (i < (int)strlen(str))
    {
      if (j == idx)
	str_in[j] = ' ';
      else
	{
	  str_in[j] = str[i];
	  i++;
	}
      j++;
    }
  str_in[j] = '\0';
  free(str);
  return (str_in);
}

char		*rebuild_str(char **ret)
{
  int		i;
  char		*str;
  int		len;

  i = -1;
  len = 0;
  while (ret[++i] != NULL)
    len += strlen(ret[i]) + 2;
  if ((str = malloc(len + 1)) == NULL)
    return (NULL);
  str[0] = '\0';
  i = 0;
  while (ret[i] != NULL)
    {
      str = strcat(str, ret[i]);
      str = strcat(str, " ");
      i++;
    }
  return (str);
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

char		*sanitize_tag(t_shell *shell, char *str,
			      int i, char **ret)
{
  char		*tmp0;
  char		*tmp1;
  char		*tmp2;

  while (ret && ret[++i] != NULL)
    if ((strcmp(ret[i], ">") == 0 || strcmp(ret[i], "<") == 0) &&
	(i == 0 || is_token(shell->tokens, ret[i - 1]) >= 0) &&
	(ret[i + 1] != NULL && ret[i + 2] != NULL &&
	 is_token(shell->tokens, ret[i + 1]) == -1 &&
	 is_token(shell->tokens, ret[i + 2]) == -1))
      {
	if ((tmp0 = strdup(ret[i + 2])) == NULL || (tmp1 = strdup(ret[i]))
	    == NULL || (tmp2 = strdup(ret[i + 1])) == NULL ||
	    (ret[i] = strdup(tmp0)) == NULL || (ret[i + 1] = strdup(tmp1))
	    == NULL || (ret[i + 2] = strdup(tmp2)) == NULL)
	  return (NULL);
	free(tmp0);
	free(tmp1);
	free(tmp2);
      }
  free(str);
  str = rebuild_str(ret);
  if (ret != NULL)
    free_args(ret);
  return (str);
}

char		*sanitize_command(char *str, t_shell *shell)
{
  int		i;
  int		idx;
  char		**ret;

  idx = -1;
  while (++idx < (int)strlen(str))
    {
      i = 6;
      while (i >= 0)
	{
	  if (strncmp(str + idx, shell->tokens[i],
		      strlen(shell->tokens[i])) == 0)
	    {
	      if ((str = add_space(str, idx)) == NULL)
		return (NULL);
	      idx += strlen(shell->tokens[i]) + 1;
	      if ((str = add_space(str, idx)) == NULL)
		return (NULL);
	    }
	  i--;
	}
    }
  if ((ret = my_str_to_wordtab(str, " \t")) == NULL)
    return (str);
  return (str = sanitize_tag(shell, str, -1, ret));
}
