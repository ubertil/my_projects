/*
** main.c for main in /home/uberti_l/rendu/Unix/PSU_2016_zappy
**
** Made by Lous-Emile Uberti-Ares
** Login   <uberti_l@epitech.net>
**
** Started on  Wed Jun 21 10:45:59 2017 Lous-Emile Uberti-Ares
** Last update Tue Jun 27 10:14:07 2017 Nicolas TROGNOT
*/

#include <stdio.h>
#include <unistd.h>
#include <signal.h>
#include "server/server.h"
#include "server/args.h"
#include "server/commands.h"

static const t_arg	g_args[] =
{
  {'p', &arg_p},
  {'x', &arg_x},
  {'y', &arg_y},
  {'n', &arg_n},
  {'c', &arg_c},
  {'f', &arg_f}
};

void	handle_sigpipe(__attribute__((unused))int sig)
{
  return ;
}

int	display_usage(char *filename)
{
  printf("\nUSAGE: %s -p port -x width -y height -n name1 name2 ...",
	 filename);
  printf(" -c clientsNb -f freq\n\n");
  printf("\tport\t  is the port number\n");
  printf("\twidth\t  is the width of the world\n");
  printf("\theight\t  is the height of the world\n");
  printf("\tnameX\t  is the name of the team X\n");
  printf("\tclientsNb is the number of authorized clients per team\n");
  printf("\tfreq\t  is the reciprocal of time unit for execution of actions");
  printf("\n\n");
  return (1);
}

int	handle_arguments(const int ac, char **av, t_server *server)
{
  char	found;
  char	c;
  int	i;

  opterr = 0;
  while ((c = getopt(ac, av, "p:x:y:n:c:f:")) != -1 && (found = 0) != -1)
    {
      i = -1;
      while (++i < NB_ARGS)
	{
	  if (g_args[i].c == c && (found = 1))
	    {
	      optind--;
	      while (optind < ac && *av[optind] != '-')
		{
		  if (g_args[i].func(server, av[optind]) != 0)
		    return (display_usage(av[0]));
		  optind++;
		}
	    }
	}
      if (found == 0)
	return (display_usage(av[0]));
    }
  return (0);
}

int		main(const int ac, char **av)
{
  t_server	server;

  signal(SIGPIPE, handle_sigpipe);
  load_default_values(&server);
  if (handle_arguments(ac, av, &server) != 0 ||
      init_server(&server) != 0)
    return (0);
  init_connection(&server);
  free_server(&server);
  return (0);
}
