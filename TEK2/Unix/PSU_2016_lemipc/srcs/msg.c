/*
** msg.c for msg in /home/uberti_l/rendu/Unix/PSU_2016_lemipc
**
** Made by Lous-Emile Uberti-Ares
** Login   <uberti_l@epitech.net>
**
** Started on  Sun Apr  2 11:19:51 2017 Lous-Emile Uberti-Ares
** Last update Sun Apr  2 11:57:22 2017 Lous-Emile Uberti-Ares
*/

#include <string.h>
#include <strings.h>
#include <sys/shm.h>
#include <sys/msg.h>
#include <stdio.h>
#include "lemipc.h"

int		rcv_msg(const t_team *team, const char *expected)
{
  t_msg		my_msg;

  if (msgrcv(team->msg_id, &my_msg, sizeof(my_msg), 1, IPC_NOWAIT) == -1)
    return (-1);
  return (strcmp(my_msg.str, expected));
}

void		send_msg(const t_team *team, const char *str)
{
  t_msg		my_msg;

  bzero(&my_msg, sizeof(my_msg));
  my_msg.mtype = team->team_number;
  sprintf(my_msg.str, str);
  msgsnd(team->msg_id, &my_msg, sizeof(my_msg), 0);
}

int		get_msgq(t_team *team, const key_t key)
{
  int		msg_id;

  msg_id = msgget(key, SHM_R | SHM_W);
  if (msg_id == -1)
    {
      team->msg_id = msgget(key, IPC_CREAT | SHM_R | SHM_W);
      if (team->msg_id == -1)
	{
	  dprintf(2, MSGQ_ERR_CREATE);
	  return (1);
	}
      dprintf(1, MSGQ_CREATED, team->msg_id);
    }
  else
    {
      team->msg_id = msg_id;
      dprintf(1, MSGQ_USED, team->msg_id);
    }
  return (0);
}
