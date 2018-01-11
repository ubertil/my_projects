/*
** graphic_take.c for zappy in /home/wadel_n/Tek2/PSU_2016_zappy/src/server/commands/graphic
** 
** Made by Nicolas Wadel
** Login   <wadel_n@epitech.net>
** 
** Started on  Thu Jun 29 12:11:57 2017 Nicolas Wadel
** Last update Thu Jun 29 12:11:58 2017 Nicolas Wadel
*/

#include "server/server.h"
#include "server/commands.h"

void	graphic_take(t_server *server, t_player *player, enum e_item resource)
{
  cmd_pgt(server, player, resource);
  cmd_pin(server, player);
  cmd_bct(server, player->pos_x, player->pos_y);
}
