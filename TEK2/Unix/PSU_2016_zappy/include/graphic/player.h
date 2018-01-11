/*
** player.h for zappy in /home/papadi_a/work/epitech/Tek2/PSU/PSU_2016_zappy
**
** Made by alexis papadimitriou
** Login   <papadi_a@epitech.net>
**
** Started on  Wed Jun 28 14:38:41 2017 alexis papadimitriou
** Last update Sun Jul  2 19:41:31 2017 grella_c
*/

#ifndef PLAYER_H_
# define PLAYER_H_
# define PLAYER_UP_TEXT "resources/player_up.png"
# define PLAYER_DOWN_TEXT "resources/player_down.png"
# define PLAYER_LEFT_TEXT "resources/player_left.png"
# define PLAYER_RIGHT_TEXT "resources/player_right.png"
# define PLAYER_SIZE MAP_SIZE / (m_size * 1.5)
# define PLAYER_NB_TEXT 4
# include <stdint.h>
# include <stdbool.h>
# include <SDL/SDL.h>
# include "drawing.h"
# include "common/directions.h"
# include "common/resources.h"

typedef struct		s_team_name
{
  char			*name;
  struct s_team_name	*next;
}			t_team_name;

typedef struct		s_player
{
  int32_t		id;
  t_pos			pos;
  enum e_direction	dir;
  uint32_t		inventory[NB_ITEM];
  uint8_t		level;
  char			*team;
  struct s_player	*next;
}			t_player;

typedef struct		s_plist
{
  t_team_name		*team_name;
  t_player		*head;
  SDL_Surface		*player_texture[PLAYER_NB_TEXT];
}			t_plist;

t_plist			*init_plist();
void			free_plist(t_plist *list);
void			push(t_plist *list, t_player *player);
t_player		*get_from_id(t_plist *list, int32_t id);
void			remove_player(t_plist *list, t_player *player);
bool			add_team_name(t_plist *list, char *name);
t_player		*init_player(int32_t x, int32_t y);
void			free_player(t_player *player);
void			render_player(SDL_Surface *pix, t_plist *list,
				      uint32_t width, uint32_t heihgt);
void			set_player_id(int32_t *collision_buf, t_plist *list,
				      uint32_t width, uint32_t height);

#endif /* !PLAYER_H_ */
