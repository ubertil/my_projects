/*
** show_info2.c for show-info2 in /home/uberti_l/rendu/PSU_2015_my_ls
**
** Made by louis-emile uberti-ares
** Login   <uberti_l@epitech.net>
**
** Started on  Sun Nov 29 21:23:09 2015 louis-emile uberti-ares
** Last update Sun Nov 29 21:37:56 2015 louis-emile uberti-ares
*/

#include <sys/stat.h>
#include "include/my.h"

int		get_total(char *file)
{
  struct stat	sb;

  lstat(file, &sb);
  return (sb.st_blocks);
}
