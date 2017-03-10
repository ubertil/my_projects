/*
** nm.h for nm in /home/uberti_l/rendu/Unix/PSU_2016_nmobjdump/include
**
** Made by Lous-Emile Uberti-Ares
** Login   <uberti_l@epitech.net>
**
** Started on  Mon Feb 20 14:04:45 2017 Lous-Emile Uberti-Ares
** Last update Sun Feb 26 22:39:31 2017 Lous-Emile Uberti-Ares
*/

#ifndef NM_H_
# define NM_H_
# include "common.h"
# define NO_SYMBOL "nm: %s: no symbols\n"

# define NM_OUTPUT_64 "%016lx %c %s\n"
# define NM_DEFAULT_64 "                 %c %s\n"
# define NM_OUTPUT_32 "%08x %c %s\n"
# define NM_DEFAULT_32 "         %c %s\n"

# define STRTAB(data, shdr, i) (data + shdr[shdr[i].sh_link].sh_offset)
# define SYM_RET(bind, c) ((bind == STB_GLOBAL) ? (toupper(c)) : (c))

typedef struct	s_order
{
  const char	*str;
  void		*data;
  int		bytes;
}		t_order;

char		get_symbol(t_order *ptr, void *data);
_Bool		my_nm(const char *filename, _Bool display);
_Bool		ordered_display_32(Elf32_Sym *sym, const char *strtab,
				   unsigned int idx[3], void *data);
_Bool		ordered_display_64(Elf64_Sym *sym, const char *strtab,
				   unsigned int idx[3], void *data);

#endif /* !NM_H_ */
