/*
** protected.c for protected.c in /home/trognot/rendu/IA/dante/generateur
**
** Made by nicolas trognot
** Login   <nicolas.trognot@epitech.eu>
**
** Started on  Wed May 18 13:53:16 2016 nicolas trognot
** Last update Wed May 18 13:53:16 2016 nicolas trognot
*/

#include "generateur.h"

void		set_maze_protected(t_maze *maze, int y, int x, int val)
{
  if (x >= 0 && y >= 0 && x < maze->w && y < maze->h)
    maze->cells[y][x] = val;
}
