/*
** symbol_finder.h for symbol_finder in /home/uberti_l/rendu/Unix/PSU_2016_ftrace
**
** Made by Lous-Emile Uberti-Ares
** Login   <uberti_l@epitech.net>
**
** Started on  Sun May  7 12:11:33 2017 Lous-Emile Uberti-Ares
** Last update Sun May  7 14:49:37 2017 Côme Grellard
*/

#ifndef SYMBOL_FINDER_H_
# define SYMBOL_FINDER_H_
# include <stdio.h>
# include <fcntl.h>
# include <sys/types.h>
# include <sys/mman.h>
# include <unistd.h>
# include <elf.h>
# include <string.h>
# include <stdlib.h>
# include <ctype.h>

typedef struct		s_myelf
{
  char			*file_name;
  void			*data;
  Elf64_Ehdr		*elf;
  Elf64_Shdr		*shdr;
  unsigned long		nb_sym;
}			t_myelf;

typedef struct		s_list
{
  long			addr;
  char			*name;
  struct s_list		*next;
}			t_list;

int			add_node(t_list **list, const long addr,
				 const char *name);
int			check_format(t_myelf *myelf);
int			check_size(int filesize, t_myelf *myelf);
t_list			*symbol_finder(const char *bin);

#endif /* !SYMBOL_FINDER_H_ */
