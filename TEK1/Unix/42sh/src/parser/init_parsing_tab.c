/*
** init_parsing_tab.c for init_parsing_tab in /home/uberti_l/rendu/Unix/PSU_2015_42sh
**
** Made by louis-emile uberti-ares
** Login   <uberti_l@epitech.net>
**
** Started on  Tue May 10 16:16:36 2016 louis-emile uberti-ares
** Last update Wed Jun  1 17:27:26 2016 alexis papadimitriou
*/

#include <stdlib.h>
#include "parser.h"
#include "tokens.h"

void		init_parsing_tab(t_parsing *tab)
{
  tab[0].token = TK_PIPE;
  tab[1].token = TK_R_REDIRECT;
  tab[2].token = TK_RR_REDIRECT;
  tab[3].token = TK_L_REDIRECT;
  tab[4].token = TK_LL_REDIRECT;
  tab[5].token = TK_AND;
  tab[6].token = TK_OR;
  tab[7].token = TK_END;
  tab[0].f = &open_pipe;
  tab[1].f = &open_r_redir;
  tab[2].f = &open_rr_redir;
  tab[3].f = &open_l_redir;
  tab[4].f = &open_ll_redir;
  tab[5].f = &token_and;
  tab[6].f = &token_or;
  tab[7].f = &token_end;
}
