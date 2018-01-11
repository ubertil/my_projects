/*
** graphic_drop.c for zappy in /home/wadel_n/Tek2/PSU_2016_zappy/src/server/commands/graphic
**
** Made by Nicolas Wadel
** Login   <wadel_n@epitech.net>
**
** Started on  Thu Jun 29 12:13:03 2017 Nicolas Wadel
** Last update Sun Jul  2 19:27:25 2017 Nicolas TROGNOT
*/

#include "server/server.h"
#include "server/commands.h"

void	graphic_drop(t_server *server, t_player *player, enum e_item resource)
{
  cmd_pdr(server, player, resource);
  cmd_pin(server, player);
  cmd_bct(server, player->pos_x, player->pos_y);
}
