/*
** errors.c for zappy in /home/papadi_a/work/epitech/Tek2/PSU/PSU_2016_zappy/src/utils
**
** Made by alexis papadimitriou
** Login   <papadi_a@epitech.net>
**
** Started on  Wed Jun 21 12:03:12 2017 alexis papadimitriou
** Last update Wed Jun 21 14:12:37 2017 alexis papadimitriou
*/

#include <stdio.h>
#include "common/utils/errors.h"

void	*p_error(const char *msg)
{
  dprintf(2, "%s\n", msg);
  return (NULL);
}

int32_t	d_error(const char *msg)
{
  dprintf(2, "%s\n", msg);
  return (ERROR_CODE);
}
