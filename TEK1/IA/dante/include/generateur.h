/*
** generateur.h for generateur.h in /home/trognot/rendu/IA/dante/generator/perfect
**
** Made by nicolas trognot
** Login   <nicolas.trognot@epitech.eu>
**
** Started on  Thu May 12 02:08:54 2016 nicolas trognot
** Last update Fri May 27 17:15:10 2016 louis-emile uberti-ares
** Last update Fri May 27 15:45:04 2016 louis-emile uberti-ares
*/

#ifndef GENERATEUR_H_
# define GENERATEUR_H_
# define ERR_SIZE "Error: Invalid size parameters. Aborting.\n"
# define ERR_TYPE "Error: Unknown type requested. Aborting.\n"
# define TOO_MUCH "Error : Please enter size under or equal to 1000.\n"
# define USAGE "Usage : ./generateur width height type\n"
# define ERR_STACK "Error: Impossible to modify stack size. Aborting.\n"
# define STACK_SIZE (0x77777777)

typedef struct		s_vec2i
{
  int			x;
  int			y;
}			t_vec2i;

typedef struct		s_maze
{
  int			w;
  int			h;
  char			**cells;
  char			is_perf;
}			t_maze;

/*
** LIB
*/

int			my_putstr_err(const char *str);
void			my_putstr(const char *str);
int			my_getnbr(const char *str);

/*
** CORE
*/

void			free_all(t_maze *maze);
int			push_stack();
int			check_args(char **av, int ac, char *mode);
int			build_maze(t_maze *maze, int x, int y, int len);
t_maze			*init_maze(int w, int h);
void			display_maze(t_maze *maze);
void			set_maze_protected(t_maze *maze,
					   int y, int x, int val);
void			fill(t_maze *maze, int w, int h);

#endif /* !GENERATEUR_H_ */
