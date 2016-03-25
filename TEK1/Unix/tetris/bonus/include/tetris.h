/*
** tetris.h for tetris.h in /home/uberti_l/rendu/Unix/PSU_2015_tetris/include
**
** Made by louis-emile uberti-ares
** Login   <uberti_l@epitech.net>
**
** Started on  Mon Feb 22 13:10:36 2016 louis-emile uberti-ares
** Last update Fri Mar 25 16:47:53 2016 louis-emile uberti-ares
*/

#ifndef TETRIS_H_
# define TETRIS_H_
# define READ_SIZE (1)
#include <ncurses.h>

typedef struct		s_pieces
{
  char			**form;
  int			color;
  int			width;
  int			height;
}			t_pieces;

typedef struct		s_tetris
{
  int			**board;
  int			music_play;
  int			startx;
  int			starty;
  int			check;
  int			freeit;
  int			option_done;
  int			current;
  int			next_piece;
  int			verbose;
  int			nb_args;
  int			idx;
  int			highscore;
  int			score;
  int			nb_pieces;
  int			board_rows;
  int			board_lines;
  int			score_lines;
  int			level;
  int			pause;
  int			hide_next;
  int			biggest[2];
  int			timer[5];
  int			**shapeint;
  char			*left_key;
  char			*right_key;
  char			*turn_key;
  char			*quit_key;
  char			*pause_key;
  char			*drop_key;
  t_pieces		*pieces;
  WINDOW		*pause_screen;
  WINDOW		*credits;
  WINDOW		*field;
  WINDOW		*next;
  WINDOW		*quit;
}			t_tetris;

typedef struct	s_options
{
  char		*str;
  void		(*f)(t_tetris *game, char *option);
}		t_options;

typedef struct		s_responses
{
  char			*key;
  void			(*f)(t_tetris *game, char *key);
}			t_responses;

/*
** TOOLS
*/

void		terminal_mode(int mode);
void		put_spaces(int x, int y, int end_x, int end_y);
void		free_all(t_tetris *game);
void		free_wrong_shape(t_tetris *game, int idx);
void		my_putstr_err(char *str);
void		my_putchar(char c);
int		quick_match(char *str1, char *str2);
int		my_put_nbr(int nbr);
int		my_putstr(char *str);
int		my_strcmp(char *str1, char *str2);
int		unstrict_cmp(char *str1, char *str2);
int		my_strncmp(char *str1, char *str2, int n);
int		my_strlen(char *str);
int		my_getnbr(char *str);
int		getnbr_from(char *str, int to_start);
int		get_terminal_size(t_tetris *game);
int		isnbr_from(char *str, int i);
char		*dupkey(char *str);
char		*my_strdup(char *src);
char		*my_strcpy(char *dest, char *src);
char		*get_next_line(const int fd);
char		**my_str_to_wordtab(char *str);

/*
** FUNCTIONS
*/

void		force_quit_music(void);
void		game_over_sound(void);
void		music(void);
void		game_over(t_tetris *game);
void		set_colors(void);
void		print_help(char **av);
void		select_level(t_tetris *game, char *option);
void		check_bindings(t_tetris *game);
void		bind_left(t_tetris *game, char *option);
void		bind_right(t_tetris *game, char *option);
void		bind_drop(t_tetris *game, char *option);
void		bind_quit(t_tetris *game, char *option);
void		bind_pause(t_tetris *game, char *option);
void		bind_turn(t_tetris *game, char *option);
void		set_map_size(t_tetris *game, char *option);
void		hide_next(t_tetris *game, char *option);
void		get_tetrimino(t_tetris *game, char **argv);
void		debug_mode(t_tetris *game);
void		draw_shape(t_tetris *game, int idx);
void		print_name_before_tetrimino(char *str);
void		prompt_tetris(void);
void		prompt_credits(t_tetris *game);
void		escape_game(t_tetris *game);
void		the_game(t_tetris *game);
void		timer(t_tetris *game);
void		score_handle(t_tetris *game);
void		prompt_board(t_tetris *game);
void		load_highscore(t_tetris *game);
void		save_highscore(t_tetris *game);
void		prompt_next_tetrimino(t_tetris *game);
int		max_next_size(t_tetris *game);
int		setup_term(t_tetris *game, char **env);
int		pause_screen(t_tetris *game);
int		check_shape(t_tetris *game, int idx);
int		check_tetriminos(t_tetris *game);
int		normal_game(t_tetris *game);
int		get_terminal_size(t_tetris *game);
int		find_debug(int ac, char **av);
int		get_options(int ac, char **av, t_tetris *game);

/*
** TETRIS
*/

void		prompt_game(t_tetris *game);
void		play_tetris(t_tetris *game, char *key);
void		which_tetrimino(t_tetris *game, int touchdown);
int		**add_shape_to_field(t_tetris *game);
int		check_downward(t_tetris *game);
int		check_leftward(t_tetris *game);
int		check_rightward(t_tetris *game);
int		**check_turn(t_tetris *game);
int		**rotate(t_tetris *game);
int		move_right(t_tetris *game);
int		move_left(t_tetris *game);
int		move_downward(t_tetris *game);
int		**get_shape(t_tetris *game);
int		**check_line_completed(t_tetris *game);
int		check_put_shape(t_tetris *game);

#endif /* !TETRIS_H_ */
