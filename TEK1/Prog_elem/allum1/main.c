/*
** main.c for main in /home/uberti_l/rendu/Prog_elem/CPE_2015_Allum1
**
** Made by louis-emile uberti-ares
** Login   <uberti_l@epitech.net>
**
** Started on  Mon Feb  8 11:07:27 2016 louis-emile uberti-ares
** Last update Mon Feb 22 17:15:42 2016 louis-emile uberti-ares
*/

#include <unistd.h>
#include <stdlib.h>
#include <time.h>
#include "include/allum.h"

void		prepare_line(t_allum *allum)
{
  if ((allum->lines = malloc(sizeof(int) * 7)) == NULL)
    exit(84);
  allum->lines[0] = 0;
  allum->lines[1] = 1;
  allum->lines[2] = 3;
  allum->lines[3] = 5;
  allum->lines[4] = 7;
  allum->lines[5] = 0;
}

void		prepare_tab(t_allum *allum)
{
  if ((allum->board = malloc(sizeof(char *) * 6)) == NULL)
    exit(84);
  allum->board[0] = my_strdup("111111111");
  allum->board[1] = my_strdup("100020001");
  allum->board[2] = my_strdup("100222001");
  allum->board[3] = my_strdup("102222201");
  allum->board[4] = my_strdup("122222221");
  allum->board[5] = my_strdup("111111111");
}

int		ia_turn(t_allum *allum)
{
  my_putchar('\n');
  my_putstr("AI's turn...\n");
  allum->ia_win = 0;
  ia_play(allum);
  return (0);
}

void		end_game(t_allum *allum)
{
  if (allum->ia_win == 1)
    my_putstr("You lost, too bad..\n");
  else
    my_putstr("I lost.. snif.. but I'll get you next time!!\n");
  free_all(allum);
}

int		main(void)
{
  t_allum	*allum;

  if ((allum = malloc(sizeof(t_allum))) == NULL)
    return (1);
  srand(time(0));
  first_prompt();
  prepare_tab(allum);
  prepare_line(allum);
  allum->ia_win = 0;
  allum->nb_lines = 4;
  while (allum->nb_lines != 0)
    {
      my_putstr("Your turn:\n");
      if (check_error(allum) == 1)
	return (0);
      prompt_player(allum);
      if (allum->nb_lines != 0)
	ia_turn(allum);
    }
  end_game(allum);
  return (0);
}
