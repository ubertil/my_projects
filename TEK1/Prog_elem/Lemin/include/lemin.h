/*
** lemin.h for lemin in /home/uberti_l/rendu/Prog_elem/CPE_2015_Lemin
**
** Made by louis-emile uberti-ares
** Login   <uberti_l@epitech.net>
**
** Started on  Thu Apr  7 11:02:12 2016 louis-emile uberti-ares
** Last update Sun Apr 24 15:26:10 2016 nicolas trognot
*/

#ifndef LEMIN_H_
# define LEMIN_H_

/*
** STRUCTURES
*/

typedef struct		s_rooms
{
  int			nb;
  int			pos[2];
  char			*room_name;
  char			has_been_visited;
  struct s_rooms	*next;
}			t_rooms;

typedef struct		s_path_list
{
  int			is_ok;
  int			nb_idx;
  int			*idx_list;
  int			*idx_ants_list;
  struct s_path_list	*next;
}			t_path_list;

typedef struct		s_lemin
{
  int			**matrix;
  char			**names;
  char			*line;
  int			nb_ants;
  int			nb_ants_start;
  int			nb_ants_end;
  int			got_matrix;
  int			who;
  int			started;
  int			ended;
  int			nb_rooms;
  int			err_after_start_end;
  t_rooms		*rooms;
  t_path_list		*list;
}			t_lemin;

/*
** TOOLS
*/

void		my_putnbr(int nbr);
void		my_puterr(char *str);
void		free_args(char **tab);
void		my_putstr(char *str);
int		my_strlen(char *str);
int		isnbr(char *str);
int		my_hard_getnbr(char *str);
int		my_strcmp(char *s1, char *s2);
char		*get_next_line(const int fd);
char		*my_strdup(char *str);
char		**my_str_to_wordtab(char *str);

/*
** FUNCTIONS
*/

void		free_struct(t_lemin *lemin);
void		disp_values(t_lemin *lemin);
int		get_all_lines(t_lemin *lemin);
int		check_args(t_lemin *lemin);
int		get_nbr_ants(t_lemin *lemin);
int		put_room_in_list(t_lemin *lemin, char *str, int mode);
int		create_matrix(t_lemin *lemin);
int		add_to_matrix(t_lemin *lemin, char *str);
int		find_room(t_rooms *rooms, char *str);
int		check_link(char *str);
int		launch_algorithm(t_lemin *lemin, int *s_visited,
				 int *history);
int		recursive_algo(t_lemin *lemin, int i, int *is_visited,
			       int *history);
int		free_history_visited(int *is_visited_new, int *newhistory);
int		free_two_rooms(char *s1, char *s2);
char		*get_first_room(char *str);
char		*get_second_room(char *str);
t_rooms		*reverse_rooms(t_rooms *root);
t_path_list	*add_to_list(int *list, t_path_list **old, t_lemin *lemin);
void		display_list(t_path_list *list, t_lemin *lemin);
char		*get_name(t_lemin *lemin, int idx);
void		sort_list(t_path_list *list);
void		sanitize_list(t_path_list *list, t_lemin *lemin);
int		check_room(char *str, t_rooms *rooms);
void		launch_feeder(t_path_list *list, t_lemin *lemin);

#endif /* !LEMIN_H_ */
