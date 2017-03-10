/*
** objdump.h for objdump in /home/uberti_l/rendu/Unix/PSU_2016_nmobjdump/include
**
** Made by Lous-Emile Uberti-Ares
** Login   <uberti_l@epitech.net>
**
** Started on  Mon Feb 20 14:11:26 2017 Lous-Emile Uberti-Ares
** Last update Sun Feb 26 22:40:05 2017 Lous-Emile Uberti-Ares
*/

#ifndef OBJDUMP_H_
# define OBJDUMP_H_
# include "common.h"

# define HEAD "%s:     file format %s-%s\narchitecture:%s%s, flags 0x%08x:\n"
# define SEC_CONTENT "Contents of section %s:\n"
# define START_ADDR "start address 0x%0*lx\n\n"

# define ELF32 "elf32"
# define ELF64 "elf64"
# define I386 " i386:"
# define UNKNOWN "unknown class"

# define STR(x, y, z) ((char *)(x + y[z->e_shstrndx].sh_offset))
# define PRINT_OFF(x, y, z) (printf(" %0*x ", y, (int)(x.sh_addr + z)))

typedef struct	s_type
{
  int		nb;
  const char	*replace;
}		t_type;

unsigned int	get_width(unsigned long nb);
unsigned int	get_flags(void *data, int bytes);
_Bool		is_required_32(Elf32_Shdr *shdr, const char *name);
_Bool		is_required_64(Elf64_Shdr *shdr, const char *name);
_Bool		my_objdump(const char *str);
_Bool		get_sections_64(void *data, Elf64_Ehdr *header,
				Elf64_Shdr *shdr, unsigned int nb_sections);
_Bool		get_sections_32(void *data, Elf32_Ehdr *header,
				Elf32_Shdr *shdr, unsigned int nb_sections);
void		print_flags(unsigned int flags);
const char	*get_machine(int id);

#endif /* !OBJDUMP_H_ */
