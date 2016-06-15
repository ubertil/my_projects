/*
** largeur.h for largeur.h in /home/trognot/rendu/IA/dante/generator/largeur
**
** Made by nicolas trognot
** Login   <nicolas.trognot@epitech.eu>
**
** Started on  Thu May 12 02:08:54 2016 nicolas trognot
** Last update Fri May 27 15:39:01 2016 louis-emile uberti-ares
*/

#ifndef LARGEUR_H_
# define LARGEUR_H_
# define USAGE "Usage : ./solver maze.txt"
# define ERR_MALLOC "Error while using malloc(). Aborting.\n"
# define WRONG_FORMAT "Error: Your file is not a proper maze. Aborting.\n"
# define NOTHING "No solution found.\n"

typedef struct		s_maze
{
  int			w;
  int			h;
  char			**cells;
  int			file_fd;
  char			*file;
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
t_maze			*init_maze();
int			maze_checker(char *maze, const int ret);
int			open_file(t_maze *maze, char *filepath);
void			display_maze(t_maze *maze);
int			solver(t_maze *maze);
void			fill_three(t_maze *maze);
void			set_maze_protected(t_maze *maze, int y, int x,
					   int val);
int			get_maze_protected(t_maze *maze, int y, int x);
int			compare_neighbours(t_maze *maze, int w, int h,
					   int val);
int			cmp_nb_final(t_maze *maze, int w, int h, int val);

#endif /* !LARGEUR_H_ */
