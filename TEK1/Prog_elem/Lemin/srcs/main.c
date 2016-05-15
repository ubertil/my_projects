/*
** main.c for main.c in /home/uberti_l/rendu/Prog_elem/CPE_2015_Lemin/srcs
**
** Made by louis-emile uberti-ares
** Login   <uberti_l@epitech.net>
**
** Started on  Thu Apr  7 13:27:34 2016 louis-emile uberti-ares
** Last update Sun Apr 24 15:53:39 2016 louis-emile uberti-ares
*/

#include <stdlib.h>
#include "lemin.h"

int		main(void)
{
  int		ret;
  t_lemin	*lemin;

  if ((lemin = malloc(sizeof(t_lemin))) == NULL)
    return (-1);
  lemin->nb_rooms = 0;
  lemin->got_matrix = 0;
  lemin->rooms = NULL;
  lemin->list = NULL;
  lemin->who = 0;
  lemin->err_after_start_end = 0;
  ret = check_args(lemin);
  if (ret > 1)
    return (ret);
  if (lemin->got_matrix == 2)
    {
      launch_algorithm(lemin, NULL, NULL);
      sort_list(lemin->list);
      launch_feeder(lemin->list, lemin);
    }
  free_struct(lemin);
  return (0);
}
