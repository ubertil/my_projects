/*
** history.h for history in /home/uberti_l/rendu/Unix/PSU_2015_42sh
**
** Made by louis-emile uberti-ares
** Login   <uberti_l@epitech.net>
**
** Started on  Tue May 31 11:12:26 2016 louis-emile uberti-ares
** Last update Sun Jun  5 15:49:30 2016 louis-emile uberti-ares
*/

#ifndef HISTORY_H_
# define HISTORY_H_
# define HIST_FILE ".42sh_history"

/*
** STRUCTURES
*/

typedef struct s_shell	t_shell;

/*
** FUNCTIONS
*/

int			add_line_to_history(t_shell *shell,
					    const char *buffer);
int			find_hist_place(t_shell *shell);

#endif /* !HISTORY_H_ */
