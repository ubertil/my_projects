/*
** incantation.c for zappy in /home/uberti_l/rendu/Unix/PSU_2016_zappy
**
** Made by Lous-Emile Uberti-Ares
** Login   <uberti_l@epitech.net>
**
** Started on  Wed Jun 28 13:49:56 2017 Lous-Emile Uberti-Ares
** Last update Fri Jun 30 15:18:09 2017 grella_c
*/

#include <string.h>
#include "client/client.h"
#include "client/ia.h"

bool		incantation(t_client *client, const char *cmd)
{
  static int	elev = 0;

  dprintf(1, "Incantation got : %s\n", cmd);
  if (cmd != NULL && (strstr(cmd, "Elevation underway") || (elev == 1)))
    {
      if (strstr(cmd, "Current level"))
	{
	  elev = 0;
	  client->level++;
	  client->ia->current = TEAM_MSG;
	  return (client->ia->func[client->ia->current](client, NULL));
	}
      else
	{
	  elev = 1;
	  client->ia->current = INCANTATION;
	}
      return (true);
    }
  client->ia->current = INCANTATION;
  return (do_incantation(client));
}
