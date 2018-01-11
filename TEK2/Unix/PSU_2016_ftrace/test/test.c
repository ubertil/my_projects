/*
** test.c for main in /home/uberti_l/rendu/Unix/PSU_2016_ftrace/test
**
** Made by Lous-Emile Uberti-Ares
** Login   <uberti_l@epitech.net>
**
** Started on  Sun Apr 23 22:27:31 2017 Lous-Emile Uberti-Ares
** Last update Sat May  6 12:05:40 2017 chalie_a
*/

#include <unistd.h>
#include <stdio.h>

void	third()
{
  printf("Third\n");
}

void	second()
{
  write(1, "Second\nCalling third\n", 22);
  third();
}

void	first()
{
  write(1, "First\n", 6);
  return;
}

int	main()
{
  first();
  second();
  write(1, "Main\n", 5);
  return (0);
}
