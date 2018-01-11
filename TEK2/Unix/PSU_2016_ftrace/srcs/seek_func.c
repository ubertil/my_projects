/*
** seek_func.c for sekk_func in /home/uberti_l/rendu/Unix/PSU_2016_ftrace
**
** Made by Lous-Emile Uberti-Ares
** Login   <uberti_l@epitech.net>
**
** Started on  Sun May  7 14:40:59 2017 Lous-Emile Uberti-Ares
** Last update Sun May  7 16:50:27 2017 Lous-Emile Uberti-Ares
*/

#include <stdio.h>
#include "ftrace.h"
#include "graph.h"
#include "opcode.h"

_Bool			find_func_name(t_ftrace *ftrace,
				       const long addr)
{
  t_list		*tmp;

  tmp = ftrace->list;
  while (tmp)
    {
      if (tmp->addr == addr)
	{
	  dprintf(1, ENTERING, tmp->name, addr);
	  add_to_graph(ftrace->fd, ftrace->func, tmp->name, F_LINKED);
	  ftrace->func = tmp->name;
	  return (true);
	}
      tmp = tmp->next;
    }
  return (false);
}

void		is_func(t_ftrace *ftrace, const long rip)
{
  long		addr;
  int		offset;

  if (ftrace->opcode.addr[0] == CALLNEAR ||
      ftrace->opcode.addr[0] == CALLFAR)
    {
      offset = ftrace->opcode.val >> 8;
      if (offset < 0)
	{
	  offset = ~offset + 1;
	  addr = rip - (offset - 5);
	}
      else
	addr = rip + (offset + 5);
      if (find_func_name(ftrace, addr))
	ftrace->stack += 1;
    }
}

void		is_ret(t_ftrace *ftrace)
{
  if (ftrace->opcode.addr[0] == RET && ftrace->stack > 0)
    {
      dprintf(1, LEAVING, ftrace->func);
      ftrace->stack -= 1;
    }
}
