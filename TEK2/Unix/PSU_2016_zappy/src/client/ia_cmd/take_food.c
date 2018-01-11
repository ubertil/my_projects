/*
** take_food.c for zappy in /home/uberti_l/rendu/Unix/PSU_2016_zappy
**
** Made by Lous-Emile Uberti-Ares
** Login   <uberti_l@epitech.net>
**
** Started on  Wed Jun 28 14:06:20 2017 Lous-Emile Uberti-Ares
** Last update Fri Jun 30 14:21:26 2017 Lous-Emile Uberti-Ares
*/

#include "client/ia.h"
#include "client/client.h"
#include "common/utils/utils.h"

bool		take_food(t_client *client, UNUSED const char *cmd)
{
  take_object(client, "food");
  client->ia->current = ENOUGH_FOOD;
  return (true);
}
