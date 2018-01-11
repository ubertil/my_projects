/*
** ftrace.h for ftrace in /home/uberti_l/rendu/Unix/PSU_2016_ftrace
**
** Made by Lous-Emile Uberti-Ares
** Login   <uberti_l@epitech.net>
**
** Started on  Tue Apr 18 14:39:17 2017 Lous-Emile Uberti-Ares
** Last update Sun May  7 17:08:34 2017 Lous-Emile Uberti-Ares
*/

#ifndef FTRACE_H_
# define FTRACE_H_
# include <stdlib.h>
# include <sys/user.h>
# include <stdbool.h>
# include "opcode.h"
# include "symbol_finder.h"

# define USAGE "./ftrace <command>\n"
# define ENTERING "Entering function %s at 0x%lx\n"
# define LEAVING "Leaving function %s\n"
# define RECEIVED "Received signal %s\n"

# define ERR_FORK "ftrace: Cannot fork\n"

# define FAKE_SIGNAL 42

typedef struct	s_ftrace
{
  t_list	*list;
  t_opcode	opcode;
  char		*func;
  int		stack;
  int		fd;
  int		pid;
  int		status;
  _Bool		done;
}		t_ftrace;

_Bool		ftrace(int pid, char * const *exec);
_Bool		check_signal(const int signum);
_Bool		free_list(t_list *list);
void		is_func(t_ftrace *ftrace, const long rip);
void		is_ret(t_ftrace *ftrace);
void		display_syscall(t_ftrace *ftrace,
				const long syscall,
				const struct user_regs_struct *regs,
				const size_t ret);
int		sighandler(const int signum, const int pid);

#endif /* !FTRACE_H_ */
