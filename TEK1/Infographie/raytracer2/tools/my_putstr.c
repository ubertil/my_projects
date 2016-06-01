/*
** my_putstr.c for my_putstr in /home/rahil_f/rendu/gfx_raytracer2
** 
** Made by Félix Rahil
** Login   <rahil_f@epitech.net>
** 
** Started on  Sun May 22 17:55:10 2016 Félix Rahil
** Last update Sun May 22 17:55:51 2016 Félix Grellard
*/

#include <unistd.h>

void	my_putstr(char *str)
{
  int	i;

  i = 0;
  while (str[i] != '\0')
    write(1, &str[i++], 1);
}
