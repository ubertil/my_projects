/*
** cmd_look.c for cmd_look.c in /home/nicolas.trognot/rendu/Reseau/PSU_2016_zappy/src/server/commands
**
** Made by Nicolas TROGNOT
** Login   <nicolas.trognot@epitech.net>
**
** Started on  Thu Jun 29 11:28:23 2017 Nicolas TROGNOT
** Last update Thu Jun 29 11:28:34 2017 Nicolas TROGNOT
*/

#include <unistd.h>
#include <stdio.h>
#include "common/resources.h"
#include "common/directions.h"
#include "server/server.h"

static const t_rotation	g_rot_value[4] =
  {
    {NORTH, {1, 0}},
    {EAST, {0, 1}},
    {WEST, {-1, 0}},
    {SOUTH, {0, -1}}
  };

static const t_item	g_item_tab[NB_ITEM] =
  {
    {LINEMATE, "linemate"},
    {DERAUMERE, "deraumere"},
    {SIBUR, "sibur"},
    {MENDIANE, "mendiane"},
    {PHIRAS, "phiras"},
    {THYSTAME, "thystame"},
    {FOOD, "food"}
  };

void		rotation(t_server *server, t_player *this, int tmp[2],
			 int pos[2])
{
  tmp[0] = ((-pos[0] * g_rot_value[this->direction].tab[0] -
	     -pos[1] * g_rot_value[this->direction].tab[1])
	    + this->pos_x + server->width) % server->width;
  tmp[1] = ((-pos[0] * g_rot_value[this->direction].tab[1] +
	     -pos[1] * g_rot_value[this->direction].tab[0])
	    + this->pos_y + server->height) % server->height;
}

static void	catch_player(t_server *server, int pos[2], const int fd)
{
  t_player	*index;

  index = server->players;
  while (index)
    {
      if (index->pos_x == pos[0] && index->pos_y == pos[1] &&
	  index->fd != fd && index->is_graphical == 0)
	dprintf(fd, " player");
      index = index->next;
    }
}

static void		prompt_amount_item(t_server *server, const int fd,
					   const int index, int tmp[2])
{
  int			i;

  i = -1;
  while (++i < server->map.cases[tmp[1]][tmp[0]].content[index])
    dprintf(fd, " %s", g_item_tab[index].item);
}

void		cmd_look(t_server *server,
			 __attribute__((unused)) char *arg,
			 const int fd)
{
  t_player	*this;
  int		pos[2];
  int		index;
  int		tmp[2];

  this = server->players;
  while (this && this->fd != fd)
    this = this->next;
  if (!this || !this->team_name)
    return ;
  pos[1] = -1;
  dprintf(fd, "[player");
  while (++pos[1] <= this->level && (pos[0] = pos[1] + 1))
    while (--pos[0] >= -pos[1] && (index = -1))
      {
	rotation(server, this, tmp, pos);
	catch_player(server, tmp, this->fd);
	while (++index < NB_ITEM)
	  if (server->map.cases[tmp[1]][tmp[0]].content[index] != 0)
	    prompt_amount_item(server, fd, index, tmp);
	dprintf(fd, ",");
      }
  dprintf(fd, "]\n");
}
