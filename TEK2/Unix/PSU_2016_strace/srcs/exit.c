/*
** exit.c for exit in /home/uberti_l/rendu/Unix/PSU_2016_strace
**
** Made by Lous-Emile Uberti-Ares
** Login   <uberti_l@epitech.net>
**
** Started on  Wed Apr 12 22:49:08 2017 Lous-Emile Uberti-Ares
** Last update Sun Apr 16 21:35:06 2017 Lous-Emile Uberti-Ares
*/

#include <signal.h>
#include <stdio.h>
#include "strace.h"

static const char	*g_signals[] =
  {
    "NULL",
    "SIGHUP",
    "SIGINT",
    "SIGQUIT",
    "SIGILL",
    "SIGTRAP",
    "SIGABRT",
    "SIGBUS",
    "SIGFPE",
    "SIGKILL",
    "SIGUSR1",
    "SIGSEGV",
    "SIGUSR2",
    "SIGPIPE",
    "SIGALRM",
    "SIGTERM",
    "SIGSTKFLT",
    "SIGCHLD",
    "SIGCONT",
    "SIGSTOP",
    "SIGTSTP",
    "SIGTTIN",
    "SIGTTOU",
    "SIGURG",
    "SIGXCPU",
    "SIGXFSZ",
    "SIGVTALRM",
    "SIGPROF",
    "SIGWINCH",
    "SIGIO",
    "SIGPWR",
    "SIGSYS",
    "SIGRTMIN",
    "SIGRTMIN+1",
    "SIGRTMIN+2",
    "SIGRTMIN+3",
    "SIGRTMIN+4",
    "SIGRTMIN+5",
    "SIGRTMIN+6",
    "SIGRTMIN+7",
    "SIGRTMIN+8",
    "SIGRTMIN+9",
    "SIGRTMIN+10",
    "SIGRTMIN+11",
    "SIGRTMIN+12",
    "SIGRTMIN+13",
    "SIGRTMIN+14",
    "SIGRTMIN+15",
    "SIGRTMAX-14",
    "SIGRTMAX-13",
    "SIGRTMAX-12",
    "SIGRTMAX-11",
    "SIGRTMAX-10",
    "SIGRTMAX-9",
    "SIGRTMAX-8",
    "SIGRTMAX-7",
    "SIGRTMAX-6",
    "SIGRTMAX-5",
    "SIGRTMAX-4",
    "SIGRTMAX-3",
    "SIGRTMAX-2",
    "SIGRTMAX-1",
    "SIGRTMAX",
  };

void			exit_status(const t_strace *info, const int status)
{
  if (WIFEXITED(status))
    {
      (info->verbose) ? (printf("exit_group(%d) = ?\n", WEXITSTATUS(status))) :
	(printf("exit_group(0x%lx) = ?\n",
		(long unsigned int)WEXITSTATUS(status)));
      (info->verbose) ?
	(printf("+++ exited with %d +++\n",WEXITSTATUS(status))) :
	(printf("+++ exited with 0x%lx +++\n",
		(long unsigned int)WEXITSTATUS(status)));
    }
  else if (WIFSIGNALED(status) || (WIFSTOPPED(status)))
    printf("+++ Killed by %s +++\n",
	   g_signals[((WIFSIGNALED(status)) ? (WTERMSIG(status)) :
		      (WSTOPSIG(status)))]);
}
