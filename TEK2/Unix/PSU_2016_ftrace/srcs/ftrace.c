/*
** ftrace.c for ftrace in /home/uberti_l/rendu/Unix/PSU_2016_ftrace
**
** Made by Lous-Emile Uberti-Ares
** Login   <uberti_l@epitech.net>
**
** Started on  Wed Apr 19 11:16:59 2017 Lous-Emile Uberti-Ares
** Last update Sun May  7 17:09:01 2017 Lous-Emile Uberti-Ares
*/

#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <sys/ptrace.h>
#include <sys/reg.h>
#include "graph.h"
#include "ftrace.h"
#include "symbol_finder.h"

static _Bool			init_ftrace(t_ftrace *ftrace, t_list *list,
					    const int pid)
{
#ifdef BONUS
  if (!open_graph(&ftrace->fd))
    return (false);
#else
  ftrace->fd = -1;
#endif
  ftrace->list = list;
  ftrace->stack = 0;
  ftrace->pid = pid;
  ftrace->func = NULL;
  ftrace->done = false;
  return (true);
}

static _Bool			launch_son(const int pid, t_list *list)
{
  t_ftrace			ftrace;
  struct user_regs_struct	regs;

  if (!init_ftrace(&ftrace, list, pid))
    return (false);
  sighandler(FAKE_SIGNAL, pid);
  waitpid(pid, &ftrace.status, 0);
  while (check_signal(ftrace.status))
    {
      ftrace.done = true;
      ptrace(PTRACE_GETREGS, pid, NULL, &regs);
      ftrace.opcode.val = ptrace(PTRACE_PEEKDATA, pid, regs.rip, NULL);
      is_func(&ftrace, regs.rip);
      is_ret(&ftrace);
      display_syscall(&ftrace,
		      ptrace(PTRACE_PEEKUSER, pid, 8 * ORIG_RAX, NULL),
		      &regs, regs.rax);
      ptrace(PTRACE_SINGLESTEP, pid, NULL, NULL);
      waitpid(pid, &ftrace.status, 0);
    }
  if (ftrace.done)
    ptrace(PTRACE_DETACH, pid, NULL, NULL);
  close_graph(ftrace.fd);
  return (free_list(list));
}

static _Bool			launch_father(char * const *exec)
{
  if (ptrace(PTRACE_TRACEME, 0, NULL, NULL) == -1)
    return (false);
  return (execvp(exec[0], exec));
}

_Bool				ftrace(int pid, char * const *exec)
{
  t_list			*list;

  if ((signal(SIGINT, (void (*)(int))sighandler) == SIG_ERR) ||
      (signal(SIGTERM, (void (*)(int))sighandler) == SIG_ERR) ||
      (signal(SIGQUIT, (void (*)(int))sighandler) == SIG_ERR) ||
      ((list = symbol_finder(exec[0])) == NULL))
    return (false);
  if (pid == -1)
    {
      if ((pid = fork()) == -1)
	return (false && dprintf(2, ERR_FORK));
      return ((pid == 0) ? (launch_father(exec)) : (launch_son(pid, list)));
    }
  else
    {
      sighandler(FAKE_SIGNAL, pid);
      if (ptrace(PTRACE_ATTACH, pid, NULL, NULL))
	return (false);
      launch_son(pid, list);
    }
  return (true);
}
