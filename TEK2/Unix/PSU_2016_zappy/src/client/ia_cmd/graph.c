/*
** ia_graph.c for ia_graph in /home/uberti_l/rendu/Unix/PSU_2016_zappy
**
** Made by Lous-Emile Uberti-Ares
** Login   <uberti_l@epitech.net>
**
** Started on  Tue Jun 27 11:09:41 2017 Lous-Emile Uberti-Ares
** Last update Fri Jun 30 14:46:52 2017 grella_c
*/

#include <stdlib.h>
#include "client/ia.h"

t_ia		*init_ia(void)
{
  t_ia		*ia;

  if ((ia = malloc(sizeof(*ia))) == NULL)
    return (NULL);
  ia->func[0] = enough_food;
  ia->func[1] = nb_stones;
  ia->func[2] = nb_players;
  ia->func[3] = incantation;
  ia->func[4] = call_reinforcement;
  ia->func[5] = team_msg;
  ia->func[6] = reached_destination;
  ia->func[7] = food_on_tile;
  ia->func[8] = go_to_food;
  ia->func[9] = take_food;
  ia->func[10] = go_to_teammate;
  ia->func[11] = take_stone;
  ia->func[12] = stone_on_tile;
  ia->func[13] = go_to_stone;
  ia->func[14] = set_stones;
  ia->target = NULL;
  ia->input = NULL;
  ia->role = COLLECTER;
  ia->current = ENOUGH_FOOD;
  return (ia);
}

void		free_ia(t_ia *ia)
{
  t_destination	*tmp;

  tmp = NULL;
  if (ia->target)
    {
      tmp = ia->target;
      while (ia->target)
	{
	  tmp = ia->target;
	  ia->target = ia->target->next;
	  free(tmp);
	}
      ia->target = NULL;
    }
  if (ia->input)
    free(ia->input);
  free(ia);
}
