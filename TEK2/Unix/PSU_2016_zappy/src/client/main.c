/*
** main.c for main in /home/uberti_l/rendu/Unix/PSU_2016_zappy
**
** Made by Lous-Emile Uberti-Ares
** Login   <uberti_l@epitech.net>
**
** Started on  Wed Jun 21 10:46:26 2017 Lous-Emile Uberti-Ares
** Last update Tue Jun 27 11:42:25 2017 grella_c
*/

#include <stdio.h>
#include <signal.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <time.h>
#include "client/client.h"
#include "common/utils/errors.h"
#include "common/utils/utils.h"

static int	disp_usage(const char *prog_name, int help)
{
  dprintf(1, "USAGE: %s -p port -n name -h machine\n", prog_name);
  dprintf(1, "\tport\tis the port number\n");
  dprintf(1, "\tname\tis the name of the team\n");
  dprintf(1, "\tmachine\tis the name of the machine, localhost by default\n");
  return ((help != 0) ? (84) : (0));
}

static t_client	*get_args(const int ac, char * const *av)
{
  char		c;
  int		port;
  char		*machine;
  char		*team_name;

  machine = NULL;
  team_name = NULL;
  port = -1;
  while ((c = getopt(ac, av, "p:h:n:")) != -1)
    {
      if (c == 'p')
	{
	  if (!is_nbr(optarg))
	    return (NULL);
	  port = atoi(optarg);
	}
      if (c == 'h')
	machine = optarg;
      if (c == 'n')
	team_name = optarg;
    }
  return ((team_name != NULL) ? (init_client(team_name, machine, port))
	  : (NULL));
}

int		main(const int ac, char * const *av)
{
  int		help;
  t_client	*client;

  help = -1;
  if ((ac == 2 && ((help = strcmp(av[1], "-help")) == 0)) ||
      (ac > 7) || ((client = get_args(ac, av)) == NULL))
    return (disp_usage(av[0], help));
  srand(time(NULL));
  sighandler(-42, client);
  if (signal(SIGINT, (void (*)(int))sighandler) == SIG_ERR)
    d_error("Could not monitor signal SIGINT\n");
  client_loop(client);
  free_client(client);
  return (0);
}
