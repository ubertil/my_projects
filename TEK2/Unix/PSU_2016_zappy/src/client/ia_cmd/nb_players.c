/*
** nb_players.c for zappy in /home/uberti_l/rendu/Unix/PSU_2016_zappy
**
** Made by Lous-Emile Uberti-Ares
** Login   <uberti_l@epitech.net>
**
** Started on  Wed Jun 28 13:50:44 2017 Lous-Emile Uberti-Ares
** Last update Fri Jun 30 15:12:25 2017 grella_c
*/

#include <stdlib.h>
#include <string.h>
#include "client/client.h"
#include "client/ia.h"
#include "common/incantation.h"
#include "common/utils/utils.h"

static const t_incantation	g_incantation[NB_INCANTATION] =
  {
    {1, {1, 0, 0, 0, 0, 0}},
    {2, {1, 1, 1, 0, 0, 0}},
    {2, {2, 0, 1, 0, 2, 0}},
    {4, {1, 1, 2, 0, 1, 0}},
    {4, {1, 2, 1, 3, 0, 0}},
    {6, {1, 2, 3, 0, 1, 0}},
    {6, {2, 2, 2, 2, 2, 1}},
  };

bool		nb_players(t_client *client, const char *cmd)
{
  int		i;
  int		nb_players;
  char		**args;
  char		**players;

  i = -1;
  nb_players = 0;
  args = str_to_wordtab(cmd, "[,]");
  players = str_to_wordtab(args[0], " \t");
  while (players != NULL && players[++i] != NULL)
    if (strstr(players[i], "player"))
      nb_players++;
  free_wordtab(args);
  free_wordtab(players);
  if (nb_players == g_incantation[client->level - 1].nb_player)
    client->ia->current = SET_STONES;
  else
    client->ia->current = TEAM_MSG;
  return (client->ia->func[client->ia->current](client, NULL));
}
