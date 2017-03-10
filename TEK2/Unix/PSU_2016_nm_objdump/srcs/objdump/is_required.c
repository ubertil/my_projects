/*
** is_required.c for is_required in /home/uberti_l/rendu/Unix/PSU_2016_nmobjdump
**
** Made by Lous-Emile Uberti-Ares
** Login   <uberti_l@epitech.net>
**
** Started on  Sun Feb 26 01:45:55 2017 Lous-Emile Uberti-Ares
** Last update Sun Feb 26 22:37:34 2017 Lous-Emile Uberti-Ares
*/

#include <string.h>
#include "common.h"

_Bool		is_required_32(Elf32_Shdr *shdr,
			       const char *name)
{
  if ((strcmp(name, ".dynstr") == 0) || (strcmp(name, ".rel.dyn") == 0) ||
      (strcmp(name, ".rel.plt") == 0))
    return (true);
  if ((shdr->sh_size == 0) || (shdr->sh_type == SHT_REL) ||
      (shdr->sh_type == SHT_NOBITS) || (shdr->sh_type == SHT_SYMTAB) ||
      (shdr->sh_type == SHT_STRTAB) || (strcmp(name, ".rela.text") == 0) ||
      (strcmp(name, ".rela.eh_frame") == 0))
    return (false);
  else if (shdr->sh_flags & SHF_ALLOC)
    return (true);
  return (true);
}

_Bool		is_required_64(Elf64_Shdr *shdr,
			       const char *name)
{
  if ((strcmp(name, ".dynstr") == 0) || (strcmp(name, ".rel.dyn") == 0) ||
      (strcmp(name, ".rel.plt") == 0))
    return (true);
  if ((shdr->sh_size == 0) || (shdr->sh_type == SHT_REL) ||
      (shdr->sh_type == SHT_NOBITS) || (shdr->sh_type == SHT_SYMTAB) ||
      (shdr->sh_type == SHT_STRTAB) || (strcmp(name, ".rela.text") == 0) ||
      (strcmp(name, ".rela.eh_frame") == 0))
    return (false);
  else if (shdr->sh_flags & SHF_ALLOC)
    return (true);
  return (true);
}
