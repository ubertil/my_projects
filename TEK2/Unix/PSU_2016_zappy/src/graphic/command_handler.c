/*
** command_handler.c for command_handler.c in /home/nicolas.trognot/rendu/Reseau/PSU_2016_zappy/src/graphic
**
** Made by Nicolas TROGNOT
** Login   <nicolas.trognot@epitech.net>
**
** Started on  Sun Jul  2 19:14:46 2017 Nicolas TROGNOT
** Last update Sun Jul  2 19:14:49 2017 Nicolas TROGNOT
*/

#include <stdio.h>
#include <string.h>
#include "graphic/command_handler.h"

static const t_command	g_cmds[] =
  {
    {"msz", handle_msz},
    {"bct", handle_bct},
    {"pnw", handle_pnw},
    {"ppo", handle_ppo},
    {"tna", handle_tna},
    {"pdi", handle_pdi},
    {"plv", handle_plv},
    {"pin", handle_pin},
    {"pgt", handle_pgt}
  };

bool		handle_current_command(t_core *core, char *str)
{
  int		i;

  i = -1;
  while (++i < NB_CMDS_GRAPHIC)
    {
      if (strncmp(g_cmds[i].command, str,
		  strlen(g_cmds[i].command)) == 0)
	{
	  printf("[+] %s\n", str);
	  return (g_cmds[i].func(core, str));
	}
    }
  printf("[-] %s\n", str);
  return (true);
}

bool		handle_commands(t_core *core)
{
  char		*str;

  str = strtok(core->client->buf, "\n");
  while (str != NULL)
    {
      if (strcmp(str, "ko") == 0)
	return (false);
      if (!handle_current_command(core, str))
	return (false);
      str = strtok(NULL, "\n");
    }
  return (true);
}
