/*
** utils.h for zappy in /home/papadi_a/work/epitech/Tek2/PSU/PSU_2016_zappy/include/client
**
** Made by alexis papadimitriou
** Login   <papadi_a@epitech.net>
**
** Started on  Wed Jun 21 11:46:11 2017 alexis papadimitriou
** Last update Sun Jul  2 19:40:27 2017 grella_c
*/

#ifndef UTILS_H_
# define UTILS_H_
# define INLINE inline __attribute__((always_inline))
# define UNUSED __attribute__((unused))
# define ABS(x) (x > 0 ? x : -x)
# include <stddef.h>
# include <stdbool.h>
# include <stdint.h>

int		rot13(const int nb);
bool		is_nbr(const char *str);
void		free_wordtab(char **wordtab);
void		secure_write(int fd, const void *buff, size_t count);
char		**str_to_wordtab(const char *str, const char *sep);
uint32_t	tab_len(char **tab);

#endif /* !UTILS_H_ */
