/*
** get_next_line.h for get_next_line.h in /home/trogno_n/rendu/CPE/CPE_2015_getnextline
**
** Made by nicolas trognot
** Login   <trogno_n@epitech.net>
**
** Started on  Thu Jan  7 10:51:29 2016 nicolas trognot
** Last update Mon Jan 11 14:45:53 2016 nicolas trognot
*/

#ifndef GET_NEXT_LINE_H_
# define GET_NEXT_LINE_H_
# ifndef READ_SIZE
#  define READ_SIZE (1)
# endif /* !READ_SIZE */

typedef struct		s_gnl
{
  int			ret;
  char			*buf;
  char			plug[READ_SIZE + 1];
  int			check_i;
  int			check_ret;
  char			*check_ret_stack;
  char			*check_add_to_stack;
}			t_gnl;

typedef struct		s_concat
{
  char			*dst;
  int			len;
  int			tmp;
}			t_concat;

char			*get_next_line(const int fd);

#endif /* !GET_NEXT_LINE_H_ */
