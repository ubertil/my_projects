/*
** syscalls.h for syscalls.h in /home/uberti_l/rendu/Unix/PSU_2016_strace
**
** Made by Lous-Emile Uberti-Ares
** Login   <uberti_l@epitech.net>
**
** Started on  Wed Apr 12 20:59:13 2017 Lous-Emile Uberti-Ares
** Last update Thu Apr 13 23:41:12 2017 Lous-Emile Uberti-Ares
*/

#ifndef SYSCALLS_H_
# define SYSCALLS_H_
# include <asm/unistd_64.h>
# include "types.h"

typedef struct		s_syscall
{
  int			sys_nb;
  const char		*name;
  int			nb_param;
  enum e_type		params[6];
}			t_syscall;

#endif /* !SYSCALLS_H_ */
