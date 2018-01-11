/*
** ia.h for ia in /home/uberti_l/rendu/Unix/PSU_2016_zappy
**
** Made by Lous-Emile Uberti-Ares
** Login   <uberti_l@epitech.net>
**
** Started on  Tue Jun 27 11:09:55 2017 Lous-Emile Uberti-Ares
** Last update Sun Jul  2 19:38:04 2017 grella_c
*/

#ifndef IA_H_
# define IA_H_
# define MAX_IA_ACTIONS 15
# define MIN_FOOD 300
# include <stdbool.h>
# include "client/direction.h"

typedef struct	s_client t_client;

enum		e_role
  {
    HERO = 0,
    COLLECTER
  };

enum		e_ia_action
  {
    ENOUGH_FOOD = 0,
    NB_STONES = 1,
    NB_PLAYERS = 2,
    INCANTATION = 3,
    CALL_REINFORCEMENT = 4,
    TEAM_MSG = 5,
    REACHED_DESTINATION = 6,
    FOOD_ON_TILE = 7,
    GO_TO_FOOD = 8,
    TAKE_FOOD = 9,
    GO_TO_TEAMMATE = 10,
    TAKE_STONE = 11,
    STONE_ON_TILE = 12,
    GO_TO_STONE= 13,
    SET_STONES = 14
  };

typedef struct		s_ia
{
  char			*input;
  t_destination		*target;
  bool			(*func[MAX_IA_ACTIONS])(t_client *client,
						const char *cmd);
  enum e_role		role;
  enum e_ia_action	current;
}			t_ia;

/*
** Functions
*/

t_ia		*init_ia(void);
void		free_ia(t_ia *ia);
char		*get_command(t_client *client, bool (*func)(t_client *client));
bool		enough_food(t_client *client, const char *cmd);
bool		nb_stones(t_client *client, const char *cmd);
bool		nb_players(t_client *client, const char *cmd);
bool		incantation(t_client *client, const char *cmd);
bool		call_reinforcement(t_client *client, const char *cmd);
bool		team_msg(t_client *client, const char *cmd);
bool		reached_destination(t_client *client, const char *cmd);
bool		food_on_tile(t_client *client, const char *cmd);
bool		go_to_food(t_client *client, const char *cmd);
bool		take_food(t_client *client, const char *cmd);
bool		go_to_teammate(t_client *client, const char *cmd);
bool		take_stone(t_client *client, const char *cmd);
bool		stone_on_tile(t_client *client, const char *cmd);
bool		go_to_stone(t_client *client, const char *cmd);
bool		set_stones(t_client *client, const char *cmd);

#endif /* !IA_H_ */
