/*
** get_param.c for get_param in /home/uberti_l/rendu/Unix/PSU_2016_strace
**
** Made by Lous-Emile Uberti-Ares
** Login   <uberti_l@epitech.net>
**
** Started on  Wed Apr 12 21:12:18 2017 Lous-Emile Uberti-Ares
** Last update Wed Apr 12 22:44:05 2017 Lous-Emile Uberti-Ares
*/

#include <stdlib.h>
#include <sys/user.h>

size_t			get_param(const struct user_regs_struct *regs, int nb)
{
  return ((nb == 0) ? (regs->rdi) :
	  (nb == 1) ? (regs->rsi) :
	  (nb == 2) ? (regs->rdx) :
	  (nb == 3) ? (regs->rcx) :
	  (nb == 4) ? (regs->r8) :
	  (nb == 5) ? (regs->r9) : ((size_t)-1));
}
