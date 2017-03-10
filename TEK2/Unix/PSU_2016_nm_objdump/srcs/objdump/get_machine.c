/*
** get_machine.c for get_machine in /home/uberti_l/rendu/Unix/PSU_2016_nmobjdump
**
** Made by Lous-Emile Uberti-Ares
** Login   <uberti_l@epitech.net>
**
** Started on  Thu Feb 23 00:02:45 2017 Lous-Emile Uberti-Ares
** Last update Sun Feb 26 21:55:33 2017 Lous-Emile Uberti-Ares
*/

#include "objdump.h"

static const t_type	machines[] =
  {
    {EM_NONE, "unknown"},
    {EM_M32, "m32"},
    {EM_SPARC, "sun sparc"},
    {EM_386, "i386"},
    {EM_68K, "m68k"},
    {EM_88K, "m88k"},
    {EM_860, "i860"},
    {EM_PARISC, "hppa"},
    {EM_SPARC32PLUS, "sparcplus"},
    {EM_PPC, "ppc"},
    {EM_PPC64, "pc64"},
    {EM_SPU, "cell BE SPU"},
    {EM_SH, "SuperH"},
    {EM_SPARCV9, "sparcv9"},
    {EM_X86_64, "x86-64"},
    {EM_IA_64, "ia64"},
    {0, (void *)0}
  };

const char	*get_machine(int id)
{
  int		i;

  i = -1;
  while (machines[++i].replace != (void *)0)
    if (id == machines[i].nb)
      return (machines[i].replace);
  return (machines[0].replace);
}
