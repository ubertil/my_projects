/*
** organize.c for organize in /home/uberti_l/rendu/Unix/PSU_2016_nmobjdump
**
** Made by Lous-Emile Uberti-Ares
** Login   <uberti_l@epitech.net>
**
** Started on  Sun Feb 26 02:22:07 2017 Lous-Emile Uberti-Ares
** Last update Sun Feb 26 22:47:28 2017 Lous-Emile Uberti-Ares
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "nm.h"

static int		compare(const void *a, const void *b)
{
  const t_order		*fir;
  const t_order		*sec;
  int			i;
  int			j;

  fir = a;
  sec = b;
  i = 0;
  j = 0;
  while (fir->str[i] != '\0' && sec->str[j] != '\0')
    {
      while (fir->str[i] != '\0' && !isalnum(fir->str[i]))
	++i;
      while (sec->str[j] != '\0' && !isalnum(sec->str[j]))
	++j;
      if (tolower(fir->str[i]) != tolower(sec->str[j]))
	return ((tolower(fir->str[i]) > tolower(sec->str[j])) ? (1) : (-1));
      ++i;
      ++j;
    }
  if (fir->str[i] == sec->str[j])
    return (1);
  return ((tolower(fir->str[i]) > tolower(sec->str[j])) ? (1) : (-1));
}

static void		display_content(t_order *ptr, void *data)
{
  char			c;

  c = get_symbol(ptr, data);
  if (ptr->str[0] != '\0' && ptr->bytes == 64)
    {
      ((SYM_64(ptr->data)->st_value != 0 ||
	(SYM_64(ptr->data)->st_value == 0 && c == 'T')) ?
       (printf(NM_OUTPUT_64, (c == 'T' && SYM_64(ptr->data)->st_value == 0) ?
	       (0) : SYM_64(ptr->data)->st_value,
	       c, ptr->str)) : (printf(NM_DEFAULT_64, c, ptr->str)));
    }
  else if (ptr->str[0] != '\0' && ptr->bytes == 32)
    {
      ((SYM_32(ptr->data)->st_value != 0 ||
	(SYM_32(ptr->data)->st_value == 0 && c == 'T')) ?
       (printf(NM_OUTPUT_32, (c == 'T' && SYM_32(ptr->data)->st_value == 0) ?
	       (0) : SYM_32(ptr->data)->st_value, c, ptr->str)) :
       (printf(NM_DEFAULT_32, c, ptr->str)));
    }
}

_Bool			ordered_display_64(Elf64_Sym *sym, const char *strtab,
					   unsigned int idx[3], void *data)
{
  t_order		ordered[idx[1]];
  unsigned int		i;

  i = -1;
  while (++i < idx[1])
    {
      ordered[i].data = &sym[i];
      ordered[i].bytes = idx[2];
      if (sym[i].st_name != 0 && sym[i].st_info != STT_FILE &&
	  sym[i].st_info != STT_SECTION)
	ordered[i].str = &strtab[sym[i].st_name];
      else
	ordered[i].str = "";
    }
  i = -1;
  qsort(ordered, sizeof(ordered) / sizeof(*ordered), sizeof(*ordered),
	compare);
  while (++i < idx[1])
    display_content(&ordered[i], data);
  return (true);
}

_Bool			ordered_display_32(Elf32_Sym *sym, const char *strtab,
					   unsigned int idx[3], void *data)
{
  t_order		ordered[idx[1]];
  unsigned int		i;

  i = -1;
  while (++i < idx[1])
    {
      ordered[i].data = &sym[i];
      ordered[i].bytes = idx[2];
      if (sym[i].st_name != 0 && sym[i].st_info != STT_FILE &&
	  sym[i].st_info != STT_SECTION)
	ordered[i].str = &strtab[sym[i].st_name];
      else
	ordered[i].str = "";
    }
  i = -1;
  qsort(ordered, sizeof(ordered) / sizeof(*ordered), sizeof(*ordered),
	compare);
  while (++i < idx[1])
    display_content(&ordered[i], data);
  return (true);
}
