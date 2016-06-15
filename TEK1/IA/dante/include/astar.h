/*
** astar.h for astar.h in /home/trognot/rendu/IA/dante/generator/astar
**
** Made by nicolas trognot
** Login   <nicolas.trognot@epitech.eu>
**
** Started on  Thu May 12 02:08:54 2016 nicolas trognot
** Last update Fri May 27 15:01:44 2016 louis-emile uberti-ares
*/

#ifndef ASTAR_H_
# define ASTAR_H_
# define USAGE "Usage : ./solver maze.txt.\n"
# define ERR_MALLOC "Error while using malloc(). Aborting.\n"
# define WRONG_FORMAT "Error: Your file is not a proper maze. Aborting.\n"
# define NOTHING "No solution found.\n"

typedef struct		s_point
{
  int			x;
  int			y;
}			t_point;

typedef struct		s_node
{
  float			cost_g;
  float			cost_h;
  float			cost_f;
  int			x;
  int			y;
  t_point		father;
}			t_node;

typedef struct		s_list
{
  t_node		*node;
  struct s_list		*next;
}			t_list;

typedef struct		s_maze
{
  int			w;
  int			h;
  char			**cells;
  int			file_fd;
  char			*file;
  t_list		*open;
  t_list		*close;
  t_point		begin;
}			t_maze;

/*
** LIB
*/

int			my_putstr_err(const char *str);
int			my_getnbr(const char *str);

/*
** CORE
*/

void			free_tab(char **tab, const int y);
void			free_all(t_maze *maze);
int			get_maze_protected(t_maze *maze, int x, int y);
int			maze_checker(char *maze, const int ret);
t_maze			*init_maze();
int			open_file(t_maze *maze, char *filepath);
void			display_maze(t_maze *maze);
int			solve_maze(t_maze *maze);
float			distance(int x1, int y1, int x2, int y2);
t_node			init_start(t_maze *maze, t_point *cur);
void			fill_result(t_maze *maze);
t_point			best_node(t_list *list);
t_list			*add_elem_in_close_list(t_maze *maze, t_point *pt);
int			delete_node(t_list **head_ref, int x, int y);
t_list			*add_elem_in_list(t_list *list, t_node *node);
int			already_in_list(t_list *list, int x, int y);
float			get_cost_g_from_father(int x, int y, t_maze *maze);
float			get_cost_g_from_father_ouverte(int x, int y,
						       t_maze *maze);
float			get_cost_f_from_father(int x, int y, t_maze *maze);
float			get_cost_h_from_father_ouverte(int x, int y,
						       t_maze *maze);
t_point			get_father_from_father_ouverte(int x, int y,
						       t_maze *maze);
float			get_cost_h_from_father(int x, int y, t_maze *maze);
void			update_node(int x, int y, t_maze *maze, t_node *node);

#endif /* !ASTAR_H_ */
