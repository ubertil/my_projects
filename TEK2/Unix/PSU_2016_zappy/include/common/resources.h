/*
** resources.h for zappy in /home/papadi_a/work/epitech/Tek2/PSU/PSU_2016_zappy/include/common
**
** Made by alexis papadimitriou
** Login   <papadi_a@epitech.net>
**
** Started on  Wed Jun 21 14:09:47 2017 alexis papadimitriou
** Last update Tue Jun 27 15:58:17 2017 grella_c
*/

#ifndef RESOURCES_H_
# define RESOURCES_H_

enum			e_item
  {
    LINEMATE = 0,
    DERAUMERE = 1,
    SIBUR = 2,
    MENDIANE = 3,
    PHIRAS = 4,
    THYSTAME = 5,
    FOOD = 6,
    NB_ITEM
  };

typedef struct		s_item
{
  enum e_item		index;
  char			*item;
}			t_item;

#endif /* !RESOURCES_H_ */
