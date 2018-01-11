/*
** types.h for n in /home/uberti_l/rendu/Unix/PSU_2016_strace
**
** Made by Lous-Emile Uberti-Ares
** Login   <uberti_l@epitech.net>
**
** Started on  Wed Apr 12 21:08:01 2017 Lous-Emile Uberti-Ares
** Last update Thu Apr 13 23:41:25 2017 Lous-Emile Uberti-Ares
*/

#ifndef TYPES_H_
# define TYPES_H_
# include <stdlib.h>

# define INLINED __attribute__((gnu_inline)) inline

typedef enum	e_type
  {
    VOID = 0,
    INT,
    CHAR,
    SIZE_T,
    OFF_T,
  }		e_type;

typedef struct	s_func
{
  e_type	type;
  int		(*f)(const int, const size_t);
}		t_func;

INLINED int	print_void(const int pid, const size_t param);
INLINED int	print_int(const int pid, const size_t param);
INLINED int	print_char(const int pid, const size_t param);
INLINED int	print_size_t(const int pid, const size_t param);
INLINED int	print_off_t(const int pid, const size_t param);

#endif /* !TYPES_H_ */
