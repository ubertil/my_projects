/*
** tokens.h for tokens.h in /home/trognot/rendu/PSU/PSU_2015_42sh/src
**
** Made by nicolas trognot
** Login   <nicolas.trognot@epitech.eu>
**
** Started on  Tue May 10 17:19:13 2016 nicolas trognot
** Last update Sun Jun  5 15:51:26 2016 louis-emile uberti-ares
*/

#ifndef TOKENS_H_
# define TOKENS_H_
# define NB_TOKEN (9)
# define TK_PIPE (0)
# define TK_R_REDIRECT (1)
# define TK_RR_REDIRECT (2)
# define TK_L_REDIRECT (3)
# define TK_LL_REDIRECT (4)
# define TK_AND (5)
# define TK_OR (6)
# define TK_END (7)

/*
** STRUCTURES
*/

typedef struct s_shell	t_shell;

/*
** FUNCTIONS
*/

int	init_tokens(t_shell *sh);

#endif /* !TOKENS_H_  */
