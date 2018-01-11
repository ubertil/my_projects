/*
** syscalls.h for syscalls.h in /home/uberti_l/rendu/Unix/PSU_2016_strace
**
** Made by Lous-Emile Uberti-Ares
** Login   <uberti_l@epitech.net>
**
** Started on  Wed Apr 12 20:59:13 2017 Lous-Emile Uberti-Ares
** Last update Sun May  7 10:43:33 2017 Lous-Emile Uberti-Ares
*/

#ifndef SYSCALLS_H_
# define SYSCALLS_H_
# include <asm/unistd_64.h>

# define INLINED __attribute__((gnu_inline)) inline

# define HEX_RET ") = 0x%lx\n"
# define HEX_PARAM "0x%lx"
# define SYSCALL "Syscall %s("

typedef struct		s_syscall
{
  int			sys_nb;
  const char		*name;
  int			nb_param;
}			t_syscall;

size_t			get_param(const struct user_regs_struct *regs,
				  const int i);

#endif /* !SYSCALLS_H_ */
