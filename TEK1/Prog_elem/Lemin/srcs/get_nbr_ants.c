/*
** get_nbr_ants.c for get_nbr_ants in /home/uberti_l/rendu/Prog_elem/CPE_2015_Lemin
**
** Made by louis-emile uberti-ares
** Login   <uberti_l@epitech.net>
**
** Started on  Thu Apr  7 14:40:07 2016 louis-emile uberti-ares
** Last update Mon Apr 25 18:15:50 2016 come grellard
*/

#include <stdlib.h>
#include "lemin.h"

int		get_nbr_ants(t_lemin *lemin)
{
  char		**argv;
  char		*str;

  if ((str = get_next_line(0)) == NULL)
    return (1);
  while (str[0] == '#' && str[1] != '#')
    if ((str = get_next_line(0)) == NULL)
      return (1);
  argv = my_str_to_wordtab(str);
  if ((argv == NULL)
      || (argv[0] == NULL || argv[0][0] == '\0' || argv[0][0] == '\n')
      || (argv[1] != NULL) || (my_hard_getnbr(argv[0]) < 0))
    {
      free(str);
      free_args(argv);
      return (1);
    }
  lemin->nb_ants = my_hard_getnbr(argv[0]);
  my_putstr(str);
  my_putstr("\n");
  free(str);
  free_args(argv);
  return (0);
}
