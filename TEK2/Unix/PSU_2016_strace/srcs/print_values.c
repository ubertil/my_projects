/*
** print_values.c for print_values in /home/uberti_l/rendu/Unix/PSU_2016_strace
**
** Made by Lous-Emile Uberti-Ares
** Login   <uberti_l@epitech.net>
**
** Started on  Wed Apr 12 21:38:21 2017 Lous-Emile Uberti-Ares
** Last update Thu Apr 13 23:44:07 2017 Lous-Emile Uberti-Ares
*/

#include <stdio.h>
#include <sys/ptrace.h>
#include <string.h>
#include <unistd.h>
#include "strace.h"
#include "types.h"

INLINED int	print_int(const int pid, const size_t value)
{
  (void)pid;
  return (printf("%d", (int)value));
}

INLINED int	print_char(const int pid, const size_t value)
{
  long		addr;
  char		str[62];
  int		i;
  int		nb;

  addr = 0xDEADBEEF;
  i = 0;
  nb = 0;
  printf("\"");
  while ((unsigned)i < 4 * sizeof(addr))
    {
      addr = ptrace(PTRACE_PEEKTEXT, pid, value + i, NULL);
      if (!addr)
	return (nb + printf("\""));
      memmove(str, &addr, sizeof(addr));
      nb += printf("%s", str);
      i += sizeof(addr);
    }
  nb += printf("\"");
  return (nb);
}

INLINED int	print_off_t(const int pid, const size_t value)
{
  (void)pid;
  return ((value) ? (printf("0x%lx", value)) : (printf("0")));
}

INLINED int	print_void(const int pid, const size_t value)
{
  (void)pid;
  return ((value) ? (printf("%p", (void *)(value))) : (printf("NULL")));
}

INLINED int	print_size_t(const int pid, const size_t value)
{
  (void)pid;
  return ((value) ? (printf("%lu", value)) : (printf("0")));
}
