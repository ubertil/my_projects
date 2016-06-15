/*
** tokens.c for tokens.c in /home/trognot/rendu/PSU/PSU_2015_42sh/src
**
** Made by nicolas trognot
** Login   <nicolas.trognot@epitech.eu>
**
** Started on  Tue May 10 17:21:05 2016 nicolas trognot
** Last update Sun Jun  5 16:22:33 2016 louis-emile uberti-ares
*/

#include <stdlib.h>
#include "shell.h"
#include "tokens.h"

int	init_tokens(t_shell *sh)
{
  if ((sh->tokens = malloc(sizeof(char *) * NB_TOKEN)) == NULL)
    return (1);
  sh->tokens[TK_PIPE] = "|";
  sh->tokens[TK_R_REDIRECT] = ">";
  sh->tokens[TK_RR_REDIRECT] = ">>";
  sh->tokens[TK_L_REDIRECT] = "<";
  sh->tokens[TK_LL_REDIRECT] = "<<";
  sh->tokens[TK_AND] = "&&";
  sh->tokens[TK_OR] = "||";
  sh->tokens[TK_END] = "\0";
  sh->tokens[8] = NULL;
  return (0);
}
