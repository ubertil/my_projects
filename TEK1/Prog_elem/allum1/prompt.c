/*
** prompt.c for prompt in /home/uberti_l/rendu/Prog_elem/CPE_2015_Allum1
**
** Made by louis-emile uberti-ares
** Login   <uberti_l@epitech.net>
**
** Started on  Mon Feb  8 11:31:11 2016 louis-emile uberti-ares
** Last update Sun Feb 21 21:54:27 2016 louis-emile uberti-ares
*/

#include <stdlib.h>
#include "include/allum.h"

void		remove_matches(t_allum *allum)
{
  int		i;
  int		idx;
  int		to_remove;

  idx = 0;
  i = my_getnbr(allum->line);
  to_remove = my_getnbr(allum->matches);
  allum->lines[i] -= to_remove;
  while (allum->board[i][idx] != '\0')
    {
      if ((allum->board[i][idx] == '2') && (to_remove > 0))
	{
	  allum->board[i][idx] = '0';
	  to_remove -= 1;
	}
      idx += 1;
    }
  if (allum->lines[i] == 0)
    allum->nb_lines -= 1;
  free(allum->matches);
  free(allum->line);
}

void		disp_board(t_allum *allum)
{
  int		i;
  int		idx;

  i = 0;
  idx = 0;
  while (i != 6)
    {
      while (allum->board[i][idx] != '\0')
	{
	  if (allum->board[i][idx] == '1')
	    my_putchar('*');
	  else if (allum->board[i][idx] == '2')
	    my_putchar('|');
	  else
	    my_putchar(' ');
	  idx += 1;
	}
      idx = 0;
      i += 1;
      my_putchar('\n');
    }
}

void		prompt_player(t_allum *allum)
{
  my_putstr("Player removed ");
  my_putstr(allum->matches);
  my_putstr(" match(es) from line ");
  my_putstr(allum->line);
  my_putchar('\n');
  remove_matches(allum);
  disp_board(allum);
  allum->ia_win = 1;
}

void		first_prompt(void)
{
  my_putstr("*********\n");
  my_putstr("*   |   *\n");
  my_putstr("*  |||  *\n");
  my_putstr("* ||||| *\n");
  my_putstr("*|||||||*\n");
  my_putstr("*********\n\n");
}
