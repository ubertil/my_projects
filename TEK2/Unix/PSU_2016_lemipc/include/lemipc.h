/*
** lemipc.h for PSU_2016_lemipc in /home/uberti_p/delivery/PSU_2016_lemipc/lemipc.h
**
** Made by Louis-Emile Uberti-Ares
** Login   <louis-emile.uberti-ares@epitech.eu>
**
** Started on  mer. mars 29 11:19:47 2017 Louis-Emile Uberti-Arès
** Last update Sun Apr  2 13:18:30 2017 Lous-Emile Uberti-Ares
*/

#ifndef LEMIPC_H_
# define LEMIPC_H_
# include <sys/types.h>
# include <sys/ipc.h>
# include <sys/sem.h>
# include "shared.h"

# define TOO_MANY_CLIENTS "Warning : Too many clients connected simultanously\
for map size (max allowed is %d).\nPlease wait for some to die before launching\
 again.\n"
# define NEW_FIGHTER "A new fighter for team n°%d enters in the arena at\
(%d, %d). Wish him luck !\n"
# define WINNER "Team n°%d wins ! Congratulations !\n"

# define SHM_CREATED "Created shm with id : %d\n"
# define SEM_CREATED "Created sem with id : %d\n"
# define MSGQ_CREATED "Created msgq with id : %d\n"
# define SHM_USED "Using shm with id : %d\n"
# define SEM_USED "Using sem with id : %d\n"
# define MSGQ_USED "Using msgq with id : %d\n"

# define SHM_ERR_CREATE "Error: shmget: could not allocate shared memory\n"
# define SEM_ERR_CREATE "Error: semget: could not create semaphore\n"
# define MSGQ_ERR_CREATE "Error: msgget: could not create message queue\n"

# define ALERT_QUIT "Autobots, rollout !"

typedef enum		e_status
  {
    ADMIN,
    CLIENT
  }			e_status;

typedef enum		e_live
  {
    ALIVE,
    DEAD
  }			e_live;

typedef struct		s_msg
{
  long			mtype;
  char			str[42];
}			t_msg;

typedef struct		s_team
{
  int			shm_id;
  int			sem_id;
  int			msg_id;
  int			team_number;
  int			current_x;
  int			current_y;
  e_status		status;
  e_live		live;
  struct sembuf		sops;
  t_shared		*shared;
}			t_team;

void			lock(const int, struct sembuf);
void			unlock(const int, struct sembuf);
void			display_map(const t_team *);
void			move_random(t_team *);
void			place_randomly(t_team *);
void			send_msg(const t_team *, const char *);
int			rcv_msg(const t_team *, const char *);
int			get_msgq(t_team *, const key_t);
int			get_surroundings(const t_team *, int *,
					 const int, const int);
int			is_dead(const t_team *);
int			winner(const t_team *);
int			can_start(const t_team *);
int			handle_args(t_team *, const char *);
int			team_dead(t_team *);
int			create_map(t_team *);
int			sighandler(int, t_team *);

#endif /* !LEMIPC_H_ */
