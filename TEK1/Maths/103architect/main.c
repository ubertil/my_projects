/*
** main.c for main in /home/uberti_l/rendu/103architect
**
** Made by louis-emile uberti-ares
** Login   <uberti_l@epitech.net>
**
** Started on  Wed Dec  9 14:18:40 2015 louis-emile uberti-ares
** Last update Thu Dec 10 16:26:52 2015 nicolas trognot
*/

#include "include/architect.h"
#include <stdlib.h>
#include <stdio.h>

static const t_list	list[4] =
  {
    {'t', &do_translation},
    {'h', &do_homothety},
    {'r', &do_rotation},
    {'s', &do_symmetry}
  };

t_num		*reverse_my_numbers(t_num *numbers)
{
  t_num		*new_numbers;
  t_num		*next_numbers;

  new_numbers = NULL;
  while (numbers) {
    next_numbers = numbers->next;
    numbers->next = new_numbers;
    new_numbers = numbers;
    numbers = next_numbers;
  }
  return (new_numbers);
}

t_fla		*reverse_my_flags(t_fla *flags)
{
  t_fla		*new_flags;
  t_fla		*next_flags;

  new_flags = NULL;
  while (flags) {
    next_flags = flags->next;
    flags->next = new_flags;
    new_flags = flags;
    flags = next_flags;
  }
  return (new_flags);
}

int			main(int ac, char **av)
{
  t_info		*info;
  int			i;

  info = parseur_argv(ac, av);
  info->numbers = reverse_my_numbers(info->numbers);
  info->flags = reverse_my_flags(info->flags);
  info->disp_matrix = 0;
  i = 0;
  while (info->flags != NULL)
    {
      if (info->flags->next == NULL)
	info->disp_matrix = 1;
      while (list[i].letter != info->flags->flags)
	i = i + 1;
      list[i].func(info);
      i = 0;
      info->flags = info->flags->next;
    }
  exit(0);
}
