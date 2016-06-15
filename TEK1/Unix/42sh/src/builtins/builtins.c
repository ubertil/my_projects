/*
** builtins.c for 42sh in /home/papadi_a/work/epitech/PSU/PSU_2015_42sh/src/builtins
**
** Made by alexis papadimitriou
** Login   <papadi_a@epitech.net>
**
** Started on  Fri May  6 12:23:00 2016 alexis papadimitriou
** Last update Sun Jun  5 16:03:48 2016 louis-emile uberti-ares
*/

#include <stdlib.h>
#include "shell.h"
#include "env.h"
#include "builtins.h"
#include "alias.h"

int	init_builtins(t_shell *shell)
{
  if ((shell->builtins = malloc(sizeof(t_builtins) * 9)) == NULL)
    return (-1);
  shell->builtins[0].cmd = "cd";
  shell->builtins[1].cmd = "echo";
  shell->builtins[2].cmd = "setenv";
  shell->builtins[3].cmd = "unsetenv";
  shell->builtins[4].cmd = "env";
  shell->builtins[5].cmd = "exit";
  shell->builtins[6].cmd = "source";
  shell->builtins[7].cmd = "alias";
  shell->builtins[8].cmd = NULL;
  shell->builtins[0].builtin = &my_cd;
  shell->builtins[1].builtin = &my_echo;
  shell->builtins[2].builtin = &my_setenv;
  shell->builtins[3].builtin = &my_unsetenv;
  shell->builtins[4].builtin = &my_env;
  shell->builtins[5].builtin = &my_exit;
  shell->builtins[6].builtin = &source_bashrc;
  shell->builtins[7].builtin = &alias_input;
  shell->builtins[8].builtin = NULL;
  return (0);
}
