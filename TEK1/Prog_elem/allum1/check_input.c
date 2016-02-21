/*
** check_input.c for check_input in /home/uberti_l/rendu/Prog_elem/CPE_2015_Allum1
**
** Made by louis-emile uberti-ares
** Login   <uberti_l@epitech.net>
**
** Started on  Thu Feb 18 14:20:19 2016 louis-emile uberti-ares
** Last update Sun Feb 21 22:15:36 2016 louis-emile uberti-ares
*/

#include <stdlib.h>
#include "include/allum.h"

int		prompt_error_line(t_allum *allum)
{
  if ((is_nbr(allum->line) == 1) || (allum->line[0] == '\0'))
    {
      my_putstr_err("Error: invalid input (positive number expected)\n");
      return (1);
    }
  if ((my_getnbr(allum->line) > 4) || (my_getnbr(allum->line) == 0))
    {
      my_putstr_err("Error: this line is out of range\n");
      return (1);
    }
  if ((allum->lines[my_getnbr(allum->line)] == 0)
      && (my_getnbr(allum->line) != 0))
    {
      my_putstr_err("Error: this line is out of range\n");
      return (1);
    }
  return (0);
}

int		prompt_error_matches(t_allum *allum)
{
  if ((is_nbr(allum->matches) == 1) || (allum->matches[0] == '\0'))
    {
      my_putstr_err("Error: invalid input (positive number expected)\n");
      free(allum->line);
      free(allum->matches);
      return (1);
    }
  if (my_getnbr(allum->matches) > allum->lines[my_getnbr(allum->line)])
    {
      my_putstr_err("Error: not enough match(es) on this line\n");
      free(allum->line);
      free(allum->matches);
      return (1);
    }
  if (allum->matches[0] == '0')
    {
      my_putstr_err("Error: you have to remove at least one match\n");
      free(allum->line);
      free(allum->matches);
      return (1);
    }
  return (0);
}

int		check_line_and_matches(t_allum *allum)
{
  my_putstr("Line: ");
  if ((allum->line = get_shell_line(0)) == NULL)
    return (1);
  if (prompt_error_line(allum) == 1)
    {
      check_line_and_matches(allum);
      return (0);
    }
  my_putstr("Matches: ");
  if ((allum->matches = get_shell_line(0)) == NULL)
    return (1);
  else if (prompt_error_matches(allum) == 1)
    {
      check_line_and_matches(allum);
      return (0);
    }
  return (0);
}

int		check_error(t_allum *allum)
{
  if (check_line_and_matches(allum) == 1)
    {
      my_putchar('\n');
      return (1);
    }
  return (0);
}
