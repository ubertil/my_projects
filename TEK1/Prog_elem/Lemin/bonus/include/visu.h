/*
** visu.h for visu in /home/uberti_l/rendu/Prog_elem/CPE_2015_Lemin/bonus
**
** Made by louis-emile uberti-ares
** Login   <uberti_l@epitech.net>
**
** Started on  Wed Apr 20 15:23:44 2016 louis-emile uberti-ares
** Last update Sun Apr 24 13:06:23 2016 louis-emile uberti-ares
*/

#ifndef VISU_H_
# define VISU_H_
# define HEIGHT (800)
# define WIDTH (800)
# define POS (pos->x + (pos->y * pix->clipable.buffer.width))
# include <lapin.h>

/*
** STRUCTURES
*/

typedef struct		s_link
{
  char			*s1;
  char			*s2;
  struct s_link		*next;
}			t_link;

typedef struct		s_pos
{
  t_bunny_position	posxy;
  int			nb;
  char			*room_name;
  struct s_pos		*next;
}			t_pos;

typedef struct		s_ants
{
  t_bunny_position	current;
  t_bunny_position	dest;
  t_bunny_position	*way;
  int			idx;
  int			len;
}			t_ants;

typedef struct		s_visu
{
  t_bunny_window	*win;
  t_bunny_pixelarray	*pix;
  t_bunny_pixelarray	*ant;
  t_bunny_pixelarray	*screen;
  t_bunny_pixelarray	*room;
  t_bunny_pixelarray	*room_end;
  t_bunny_music		*lemin;
  t_pos			*rooms;
  t_link		*link;
  t_ants		*ants;
  int			start_rendu;
  int			err_after_start_end;
  int			nb_ants;
  int			who;
  int			started;
  int			ended;
  char			*mem;
}			t_visu;

/*
** FUNCTIONS
*/

void			my_putstr(char *str);
void			make_ants_move(t_visu *visu);
void			free_all(t_visu *visu);
void			free_args(char **tab);
void			show_all_rooms(t_visu *visu);
void			show_all_links(t_visu *visu);
void			set_background(t_bunny_pixelarray *pix,
				       unsigned int color);
void			tekpixel(t_bunny_pixelarray *pix,
				 t_bunny_position *pos,
				 unsigned int color);
void			tekpixel_alpha(t_bunny_pixelarray *pix,
				       t_bunny_position *pos,
				       t_color *color);
void			blit_alpha(t_bunny_pixelarray *dest,
				   t_bunny_pixelarray *src,
				   t_bunny_position *pos);
void			tekline(t_bunny_pixelarray *pix,
				t_bunny_position *pos,
				unsigned int color);
void			tekcircle(t_bunny_pixelarray *pix,
				  t_bunny_position *pos,
				  double radius,
				  unsigned int color);
int			load_ant(t_visu *visu, char *str);
int			load_screen(t_visu *visu, char *str);
int			check_args(t_visu *visu);
int			my_strlen(char *str);
int			recup_list(t_visu *visu);
int			get_all_rooms(t_visu *visu);
int			my_getnbr(char *str);
int			my_hard_getnbr(char *str);
int			find_room(t_pos *rooms, char *str);
int			put_room_in_list(t_visu *visu, char *str, int mode);
int			add_link(t_visu *visu, char *str);
int			recup_links(t_visu *visu);
int			my_strcmp(char *s1, char *s2);
int			get_nbr_ants(t_visu *visu);
int			check_link(char *str);
int			check_room(char *str, t_pos *rooms);
int			start_music(t_visu *visu, char *str);
int			close_music(t_visu *visu);
int			move_all_ants(t_visu *visu);
int			init_ant_struct(t_visu *visu);
int			get_ant_positions(t_visu *visu, char *move);
int			tekant(t_visu *visu, t_bunny_position *pos, int i);
float			get_pente(t_bunny_position *pos);
char			*get_first_room(char *str);
char			*get_second_room(char *str);
char			*my_strdup(char *str);
char			*get_next_line(const int fd);
char			**my_str_to_wordtab(char *str);
char			*get_next_room(char *str);
t_pos			*reverse_rooms(t_pos *root);
t_link			*reverse_links(t_link *root);
t_bunny_position	get_first_position(t_visu *visu, char *s1);
t_color			get_pixel(t_bunny_pixelarray *pix,
				  t_bunny_position *pos);

#endif /* !VISU_H_ */
