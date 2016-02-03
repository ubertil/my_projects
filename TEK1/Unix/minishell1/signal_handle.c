/*
** signal_handle.c for signal_handle in /home/uberti_l/rendu/Unix/PSU_2015_minishell1
**
** Made by louis-emile uberti-ares
** Login   <uberti_l@epitech.net>
**
** Started on  Tue Jan  5 16:38:37 2016 louis-emile uberti-ares
** Last update Sun Jan 24 11:31:43 2016 louis-emile uberti-ares
*/

#include "include/mysh.h"

void		signal_sigint(int signum)
{
  my_putstr("\n$> ");
  (void)signum;
}
