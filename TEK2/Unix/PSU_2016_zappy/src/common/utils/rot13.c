/*
** rot13.c for rot in /home/uberti_l/rendu/Unix/PSU_2016_zappy
**
** Made by Lous-Emile Uberti-Ares
** Login   <uberti_l@epitech.net>
**
** Started on  Tue Jun 27 14:23:50 2017 Lous-Emile Uberti-Ares
** Last update Tue Jun 27 14:25:38 2017 Lous-Emile Uberti-Ares
*/

#include "common/utils/utils.h"

INLINE int	rot13(const int nb)
{
  return (((0x0000FFFF & nb) << 16) + ((0xFFFF0000 & nb) >> 16));
}
