/*
** ascii_to_binary.c for ascii_to_binary in /home/uberti_l/rendu/Unix/PSU_2015_minitalk/minitalk_client
**
** Made by louis-emile uberti-ares
** Login   <uberti_l@epitech.net>
**
** Started on  Mon Feb  1 15:18:04 2016 louis-emile uberti-ares
** Last update Wed Feb  3 14:05:34 2016 louis-emile uberti-ares
*/

#include <signal.h>
#include <unistd.h>
#include "include/client.h"

void		decimal_conversion(char ascii, int power, int pid)
{
  if (power > 0)
    decimal_conversion(ascii / 2, power - 1, pid);
  if ((ascii % 2) == 1)
    kill(pid, SIGUSR1);
  else
    kill(pid, SIGUSR2);
  usleep(1);
}

void		ascii_to_binary(char *str, int pid)
{
  int		i;

  i = 0;
  while (str[i] != '\0')
    {
      decimal_conversion(str[i], 7, pid);
      i += 1;
    }
}
