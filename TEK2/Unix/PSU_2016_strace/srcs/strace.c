#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <sys/ptrace.h>
#include <sys/user.h>
#include <sys/reg.h>
#include "strace.h"

static _Bool			launch_son(const t_strace *info)
{
  int				status;
  long				syscall;
  _Bool				done;
  struct user_regs_struct	regs;

  done = false;
  sighandler(FAKE_SIGNAL, info->pid);
  waitpid(info->pid, &status, 0);
  while (check_signal(status))
    {
      done = true;
      ptrace(PTRACE_GETREGS, info->pid, NULL, &regs);
      syscall = ptrace(PTRACE_PEEKUSER, info->pid, 8 * ORIG_RAX, NULL);
      if (syscall >= 0 && syscall <= 331)
	display_syscall(info, syscall, &regs, regs.rax);
      ptrace(PTRACE_SINGLESTEP, info->pid, NULL, NULL);
      waitpid(info->pid, &status, 0);
    }
  if (done)
    {
      ptrace(PTRACE_DETACH, info->pid, NULL, NULL);
      exit_status(info, status);
    }
  return (true);
}

static _Bool			launch_father(const t_strace *info,
					      const char *prog)
{
  ptrace(PTRACE_TRACEME, 0, NULL, NULL);
  if (execvp(info->exec[0], info->exec) == -1)
    return (false && dprintf(1, ERR_NO_FILE, prog));
  return (true);
}

static _Bool			attach_process(t_strace *info)
{
  ptrace(PTRACE_ATTACH, info->pid, NULL, NULL);
  return (true);
}

_Bool				strace(t_strace *info, const char *prog)
{
  signal(SIGINT, (void (*)(int))sighandler);
  signal(SIGTERM, (void (*)(int))sighandler);
  signal(SIGQUIT, (void (*)(int))sighandler);
  if (info->pid == -1)
    {
      if ((info->pid = fork()) == -1)
	return (false && dprintf(2, ERR_FORK));
      return ((info->pid == 0) ? (launch_father(info, prog)) :
	      (launch_son(info)));
    }
  else
    {
      sighandler(FAKE_SIGNAL, info->pid);
      attach_process(info);
      launch_son(info);
    }
  return (true);
}
