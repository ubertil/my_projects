/*
** get_flags.c for get_flags in /home/uberti_l/rendu/Unix/PSU_2016_nmobjdump
**
** Made by Lous-Emile Uberti-Ares
** Login   <uberti_l@epitech.net>
**
** Started on  Tue Feb 21 16:19:59 2017 Lous-Emile Uberti-Ares
** Last update Sun Feb 26 22:47:56 2017 Lous-Emile Uberti-Ares
*/

#include <stdio.h>
#include "flags.h"
#include "objdump.h"

static void		fill_flags(t_type *flags)
{
  flags[0].nb = HAS_RELOC;
  flags[1].nb = EXEC_P;
  flags[2].nb = HAS_SYMS;
  flags[3].nb = DYNAMIC;
  flags[4].nb = D_PAGED;
  flags[5].nb = BFD_NO_FLAGS;
  flags[0].replace = "HAS_RELOC";
  flags[1].replace = "EXEC_P";
  flags[2].replace = "HAS_SYMS";
  flags[3].replace = "DYNAMIC";
  flags[4].replace = "D_PAGED";
  flags[5].replace = NULL;
}

void			print_flags(unsigned int flags)
{
  t_type		replace[6];
  int			i;
  _Bool			no_comma;

  no_comma = true;
  i = -1;
  fill_flags(replace);
  while (++i < 6)
    {
      if (replace[i].nb & flags)
	{
	  if (!no_comma)
	    printf(", ");
	  printf("%s", replace[i].replace);
	  no_comma = false;
	}
    }
  printf("\n");
}

static unsigned int	get_flags_32bytes(Elf32_Ehdr *header,
					  Elf32_Shdr *shdr)
{
  unsigned int		i;
  unsigned int		flags;

  i = -1;
  flags = BFD_NO_FLAGS;
  while (++i < header->e_shnum)
    {
      if (shdr[i].sh_type == SHT_RELA)
	flags |= HAS_RELOC;
      if (shdr[i].sh_type == SHT_SYMTAB || shdr[i].sh_type == SHT_DYNSYM)
	flags |= HAS_SYMS;
    }
  if (header->e_type == ET_EXEC)
    flags = (flags & ~HAS_RELOC) | (EXEC_P | D_PAGED);
  if (header->e_type == ET_DYN)
    flags = (flags & ~HAS_RELOC) | (DYNAMIC | D_PAGED);
  return (flags);
}

static unsigned int	get_flags_64bytes(Elf64_Ehdr *header,
					  Elf64_Shdr *shdr)
{
  unsigned int		i;
  unsigned int		flags;

  i = -1;
  flags = BFD_NO_FLAGS;
  while (++i < header->e_shnum)
    {
      if (shdr[i].sh_type == SHT_RELA)
	flags |= HAS_RELOC;
      if (shdr[i].sh_type == SHT_SYMTAB || shdr[i].sh_type == SHT_DYNSYM)
	flags |= HAS_SYMS;
    }
  if (header->e_type == ET_EXEC)
    flags = (flags & ~HAS_RELOC) | (EXEC_P | D_PAGED);
  if (header->e_type == ET_DYN)
    flags = (flags & ~HAS_RELOC) | (DYNAMIC | D_PAGED);
  return (flags);
}

unsigned int		get_flags(void *data, int bytes)
{
  if (bytes == 64)
    return (get_flags_64bytes(EHDR_64(data),
			      SHDR_64(data + EHDR_64(data)->e_shoff)));
  else
    return (get_flags_32bytes(EHDR_32(data),
			      SHDR_32(data + EHDR_32(data)->e_shoff)));
}
