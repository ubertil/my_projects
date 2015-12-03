/*
** main.c for main in /home/uberti_l/rendu/PSU_2015_my_select
**
** Made by louis-emile uberti-ares
** Login   <uberti_l@epitech.net>
**
** Started on  Mon Nov 30 21:06:42 2015 louis-emile uberti-ares
** Last update Thu Dec  3 10:10:55 2015 louis-emile uberti-ares
*/

#include "include/my_select.h"
#include <ncurses.h>
#include <ncurses/curses.h>
#include <stdlib.h>
#include <unistd.h>

void		get_key(my_select *select)
{
  if (select->key == KEY_UP)
    select->cursor = select->cursor - 1;
  if (select->key == KEY_DOWN)
    select->cursor = select->cursor + 1;
  if (select->cursor == 0)
    select->cursor = select->nb_arg - 1;
  else if (select->cursor == select->nb_arg)
    select->cursor = 0;
}

void		set_responses(my_select *select, char **av)
{
  int		i;
  int		*pos;

  select->cursor = 1;
  if ((pos = malloc(select->nb_arg * sizeof(int))) == NULL)
    exit (84);
  get_key(select);
  if (select->key == '\n')
    pos[select->cursor] = 1 - pos[select->cursor];
  initscr();
  i = 1;
  while (i < select->nb_arg)
    {
      if (i == select->cursor)
	attrset(A_UNDERLINE);
      else if (pos[i] == 1)
	attrset(A_REVERSE);
      else
	attrset(A_NORMAL);
      move(i - 1, 0);
      printw(av[i]);
      i = i + 1;
    }
}

void		my_core(my_select *select, char **av)
{
  raw();
  keypad(stdscr, TRUE);
  select->key = getch();
  while (select->key != 27)
    {
      set_responses(select ,av);
      keypad(stdscr, TRUE);
      select->key = getch();
      refresh();
      curs_set(0);
      noecho();
    }
  endwin();
}

int		main(int ac, char **av)
{
  my_select	*select;

  if ((select = malloc(sizeof(my_select))) == NULL)
    return (1);
  select->nb_arg = ac;
  if (ac == 1)
    {
      write(2, "Usage : ./my_select [arguments] | $\n", 36);
      return (1);
    }
  else
    my_core(select, av);
  return (0);
}
