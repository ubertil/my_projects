/*
** cmd_incantation.c for cmd_incantation.c in /home/nicolas.trognot/rendu/Reseau/PSU_2016_zappy/src/server/commands
**
** Made by Nicolas TROGNOT
** Login   <nicolas.trognot@epitech.net>
**
** Started on  Thu Jun 29 11:44:32 2017 Nicolas TROGNOT
** Last update Thu Jun 29 11:44:43 2017 Nicolas TROGNOT
*/

#include <stdio.h>
#include "server/server.h"
#include "server/commands.h"

static const t_incantation	g_incantation[NB_INCANTATION] =
  {
    {1, {1, 0, 0, 0, 0, 0}},
    {2, {1, 1, 1, 0, 0, 0}},
    {2, {2, 0, 1, 0, 2, 0}},
    {4, {1, 1, 2, 0, 1, 0}},
    {4, {1, 2, 1, 3, 0, 0}},
    {6, {1, 2, 3, 0, 1, 0}},
    {6, {2, 2, 2, 2, 2, 1}}
  };

static int	count_player_on_tile(t_server *server, t_player *this)
{
  t_player	*index;
  int		count;

  count = 0;
  index = server->players;
  while (index)
    {
      if (index->pos_x == this->pos_x && index->pos_y == this->pos_y)
	{
	  if (index->level == this->level)
	    ++count;
	  else
	    return (-1);
	}
      index = index->next;
    }
  return (count);
}

void		check_incantation(t_server *server,
				  const int fd)
{
  t_player	*this;
  int		i;

  this = server->players;
  while (this && this->fd != fd)
    this = this->next;
  if (!this || this->level == 8)
    {
      dprintf(fd, "ko\n");
      return ;
    }
  i = -1;
  while (++i < NB_ITEM - 1)
    if (server->map.cases[this->pos_y][this->pos_x].content[i] !=
	g_incantation[this->level - 1].amount[i])
      break ;
  if (i != NB_ITEM - 1 || count_player_on_tile(server, this) !=
      g_incantation[this->level - 1].nb_player)
    dprintf(fd, "ko\n");
  else
    {
      dprintf(fd, "Elevation underway\n");
      cmd_pic(server, this);
    }
}

static void	do_leveling(t_server *server, t_player *this)
{
  t_player	*index;

  index = server->players;
  cmd_pie(server, this);
  while (index)
    {
      if (index->pos_x == this->pos_x && index->pos_y == this->pos_y)
	{
	  ++index->level;
	  dprintf(index->fd, "Current level: %d\n", index->level);
	  cmd_plv(server, index);
	}
      index = index->next;
    }
}

void		cmd_incantation(t_server *server,
				__attribute__((unused)) char *arg,
				const int fd)
{
  t_player	*this;
  int		i;

  this = server->players;
  while (this && this->fd != fd)
    this = this->next;
  if (!this || this->level == 8)
    {
      dprintf(fd, "ko\n");
      if (this->level == 8)
	this->is_incanting = 0;
      return ;
    }
  i = -1;
  while (++i < NB_ITEM - 1)
    if (server->map.cases[this->pos_y][this->pos_x].content[i] !=
	g_incantation[this->level - 1].amount[i])
      break ;
  if (i != NB_ITEM - 1 || count_player_on_tile(server, this) !=
      g_incantation[this->level - 1].nb_player)
    dprintf(fd, "ko\n");
  else
    do_leveling(server, this);
  this->is_incanting = 0;
}
