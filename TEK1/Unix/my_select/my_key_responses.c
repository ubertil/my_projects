/*
** my_key_resposes.c for my_key_responses in /home/uberti_l/rendu/PSU_2015_my_select
**
** Made by louis-emile uberti-ares
** Login   <uberti_l@epitech.net>
**
** Started on  Tue Dec  1 14:35:12 2015 louis-emile uberti-ares
** Last update Tue Dec  1 16:46:08 2015 louis-emile uberti-ares
*/

#include <ncurses.h>
#include <stdlib.h>
#include "include/my_select.h"

void		go_up(t_arg *a)
{
  refresh();

}

void		go_down(t_arg *a)
{
  refresh();
}

void		my_send(t_arg *a)
{
  endwin();
}

void		my_select(t_arg *a)
{
  refresh();
}
