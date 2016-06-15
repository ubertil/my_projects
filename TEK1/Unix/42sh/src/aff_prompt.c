/*
** aff_prompt.c for aff_prompt in /home/grella_c/rendu/PSU_2015_minishell1
**
** Made by come grellard
** Login   <grella_c@epitech.net>
**
** Started on  Fri Jan 22 18:01:46 2016 come grellard
** Last update Sun Jun  5 15:52:57 2016 louis-emile uberti-ares
*/

#include <string.h>
#include <unistd.h>
#include <stdlib.h>
#include "tools.h"

static char	*cut_prompt(char *prompt)
{
  char		*short_prompt;
  int		i;
  int		j;
  int		count_slash;
  int		len_short_prompt;

  i = strlen(prompt);
  j = 0;
  len_short_prompt = 0;
  count_slash = 0;
  while (count_slash < 2 && i >= 0)
    {
      if (prompt[i--] == '/')
	count_slash += 1;
      len_short_prompt += 1;
    }
  i += 2;
  if ((short_prompt = malloc(len_short_prompt - 1)) == NULL)
    return (NULL);
  while (prompt[i] != '\0')
    short_prompt[j++] = prompt[i++];
  short_prompt[j] = '\0';
  free(prompt);
  return (short_prompt);
}

int		aff_prompt(void)
{
  char		*prompt;
  int		i;

  i = 1;
  if ((prompt = malloc(i)) == NULL)
    return (-1);
  while (getcwd(prompt, i++) == NULL)
    {
      free(prompt);
      if ((prompt = malloc(i)) == NULL)
	return (-1);
    }
  if ((prompt = cut_prompt(prompt)) == NULL)
    return (-1);
  my_putstr(prompt);
  my_putstr("> ");
  free(prompt);
  return (0);
}
