/*
** get_sections.c for get_sections in /home/uberti_l/rendu/Unix/PSU_2016_nmobjdump
**
** Made by Lous-Emile Uberti-Ares
** Login   <uberti_l@epitech.net>
**
** Started on  Tue Feb 21 16:56:23 2017 Lous-Emile Uberti-Ares
** Last update Sun Feb 26 22:48:35 2017 Lous-Emile Uberti-Ares
*/

#include <ctype.h>
#include <stdio.h>
#include "objdump.h"

static void			show_hex(const unsigned char *str,
					 unsigned int idx,
					 unsigned int size)
{
  int				i;
  int				j;

  i = 0;
  j = 0;
  if (str == NULL)
    return ;
  while (i < 16 && i + idx < size)
    {
      j = 0;
      while (j < 4 && i + j + idx < size)
	{
	  printf("%02x", str[i + j + idx]);
	  ++j;
	}
      if (!(i % 4))
	printf(" ");
      i += j;
    }
  while (i < 16)
    ((i++ % 4) ? (printf("  ")) : (printf("   ")));
  printf(" ");
}

static void			show_str(const char *str,
					 unsigned int idx,
					 unsigned int size)
{
  int				i;

  i = 0;
  if (str == NULL)
    return ;
  while (i < 16 && i + idx < size)
    {
      (isprint(str[i + idx])) ? (printf("%c", str[i + idx])) : (printf("."));
      ++i;
    }
  while (i++ < 16)
    printf(" ");
  printf("\n");
}

_Bool				get_sections_32(void *data, Elf32_Ehdr *header,
						Elf32_Shdr *shdr,
						unsigned int nb_sections)
{
  unsigned int			j;
  unsigned int			i;
  unsigned int			width;

  i = 0;
  if (shdr == NULL)
    return (false);
  while (i++ < nb_sections - 1)
    {
      if (is_required_32(&shdr[i], &STR(data, shdr, header)[shdr[i].sh_name]))
	{
	  printf(SEC_CONTENT, &STR(data, shdr, header)[shdr[i].sh_name]);
	  j = 0;
	  width = get_width(shdr[i].sh_addr + shdr[i].sh_size - 16);
	  while (j < shdr[i].sh_size)
	    {
	      PRINT_OFF(shdr[i], width, j);
	      show_hex(data + shdr[i].sh_offset, j, shdr[i].sh_size);
	      show_str(data + shdr[i].sh_offset, j, shdr[i].sh_size);
	      j += 16;
	    }
	}
    }
  return (true);
}

_Bool				get_sections_64(void *data, Elf64_Ehdr *header,
						Elf64_Shdr *shdr,
						unsigned int nb_sections)
{
  unsigned int			j;
  unsigned int			i;
  unsigned int			width;

  i = 0;
  if (shdr == NULL)
    return (false);
  while (i++ < nb_sections - 1)
    {
      if (is_required_64(&shdr[i], &STR(data, shdr, header)[shdr[i].sh_name]))
	{
	  printf(SEC_CONTENT, &STR(data, shdr, header)[shdr[i].sh_name]);
	  j = 0;
	  width = get_width(shdr[i].sh_addr + shdr[i].sh_size - 16);
	  while (j < shdr[i].sh_size)
	    {
	      PRINT_OFF(shdr[i], width, j);
	      show_hex(data + shdr[i].sh_offset, j, shdr[i].sh_size);
	      show_str(data + shdr[i].sh_offset, j, shdr[i].sh_size);
	      j += 16;
	    }
	}
    }
  return (true);
}
