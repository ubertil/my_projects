/*
** get_nbr_ants.c for get_nbr_ants in /home/uberti_l/rendu/Prog_elem/CPE_2015_Lemin
**
** Made by louis-emile uberti-ares
** Login   <uberti_l@epitech.net>
**
** Started on  Thu Apr  7 14:40:07 2016 louis-emile uberti-ares
** Last update Sun Apr 24 15:11:55 2016 louis-emile uberti-ares
*/

#include <stdlib.h>
#include "visu.h"

int		get_nbr_ants(t_visu *visu)
{
  char		**argv;
  char		*str;

  if ((str = get_next_line(0)) != NULL)
    argv = my_str_to_wordtab(str);
  else
    return (1);
  if ((argv[0] == NULL || argv[0][0] == '\0' || argv[0][0] == '\n')
      || (argv[1] != NULL)
      || (my_hard_getnbr(argv[0]) < 0))
    {
      free(str);
      free_args(argv);
      return (1);
    }
  visu->nb_ants = my_hard_getnbr(argv[0]);
  free(str);
  free_args(argv);
  return (0);
}
