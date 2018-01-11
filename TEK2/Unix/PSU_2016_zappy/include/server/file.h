/*
** file.h for file.h in /home/nicolas.trognot/rendu/Reseau/PSU_2016_zappy/include/server
**
** Made by Nicolas TROGNOT
** Login   <nicolas.trognot@epitech.net>
**
** Started on  Tue Jun 27 10:05:43 2017 Nicolas TROGNOT
** Last update Tue Jun 27 10:05:52 2017 Nicolas TROGNOT
*/

#ifndef FILE_H_
# define FILE_H_
# include <stdio.h>
# include "server/server.h"

FILE		*get_file_from_fd(t_server *server, int fd);

#endif /* !FILE_H_ */
