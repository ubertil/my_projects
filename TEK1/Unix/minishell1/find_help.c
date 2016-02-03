/*
** find_help.c for find_help in /home/uberti_l/rendu/Unix/PSU_2015_minishell1
**
** Made by louis-emile uberti-ares
** Login   <uberti_l@epitech.net>
**
** Started on  Tue Jan 19 11:11:45 2016 louis-emile uberti-ares
** Last update Sun Jan 24 14:19:23 2016 louis-emile uberti-ares
*/

#include "include/mysh.h"
#include <unistd.h>

void	help_env(void)
{
  my_putchar('\f');
  my_putstr("\033[01;37mENV(1)\t\t\tMinishell1 UBERTI_L ");
  my_putstr("Program Help\t\t  ENV(1)\n\n\033[0m");
  my_putstr("\033[01;37mNAME\n\033[0m\tenviron");
  my_putstr("\n\n\033[01;37mSYNOPSIS\n\033[0m\tenv is used to display ");
  my_putstr("useful informations about the shell envirionnement.\n");
  my_putstr("The variable environ points to an array of pointers to strings ");
  my_putstr("called the 'environment'.\nProcess are using this variable.\n");
  my_putstr("You can see the envrionment by typing env in the minishell1\n");
  my_putstr("If the environment is empty, nothing is displayed\n\n");
  my_putstr("\033[01;37mSEE ALSO\n\tsetenv(2), unsetenv(3)\033[0m\n\n");
  my_putstr("\033[01;37mCOLOPHON\n\t\033[0mThis page is part of release ");
  my_putstr("1.0 of the Minishell1 project by uberti_l\n");
  my_putstr("\t\t(2016 Copyright uberti_l | All Rights reserved)\n");
}

void	help_setenv(void)
{
  my_putchar('\f');
  my_putstr("\033[01;37mSETENV(2)\t\t\tMinishell1 UBERTI_L ");
  my_putstr("Program Help\tSETENV(2)\n\n\033[0m");
  my_putstr("\033[01;37mNAME\n\033[0m\t");
  my_putstr("setenv - change or add an environment variable\n");
  my_putstr("\n\n\033[01;37mSYNOPSIS\n\033[0m\tsetenv ");
  my_putstr("[NAME] [VALUE] [OVERWRITE_VALUE]\n");
  my_putstr("The setenv built-in adds the ");
  my_putstr("variable name to the environnement with the given value, if name ");
  my_putstr("doesn't exist.\nIf name does exist in the environment(1) then its");
  my_putstr("value is changed to the new value if overwrite is nonzero; ");
  my_putstr("if overwrite is zero, then the value of name is not changed\n\n");
  my_putstr("\033[01;37mSEE ALSO\n\tenviron(1), unsetenv(3)\033[0m\n\n");
  my_putstr("\033[01;37mCOLOPHON\n\t\033[0mThis page is part of release ");
  my_putstr("1.0 of the Minishell1 project by uberti_l\n");
  my_putstr("\t\t(2016 Copyright uberti_l | All Rights reserved)\n");
}

void	help_unsetenv(void)
{
  my_putchar('\f');
  my_putstr("\033[01;37mUNSETENV(2)\t\t\tMinishell1 UBERTI_L ");
  my_putstr("Program Help\tUNSETENV(2)\n\n\033[0m");
  my_putstr("\033[01;37mNAME\n\033[0m\t");
  my_putstr("unsetenv - delete the variable name from the environment\n");
  my_putstr("\n\n\033[01;37mSYNOPSIS\n\033[0m\tunsetenv ");
  my_putstr("does the opposite of setenv. If the given name does not exist");
  my_putstr("in the environment, then the built-in succeeds and the ");
  my_putstr("environment is unchanged");
  my_putstr("\033[01;37mSEE ALSO\n\tenviron(1), setenv(2)\033[0m\n\n");
  my_putstr("\033[01;37mCOLOPHON\n\t\033[0mThis page is part of release ");
  my_putstr("1.0 of the Minishell1 project by uberti_l\n");
  my_putstr("\t\t(2016 Copyright uberti_l | All Rights reserved)\n");
}

void	help_minishell(void)
{
  my_putchar('\f');
  my_putstr("\033[01;37m\t\t\tMinishell1 UBERTI_L\n\n\033[0m");
  my_putstr("Welcome on Minishell1 by uberti_l (2016), developped in C.\n");
  my_putstr("You can use various built-in commands, listed in the help ");
  my_putstr("section.\nLeave the minishell by typing 'exit' in the terminal.\n");
  my_putstr("All built-in commands are listed below : \n");
  my_putstr("\t \033[01;37mcd, env, setenv, unsetenv, clear, help\n");
  my_putstr("COLOPHON\n\t\033[0mThis page is part of release ");
  my_putstr("1.0 of the Minishell1 project by uberti_l\n");
  my_putstr("\t\t(2016 Copyright uberti_l | All Rights reserved)\n");
}

int	display_help(void)
{
  char	page[2];
  int	breakvalue;

  breakvalue = 0;
  my_putstr("Help: find all matching help pages\n");
  my_putstr(" * environ (1)\n   setenv (2)\n   unsetenv (3)\n   ");
  my_putstr("about minishell1 (4)\nHelp: What help page do you want?\nHelp: ");
  while (breakvalue == 0)
    {
      if (read(0, page, 2) >= 1)
	breakvalue = 1;
    }
  if (page[0] == '1')
    help_env();
  if (page[0] == '2')
    help_setenv();
  if (page[0] == '3')
    help_unsetenv();
  if (page[0] == '4')
    help_minishell();
  else if (page[0] < '0' || page[0] > '4')
    write(2, "No help page for the required section\n", 39);
  return (0);
}
