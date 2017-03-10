/*
** my_nm.c for my_nm in /home/uberti_l/rendu/Unix/PSU_2016_nmobjdump
**
** Made by Lous-Emile Uberti-Ares
** Login   <uberti_l@epitech.net>
**
** Started on  Mon Feb 20 15:48:08 2017 Lous-Emile Uberti-Ares
** Last update Sun Feb 26 22:46:25 2017 Lous-Emile Uberti-Ares
*/

#include <stdio.h>
#include "nm.h"

static _Bool		do_nm_32(void *data, Elf32_Ehdr *header,
				 Elf32_Shdr *shdr, const char *file)
{
  unsigned int		idx[3];
  Elf32_Sym		*sym;
  char			*strtab;

  idx[0] = 0;
  idx[2] = 32;
  while (idx[0] < (unsigned)header->e_shnum &&
	 shdr[idx[0]].sh_type != SHT_SYMTAB)
    ++idx[0];
  if (shdr[idx[0]].sh_type != SHT_SYMTAB)
    {
      dprintf(2, NO_SYMBOL, file);
      return (true);
    }
  sym = SYM_32(data + shdr[idx[0]].sh_offset);
  idx[1] = shdr[idx[0]].sh_size / shdr[idx[0]].sh_entsize;
  strtab = STRTAB(data, shdr, idx[0]);
  if (strtab == NULL)
    return (false);
  return (ordered_display_32(sym, strtab, idx, data));
}

static _Bool		do_nm_64(void *data, Elf64_Ehdr *header,
				 Elf64_Shdr *shdr, const char *file)
{
  unsigned int		idx[3];
  char			*strtab;
  Elf64_Sym		*sym;

  idx[0] = 0;
  idx[2] = 64;
  while (idx[0] < (unsigned)header->e_shnum &&
	 shdr[idx[0]].sh_type != SHT_SYMTAB)
    ++idx[0];
  if (shdr[idx[0]].sh_type != SHT_SYMTAB)
    {
      dprintf(2, NO_SYMBOL, file);
      return (true);
    }
  sym = SYM_64(data + shdr[idx[0]].sh_offset);
  idx[1] = shdr[idx[0]].sh_size / shdr[idx[0]].sh_entsize;
  strtab = STRTAB(data, shdr, idx[0]);
  if (strtab == NULL)
    return (false);
  return (ordered_display_64(sym, strtab, idx, data));
}

_Bool		my_nm(const char *file, _Bool display)
{
  void		*data;
  Elf64_Ehdr	*elf;

  elf = NULL;
  if (((open_file("nm", file, &data)) == false) || (EHDR_64(data) == NULL))
    return (false);
  if (display)
    printf("\n%s:\n", file);
  elf = EHDR_64(data);
  if (elf->e_ident[EI_CLASS] == ELFCLASS64)
    return (do_nm_64(data, EHDR_64(data),
		     SHDR_64(data + EHDR_64(data)->e_shoff), file));
  else if (elf->e_ident[EI_CLASS] == ELFCLASS32)
    return (do_nm_32(data, EHDR_32(data),
		     SHDR_32(data + EHDR_32(data)->e_shoff), file));
  else
    return (false);
}
