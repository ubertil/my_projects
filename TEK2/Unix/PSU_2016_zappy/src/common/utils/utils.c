/*
** utils.c for zappy in /home/papadi_a/work/epitech/Tek2/PSU/PSU_2016_zappy/include/client
**
** Made by alexis papadimitriou
** Login   <papadi_a@epitech.net>
**
** Started on  Wed Jun 21 11:48:02 2017 alexis papadimitriou
** Last update Tue Jun 27 16:37:37 2017 grella_c
*/

#include <unistd.h>
#include "common/utils/utils.h"

void		secure_write(int fd, const void *buff, size_t count)
{
  size_t	len;

  len = count;
  while (count > 0)
    count = len - write(fd, buff + (len - count), count);
}

uint32_t	tab_len(char **tab)
{
  uint32_t	len;

  if (!tab)
    return (0);
  len = 0;
  while (tab[len])
    len += 1;
  return (len);
}
