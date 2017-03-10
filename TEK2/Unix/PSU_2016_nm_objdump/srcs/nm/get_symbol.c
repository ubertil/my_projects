/*
** get_symbol.c for get_symbol in /home/uberti_l/rendu/Unix/PSU_2016_nmobjdump
**
** Made by Lous-Emile Uberti-Ares
** Login   <uberti_l@epitech.net>
**
** Started on  Sat Feb 25 14:36:16 2017 Lous-Emile Uberti-Ares
** Last update Sun Feb 26 22:44:52 2017 Lous-Emile Uberti-Ares
*/

#include <ctype.h>
#include "nm.h"

static char	sec_flags(unsigned long sh_flags, unsigned long sh_type,
			  int bind)
{
  if (sh_type == SHT_NOBITS && sh_flags == (SHF_ALLOC | SHF_WRITE))
    return (SYM_RET(bind, 'b'));
  if (sh_type == SHT_PROGBITS && sh_flags == SHF_ALLOC)
    return (SYM_RET(bind, 'r'));
  if (sh_type == SHT_PROGBITS && sh_flags == (SHF_ALLOC | SHF_WRITE))
    return (SYM_RET(bind, 'd'));
  if (sh_type == SHT_PROGBITS && sh_flags == (SHF_ALLOC | SHF_EXECINSTR))
    return (SYM_RET(bind, 't'));
  else if (sh_type == SHT_DYNAMIC)
    return (SYM_RET(bind, 'd'));
  return (((int)sh_type >= 14 && (int)sh_type <= 20) ?
	  (SYM_RET(bind, 't')) : ('?'));
}

static char	check_symbol(int shndx, int type, int bind)
{
  char		c;

  c = '?';
  c = ((shndx == SHN_ABS) ? ('a') : (c));
  c = ((shndx == SHN_COMMON) ? ('C') : (c));
  c = ((bind == STB_GNU_UNIQUE) ? ('u') : (c));
  if (c != '?')
    return (SYM_RET(bind, c));
  if (shndx == SHN_UNDEF)
    {
      if (bind == STB_WEAK && type == STT_OBJECT)
	return (SYM_RET(bind, 'v'));
      else if (bind == STB_WEAK)
	return (SYM_RET(bind, 'w'));
      else
	return ('U');
    }
  c = ((bind == STB_WEAK) ? ((type == STT_OBJECT) ? ('V') : ('W')) : (c));
  return (c);
}

char		get_symbol(t_order *ptr, void *data)
{
  char		c;
  int		idx;

  if (ptr->bytes == 64)
    {
      idx = SYM_64(ptr->data)->st_shndx;
      c = check_symbol(idx, ELF64_ST_TYPE(SYM_64(ptr->data)->st_info),
		       ELF64_ST_BIND(SYM_64(ptr->data)->st_info));
      if (c == '?')
	return (sec_flags(SHDR_64(data + EHDR_64(data)->e_shoff)[idx].sh_flags,
			  SHDR_64(data + EHDR_64(data)->e_shoff)[idx].sh_type,
			  ELF64_ST_BIND(SYM_64(ptr->data)->st_info)));
    }
  else
    {
      idx = SYM_32(ptr->data)->st_shndx;
      c = check_symbol(idx, ELF32_ST_TYPE(SYM_32(ptr->data)->st_info),
		       ELF32_ST_BIND(SYM_32(ptr->data)->st_info));
      if (c == '?')
	return (sec_flags(SHDR_32(data + EHDR_32(data)->e_shoff)[idx].sh_flags,
			  SHDR_32(data + EHDR_32(data)->e_shoff)[idx].sh_type,
			  ELF32_ST_BIND(SYM_32(ptr->data)->st_info)));
    }
  return (c);
}
