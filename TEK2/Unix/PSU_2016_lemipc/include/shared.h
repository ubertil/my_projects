/*
** shared.h for PSU_2016_lemipc in /home/uberti_p/delivery/PSU_2016_lemipc/shared.h
**
** Made by Louis-Emile Uberti-Ares
** Login   <louis-emile.uberti-ares@epitech.eu>
**
** Started on  ven. mars 31 11:25:11 2017 Louis-Emile Uberti-Arès
** Last update Sun Apr  2 13:02:55 2017 Lous-Emile Uberti-Ares
*/

#ifndef SHARED_H_
# define SHARED_H_

# define USAGE "Usage : ./lemipc path_to_key team_number [--mode=]\n\
path_to_key is a valid path that will be used by ftok\n\
team_number is the team number assigned to the current player\n\
--mode={coward, random, default} defines the IA mode to be used\n"
# define GFX_USAGE "Usage : ./visualizer path_to_key\npath_to_key is a valid\
path that will be used by ftok"


# define ABS(x) ((x < 0) ? (-x) : (x))
# define MAP_X 10
# define MAP_Y 10
# define MAP_PATTERN (".%*c")
# define PADDING 4

# define SLEEP_FPS (200000)

typedef struct			s_shared
{
  int				nb_connected;
  int				map[MAP_Y][MAP_X];
}__attribute__((packed))	t_shared;

# define SHM_SIZE (sizeof(t_shared))

#endif /* !SHARED_H_ */
