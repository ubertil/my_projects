/*
** my_objdump.c for my_objdump in /home/uberti_l/rendu/Unix/PSU_2016_nmobjdump
**
** Made by Lous-Emile Uberti-Ares
** Login   <uberti_l@epitech.net>
**
** Started on  Mon Feb 20 16:08:17 2017 Lous-Emile Uberti-Ares
** Last update Sun Feb 26 21:58:00 2017 Lous-Emile Uberti-Ares
*/

#include <stdio.h>
#include "objdump.h"

static const char		*get_spec(int class)
{
  if (class == ELFCLASS32)
    return (ELF32);
  else if (class == ELFCLASS64)
    return (ELF64);
  else
    return (UNKNOWN);
}

static _Bool			show_header(void *data, const char *file)
{
  Elf64_Ehdr			*elf;
  unsigned int			width;
  unsigned int			bytes;
  unsigned int			flags;

  elf = EHDR_64(data);
  bytes = ((elf->e_ident[EI_CLASS] == ELFCLASS32) ? (32) : (64));
  width = ((bytes == 64) ? (16) : (8));
  flags = get_flags(data, bytes);
  printf("\n");
  printf(HEAD, file, get_spec(elf->e_ident[EI_CLASS]),
	 get_machine((bytes == 64) ? (elf->e_machine) :
		     (EHDR_32(data)->e_machine)),
	 (bytes == 64 && elf->e_flags == 0) ? (I386) : (" "),
	 get_machine((bytes == 64) ? (elf->e_machine) :
		     (EHDR_32(data)->e_machine)), flags);
  print_flags(flags);
  printf(START_ADDR, width, (bytes == 64) ? (elf->e_entry) :
	 (EHDR_32(data)->e_entry));
  return ((bytes == 64) ?
	(get_sections_64(data, elf,
			 SHDR_64(data + elf->e_shoff), elf->e_shnum)) :
	  (get_sections_32(data, EHDR_32(data),
			   SHDR_32(data + EHDR_32(data)->e_shoff),
			   EHDR_32(data)->e_shnum)));
}

_Bool		my_objdump(const char *file)
{
  void		*data;

  if ((open_file("objdump", file, &data)) == false)
    return (false);
  return (show_header(data, file));
}
