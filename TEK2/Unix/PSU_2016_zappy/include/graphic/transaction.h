/*
** transaction.h for transaction.h in /home/nicolas.trognot/rendu/Reseau/PSU_2016_zappy/include/graphic
**
** Made by Nicolas TROGNOT
** Login   <nicolas.trognot@epitech.net>
**
** Started on  Thu Jun 29 11:10:04 2017 Nicolas TROGNOT
** Last update Sun Jul  2 19:42:38 2017 grella_c
*/

#ifndef TRANSACTION_H_
# define TRANSACTION_H_
# define READ_SIZE 1024
# include "graphic/core.h"

bool		init_transaction(t_core *core);
bool		manage_transaction(t_core *core, struct timeval *timeout);

#endif /* !TRANSACTION_H_ */
