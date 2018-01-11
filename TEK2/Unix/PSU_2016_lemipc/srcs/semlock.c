/*
** semlock.c for PSU_2016_lemipc in /home/uberti_p/delivery/PSU_2016_lemipc/semlock.c
**
** Made by Louis-Emile Uberti-Ares
** Login   <louis-emile.uberti-ares@epitech.eu>
**
** Started on  jeu. mars 30 21:27:03 2017 Louis-Emile Uberti-Arès
** Last update Sat Apr  1 14:50:59 2017 Lous-Emile Uberti-Ares
*/

#include "lemipc.h"

void		lock(const int sem_id, struct sembuf sops)
{
  sops.sem_num = 0;
  sops.sem_flg = 0;
  sops.sem_op = -1;
  semop(sem_id, &sops, 1);
}

void		unlock(const int sem_id, struct sembuf sops)
{
  sops.sem_num = 0;
  sops.sem_flg = 0;
  sops.sem_op = 1;
  semop(sem_id, &sops, 1);
}
