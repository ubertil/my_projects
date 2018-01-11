/*
** modes.h.h for PSU_2016_lemipc in /home/uberti_p/delivery/PSU_2016_lemipc/modes.h.h
**
** Made by Louis-Emile Uberti-Ares
** Login   <louis-emile.uberti-ares@epitech.eu>
**
** Started on  jeu. mars 30 13:15:08 2017 Louis-Emile Uberti-Arès
** Last update Sun Apr  2 14:55:01 2017 Lous-Emile Uberti-Ares
*/

#ifndef MODES_H_
# define MODES_H_

# define IA_MODE "IA mode selected : %s\n"

typedef struct s_team	t_team;

typedef struct		s_modes
{
  char			*str;
  int			(*f)(t_team *);
}			t_modes;

int			can_start(const t_team *);
int			mode_target(t_team *);
int			mode_random(t_team *);

#endif /* !MODES_H_ */
