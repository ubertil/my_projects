/*
** team_msg.c for zappy in /home/uberti_l/rendu/Unix/PSU_2016_zappy
**
** Made by Lous-Emile Uberti-Ares
** Login   <uberti_l@epitech.net>
**
** Started on  Fri Jun 30 14:06:24 2017 Lous-Emile Uberti-Ares
** Last update Fri Jun 30 14:10:44 2017 Lous-Emile Uberti-Ares
*/

#include <stdlib.h>
#include <string.h>
#include "client/client.h"
#include "client/ia.h"
#include "client/direction.h"
#include "common/utils/utils.h"

static bool	assemble(t_client *client)
{
  char		*msg;

  msg = NULL;
  asprintf(&msg, "%s %d", "ASSEMBLE", rot13(client->level));
  if (msg)
    {
      broadcast_text(client, msg);
      free(msg);
      return (true);
    }
  return (false);
}

bool		team_msg(t_client *client, const char *cmd)
{
  char		**args;

  args = str_to_wordtab((cmd != NULL && strlen(cmd) > 10) ? (cmd + 10) :
			(cmd), " \t");
  if ((cmd != NULL) && (!strstr(cmd, "ASSEMBLE")))
    return (assemble(client));
  else if (cmd != NULL && strstr(cmd, "ASSEMBLE") && tab_len(args) == 2 &&
	   rot13(atoi(args[1])) == client->level)
    {
      free_wordtab(args);
      client->ia->current = GO_TO_TEAMMATE;
      return (client->ia->func[client->ia->current](client, cmd + 10));
    }
  free_wordtab(args);
  get_inventory(client);
  client->ia->current = NB_STONES;
  return (true);
}
