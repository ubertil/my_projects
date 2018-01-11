/*
** teamname.c for teamname.c in /home/nicolas.trognot/rendu/Reseau/PSU_2016_zappy/src/graphic
**
** Made by Nicolas TROGNOT
** Login   <nicolas.trognot@epitech.net>
**
** Started on  Sun Jul  2 19:12:57 2017 Nicolas TROGNOT
** Last update Sun Jul  2 19:13:12 2017 Nicolas TROGNOT
*/

#include "graphic/player.h"

bool		add_team_name(t_plist *list, char *name)
{
  t_team_name	*t;

  if ((t = malloc(sizeof(t_team_name))) == NULL ||
      (t->name = strdup(name)) == NULL)
    return (false);
  t->next = list->team_name;
  list->team_name = t;
  return (true);
}
