/*
** ia_play.c for ia_play in /home/uberti_l/rendu/Prog_elem/CPE_2015_Allum1
**
** Made by louis-emile uberti-ares
** Login   <uberti_l@epitech.net>
**
** Started on  Mon Feb  8 12:28:31 2016 louis-emile uberti-ares
** Last update Fri Feb 19 12:26:32 2016 louis-emile uberti-ares
*/

#include <stdlib.h>
#include "include/allum.h"

void		remove_ia_matches(t_allum *allum, int i, int to_remove)
{
  int		idx;

  idx = 0;
  if ((allum->lines[i] -= to_remove) == 0)
    allum->nb_lines -= 1;
  while (allum->board[i][idx] != '\0')
    {
      if ((allum->board[i][idx] == '2') && (to_remove > 0))
	{
	  allum->board[i][idx] = '0';
	  to_remove -= 1;
	}
      idx += 1;
    }
}

int		ia_play(t_allum *allum)
{
  int		row;
  int		matches;

  row = 0;
  matches = 0;
  while (allum->lines[row] == 0)
    row = rand() % 5;
  while ((matches == 0) || (matches > allum->lines[row]))
    matches = rand() % 7;
  my_putstr("AI removed ");
  my_putchar(matches + 48);
  my_putstr(" match(es) from line ");
  my_putchar(row + 48);
  my_putchar('\n');
  remove_ia_matches(allum, row, matches);
  disp_board(allum);
  if (allum->nb_lines != 0)
    my_putchar('\n');
  else
    allum->ia_win = 0;
  return (0);
}
