/*
** strace.h for PSU_2016_strace in /home/uberti_p/delivery/PSU_2016_strace/strace.h
**
** Made by Louis-Emile Uberti-Ares
** Login   <louis-emile.uberti-ares@epitech.eu>
**
** Started on  mar. avr. 11 11:02:33 2017 Louis-Emile Uberti-Arès
** Last update Thu Apr 13 21:27:07 2017 Lous-Emile Uberti-Ares
*/

#ifndef STRACE_H_
# define STRACE_H_
# include <sys/user.h>
# include <stdlib.h>
# include <stdbool.h>

# define USAGE "Usage : ./strace [-s] [-p <pid>|<command>]\n"
# define ERR_NO_FILE "strace: Cannot stat '%s' : No such file or directory\n"
# define ERR_FORK "strace: Cannot fork\n"

# define FAKE_SIGNAL -42

typedef struct	s_strace
{
  _Bool		verbose;
  int		pid;
  char		**exec;
}		t_strace;

_Bool		strace(t_strace *info, const char *prog);
_Bool		check_signal(const int status);
int		sighandler(const int signal, int pid);
void		display_syscall(const t_strace *info,
				const long syscall,
				const struct user_regs_struct *regs,
				const size_t ret);
void		exit_status(const t_strace *info, const int status);
size_t		get_param(const struct user_regs_struct *regs, int nb);

#endif /* !STRACE_H_ */
