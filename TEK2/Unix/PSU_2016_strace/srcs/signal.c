/*
** signal.c for signal in /home/uberti_l/rendu/Unix/PSU_2016_strace
**
** Made by Lous-Emile Uberti-Ares
** Login   <uberti_l@epitech.net>
**
** Started on  Wed Apr 12 20:56:41 2017 Lous-Emile Uberti-Ares
** Last update Fri Apr 14 16:15:33 2017 Lous-Emile Uberti-Ares
*/

#include <stdio.h>
#include <sys/wait.h>
#include <signal.h>
#include <sys/ptrace.h>
#include "strace.h"

int			sighandler(const int signal, int pid)
{
  static int		saved_pid = -1;
  int			status;

  if (saved_pid == -1)
    saved_pid = pid;
  if (signal != FAKE_SIGNAL)
    {
      waitpid(saved_pid, &status, 0);
      ptrace(PTRACE_DETACH, saved_pid, NULL, NULL);
      ptrace(PTRACE_CONT, saved_pid, NULL, NULL);
      dprintf(1, "strace: Process %d detached <detached ...>\n", saved_pid);
      exit(1);
    }
  return (0);
}

inline _Bool		check_signal(const int status)
{
  return (WIFSTOPPED(status) &&
	  ((WSTOPSIG(status) == SIGTRAP) || WSTOPSIG(status) == SIGSTOP));
}