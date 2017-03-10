/*
** flags.h for flags in /home/uberti_l/rendu/Unix/PSU_2016_nmobjdump
**
** Made by Lous-Emile Uberti-Ares
** Login   <uberti_l@epitech.net>
**
** Started on  Fri Feb 24 17:08:21 2017 Lous-Emile Uberti-Ares
** Last update Sun Feb 26 22:39:13 2017 Lous-Emile Uberti-Ares
*/

#ifndef BFD_H_SEEN_
# define BFD_H_SEEN_

# define BFD_NO_FLAGS	0x00
# define HAS_RELOC	0x01
# define EXEC_P		0x02
# define HAS_LINENO	0x04
# define HAS_DEBUG	0x08
# define HAS_SYMS	0x10
# define HAS_LOCALS	0x20
# define DYNAMIC	0x40
# define WP_TEXT	0x80
# define D_PAGED	0x100

#endif /* !BFD_H_SEEN_ */
