/*
** symbol_finder.c for symbol_finder in /home/uberti_l/rendu/Unix/PSU_2016_ftrace
**
** Made by Lous-Emile Uberti-Ares
** Login   <uberti_l@epitech.net>
**
** Started on  Sun May  7 12:11:14 2017 Lous-Emile Uberti-Ares
** Last update Sun May  7 12:11:21 2017 Lous-Emile Uberti-Ares
*/

#include "symbol_finder.h"

t_list		*get_infos(t_myelf *myelf, Elf64_Sym *symtab, char *strtab)
{
  unsigned long	num;
  t_list	*list;

  list = NULL;
  num = 1;
  while (num < myelf->nb_sym)
    {
      if (symtab[num].st_info != STT_SECTION &&
	  symtab[num].st_info != STT_FILE)
	add_node(&list, symtab[num].st_value, &strtab[symtab[num].st_name]);
      num++;
    }
  return (list);
}

Elf64_Sym	*get_symtab(t_myelf *myelf)
{
  int		i;
  int		symtab_idx;
  Elf64_Sym	*symtab;

  i = 0;
  symtab_idx = -1;
  while (i < myelf->elf->e_shnum)
    {
      if (myelf->shdr[i].sh_type == SHT_SYMTAB)
	symtab_idx = i;
      i++;
    }
  if (symtab_idx == -1)
    return (NULL);
  symtab = (Elf64_Sym *)(myelf->data + myelf->shdr[symtab_idx].sh_offset);
  myelf->nb_sym = myelf->shdr[symtab_idx].sh_size /
    myelf->shdr[symtab_idx].sh_entsize;
  return (symtab);
}

int		get_strtab_idx(Elf64_Shdr *shdr, int shnum, char *strtab)
{
  int		i;

  i = 0;
  while (i < shnum)
    {
      if (strcmp(&strtab[shdr[i].sh_name], ".strtab") == 0)
	return (i);
      i++;
    }
  return (-1);
}

t_list		*find_it(t_myelf *myelf)
{
  char		*sections_names;
  int		strtab_idx;
  char		*strtab;
  Elf64_Sym	*symtab;

  sections_names =
    (char *)(myelf->data + myelf->shdr[myelf->elf->e_shstrndx].sh_offset);
  if ((strtab_idx =
       get_strtab_idx(myelf->shdr, myelf->elf->e_shnum, sections_names)) == -1)
    return (NULL);
  strtab = (char *)(myelf->data + myelf->shdr[strtab_idx].sh_offset);
  if ((symtab = get_symtab(myelf)) == NULL)
    return (NULL);
  return (get_infos(myelf, symtab, strtab));
}

t_list		*symbol_finder(const char *bin)
{
  t_myelf	myelf;
  int		fd;
  int		filesize;
  t_list	*list;

  list = NULL;
  myelf.file_name = strdup(bin);
  if ((fd = open(bin, O_RDONLY)) == -1)
    return (NULL);
  if (((filesize = lseek(fd, 0, SEEK_END)) == -1) ||
      ((myelf.data = mmap(NULL, filesize, PROT_READ, MAP_SHARED, fd, 0))
       == MAP_FAILED))
    return (NULL);
  if (check_format(&myelf) == 1 ||
      check_size(filesize, &myelf) == 1)
    return (NULL);
  close(fd);
  if ((list = find_it(&myelf)) == NULL)
    return (NULL);
  return (list);
}
