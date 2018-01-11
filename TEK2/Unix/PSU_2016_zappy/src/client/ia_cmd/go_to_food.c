/*
** go_to_food.c for zappy in /home/uberti_l/rendu/Unix/PSU_2016_zappy
**
** Made by Lous-Emile Uberti-Ares
** Login   <uberti_l@epitech.net>
**
** Started on  Wed Jun 28 13:46:05 2017 Lous-Emile Uberti-Ares
** Last update Thu Jun 29 14:30:03 2017 Lous-Emile Uberti-Ares
*/

#include <stdlib.h>
#include "client/client.h"

bool		go_to_food(t_client *client, const char *cmd)
{
  move_to(client, rand() % 15, false);
  (void)cmd;
  return (true);
}
