/*
** open_file.c for open_file in /home/uberti_l/rendu/Unix/PSU_2016_nmobjdump
**
** Made by Lous-Emile Uberti-Ares
** Login   <uberti_l@epitech.net>
**
** Started on  Mon Feb 20 15:09:56 2017 Lous-Emile Uberti-Ares
** Last update Sun Feb 26 22:43:54 2017 Lous-Emile Uberti-Ares
*/

#include <fcntl.h>
#include <sys/stat.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/mman.h>
#include "common.h"

static int		is_dir(const char *prog, const char *file)
 {
  struct stat		test;

  if (stat(file, &test) != 0)
    return (1);
  if (!S_ISREG(test.st_mode))
    {
      dprintf(2, NOT_ORDINARY, prog, file);
      return (true);
    }
  return (false);
}

static inline int	filesize(int fd)
{
  return (lseek(fd, 0L, SEEK_END));
}

static inline _Bool	check_size_32bytes(const char *prog, const char *file,
					   unsigned int size,
					   Elf32_Ehdr *header)
{
  if (header->e_shoff + (header->e_shentsize * header->e_shnum) > size)
    {
      dprintf(2, TRUNCATED, prog, file);
      return (false);
    }
  return (true);
}

static _Bool		is_valid(const char *prog, const char *file,
				 unsigned int size, void *data)
{
  Elf64_Ehdr		*header;

  header = EHDR_64(data);
  if (header == NULL)
    return (false);
  if (header->e_ident[0] != ELFMAG0 || header->e_ident[1] != ELFMAG1 ||
      header->e_ident[2] != ELFMAG2 || header->e_ident[3] != ELFMAG3 ||
      (header->e_ident[EI_CLASS] != ELFCLASS32 &&
       header->e_ident[EI_CLASS] != ELFCLASS64))
    {
      dprintf(2, NOT_RECOGNIZED, prog, file);
      return (false);
    }
  if (header->e_ident[EI_CLASS] == ELFCLASS32)
    return (check_size_32bytes(prog, file, size, EHDR_32(data)));
  else if (header->e_shoff + (header->e_shentsize * header->e_shnum) > size)
    {
      dprintf(2, TRUNCATED, prog, file);
      return (false);
    }
  return (true);
}

_Bool			open_file(const char *prog, const char *file,
				  void **data)
{
  int			fd;

  if ((fd = open(file, O_RDONLY)) == -1)
    {
      dprintf(2, NO_FILE, prog, file);
      return (false);
    }
  if ((is_dir(prog, file)) ||
      (*data = mmap(NULL, filesize(fd), PROT_READ,
		    MAP_SHARED, fd, 0)) == MAP_FAILED)
    return (false);
  if (!is_valid(prog, file, filesize(fd), *data))
    return (false);
  close(fd);
  return (true);
}
