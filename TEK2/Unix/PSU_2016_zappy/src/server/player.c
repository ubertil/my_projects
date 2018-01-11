/*
** player.c for player.c in /home/nicolas.trognot/rendu/Reseau/PSU_2016_zappy/src/server
**
** Made by Nicolas TROGNOT
** Login   <nicolas.trognot@epitech.net>
**
** Started on  Tue Jun 27 10:10:12 2017 Nicolas TROGNOT
** Last update Thu Jun 29 11:43:09 2017 Nicolas TROGNOT
*/

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "server/server.h"
#include "server/player.h"
#include "server/commands.h"
#include "common/protocol.h"
#include "common/resources.h"

char		check_team_name_exists(t_server *server, char *team_name)
{
  t_name	*tmp;

  if (strcmp(team_name, IS_GRAPHIC_NN) == 0)
    return (1);
  tmp = server->names;
  while (tmp)
    {
      if (tmp->name != NULL && !strcmp(team_name, tmp->name))
	return (1);
      tmp = tmp->next;
    }
  return (0);
}

int		check_disponibility_of_team(t_server *server, char *team_name)
{
  t_player	*tmp;
  int		count;

  tmp = server->players;
  count = 0;
  while (tmp)
    {
      if (tmp->team_name != NULL && !strcmp(team_name, tmp->team_name))
	++count;
      if (strcmp(team_name, IS_GRAPHIC_NN) == 0 &&
	  tmp->team_name != NULL &&
      	  strcmp(tmp->team_name, IS_GRAPHIC_NN) == 0)
      	return (0);
      tmp = tmp->next;
    }
  return (server->client_nb - count);
}

void		init_player(t_server *server, t_player *player)
{
  int		idx;

  player->team_name = NULL;
  player->level = 1;
  player->pos_x = rand() % server->width;
  player->pos_y = rand() % server->height;
  player->direction = rand() % 4;
  player->command_idx = 0;
  player->is_egg = 0;
  player->is_incanting = 0;
  idx = -1;
  while (++idx < 10)
    player->commands[idx].cmd = NULL;
  idx = -1;
  while (++idx < NB_ITEM - 1)
    player->inventory[idx] = 0;
  player->inventory[FOOD] = 1260;
}

char		add_player(t_server *server, int fd)
{
  t_player	*new;

  new = server->players;
  while (new && new->fd != fd)
    new = new->next;
  if (new)
    return (0);
  if ((new = malloc(sizeof(t_player))) == NULL)
    return (1);
  new->fd = fd;
  new->is_graphical = 0;
  new->file = fdopen(new->fd, "r");
  new->is_graphical = 0;
  init_player(server, new);
  new->next = server->players;
  server->players = new;
  return (0);
}

char		confirm_player(t_server *server, char *team_name,
			       int fd)
{
  t_player	*this;
  int		remain;

  this = server->players;
  while (this && this->fd != fd)
    this = this->next;
  if (!this || !check_team_name_exists(server, team_name)
      || !(remain = check_disponibility_of_team(server, team_name))
      || (this->team_name = strdup(team_name)) == NULL)
    {
      dprintf(fd, "ko\n");
      return (1);
    }
  if (strcmp(team_name, IS_GRAPHIC_NN) == 0)
    this->is_graphical = 1;
  else
    {
      dprintf(fd, "%d\n%d %d\n", remain - 1, server->width,
	      server->height);
      (this->is_egg != 0) ? cmd_ebo(server, this) : 0;
      cmd_pnw(server, this);
    }
  return (0);
}
