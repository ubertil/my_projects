/*
** directions.h for directions.h in /home/nicolas.trognot/rendu/Reseau/PSU_2016_zappy/include
**
** Made by Nicolas TROGNOT
** Login   <nicolas.trognot@epitech.net>
**
** Started on  Tue Jun 27 10:08:02 2017 Nicolas TROGNOT
** Last update Tue Jun 27 10:08:08 2017 Nicolas TROGNOT
*/

#ifndef DIRECTIONS_H_
# define DIRECTIONS_H_

enum			e_direction
  {
    NORTH = 0,
    EAST,
    SOUTH,
    WEST
  };

typedef struct		s_rotation
{
  enum e_direction	dir;
  int			tab[2];
}			t_rotation;

#endif /* !DIRECTIONS_H_ */
