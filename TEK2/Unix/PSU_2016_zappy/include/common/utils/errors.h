/*
** errors.h for zappy in /home/papadi_a/work/epitech/Tek2/PSU/PSU_2016_zappy/include/utils
**
** Made by alexis papadimitriou
** Login   <papadi_a@epitech.net>
**
** Started on  Wed Jun 21 12:00:22 2017 alexis papadimitriou
** Last update Sun Jul  2 19:40:07 2017 grella_c
*/

#ifndef ERRORS_H_
# define ERRORS_H_
# define CLIENT_MLLC_ERR "Error: Failed to allocate memory for t_client"
# define CLIENT_SCKT_ERR "Error: Failed to open a connection for t_client"
# define ERROR_CODE 84
# include <stdint.h>

void	*p_error(const char *msg);
int32_t	d_error(const char *msg);

#endif /* !ERRORS_H_ */
