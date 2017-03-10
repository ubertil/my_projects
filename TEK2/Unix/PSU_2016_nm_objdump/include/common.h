/*
** common.h for common in /home/uberti_l/rendu/Unix/PSU_2016_nmobjdump/include
**
** Made by Lous-Emile Uberti-Ares
** Login   <uberti_l@epitech.net>
**
** Started on  Mon Feb 20 14:07:10 2017 Lous-Emile Uberti-Ares
** Last update Sun Feb 26 22:38:28 2017 Lous-Emile Uberti-Ares
*/

#ifndef COMMON_H_
# define COMMON_H_
# include <elf.h>
# include <stdbool.h>

# define NO_FILE "%s: '%s': No such file\n"
# define NOT_ORDINARY "%s: Warning: '%s' is not an ordinary file\n"
# define NOT_RECOGNIZED "%s: %s: File format not recognized\n"
# define TRUNCATED "%s: %s: File truncated\n"
# define NO_SYMBOLS "no symbols"
# define FILE_DEFAULT "a.out"

# define EHDR_64(x) ((Elf64_Ehdr *)(x))
# define SHDR_64(x) ((Elf64_Shdr *)(x))
# define SYM_64(x) ((Elf64_Sym *)(x))

# define EHDR_32(x) ((Elf32_Ehdr *)(x))
# define SHDR_32(x) ((Elf32_Shdr *)(x))
# define SYM_32(x) ((Elf32_Sym *)(x))

_Bool			open_file(const char *prog, const char *file,
				  void **data);

#endif /* !COMMON_H_ */
