/*
** check_file.c for check_file in /home/grella_c/rendu/PSU_2016_ftrace
**
** Made by Côme Grellard
** Login   <grella_c@epitech.net>
**
** Started on  Sun May  7 14:44:30 2017 Côme Grellard
** Last update Sun May  7 14:44:31 2017 Côme Grellard
*/

#include "symbol_finder.h"

int		check_format(t_myelf *myelf)
{
  myelf->elf = (Elf64_Ehdr *)myelf->data;
  myelf->shdr = (Elf64_Shdr *)(myelf->data + myelf->elf->e_shoff);
  if (myelf->elf->e_ident[0] != ELFMAG0 ||
      myelf->elf->e_ident[1] != ELFMAG1 ||
      myelf->elf->e_ident[2] != ELFMAG2 ||
      myelf->elf->e_ident[3] != ELFMAG3)
    return (1);
  return (0);
}

int		check_size(int filesize, t_myelf *myelf)
{
  int		size;

  size = myelf->elf->e_shnum * myelf->elf->e_shentsize +
    myelf->elf->e_shoff;
  if (size != filesize)
    return (1);
  return (0);
}
