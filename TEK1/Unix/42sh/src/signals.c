/*
** signals.c for signals.c in /home/trognot/rendu/PSU/PSU_2015_42sh/src
**
** Made by nicolas trognot
** Login   <nicolas.trognot@epitech.eu>
**
** Started on  Wed May 11 14:02:58 2016 nicolas trognot
** Last update Sun Jun  5 16:02:00 2016 louis-emile uberti-ares
*/

#include <stdio.h>
#include <signal.h>
#include "shell.h"
#include "tools.h"

static void		sighandler(int signum)
{
  if (signum == SIGINT)
    {
      printf("\n");
      aff_prompt();
    }
}

int			init_signals(void)
{
  sighandler(0);
  if (signal(SIGINT, sighandler) == SIG_ERR)
    return (-1);
  return (0);
}
