/*
** profondeur.h for profondeur.h in /home/trognot/rendu/IA/dante/generator/profondeur
**
** Made by nicolas trognot
** Login   <nicolas.trognot@epitech.eu>
**
** Started on  Thu May 12 02:08:54 2016 nicolas trognot
** Last update Fri May 27 17:16:44 2016 louis-emile uberti-ares
** Last update Fri May 27 15:57:42 2016 louis-emile uberti-ares
*/

#ifndef PROFONDEUR_H_
# define PROFONDEUR_H_
# define USAGE "Usage : ./solver maze.txt\n"
# define ERR_MALLOC "Error while using malloc(). Aborting.\n"
# define WRONG_FORMAT "Error: Your file is not a proper maze. Aborting.\n"
# define NOTHING "No solution found.\n"
# define TOO_MUCH "Error: Please enter maze smaller than 1500 * 1500\n"

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
int			solve_maze(t_maze *maze);

#endif /* !PROFONDEUR_H_ */
