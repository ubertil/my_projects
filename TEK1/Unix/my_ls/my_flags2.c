/*
** my_flags2.c for my_flags2 in /home/uberti_l/rendu/PSU_2015_my_ls
**
** Made by louis-emile uberti-ares
** Login   <uberti_l@epitech.net>
**
** Started on  Fri Nov 27 16:34:44 2015 louis-emile uberti-ares
** Last update Sun Nov 29 18:34:23 2015 louis-emile uberti-ares
*/

#include <sys/stat.h>
#include <dirent.h>
#include <stdlib.h>
#include "include/my.h"

void		my_show_basic(t_dir *a)
{
  t_dir		*tmp;
  struct dirent *dent;
  DIR           *dir;

  if ((tmp = malloc(sizeof(*tmp))) == NULL)
    exit (84);
  tmp = a;
  while (tmp != NULL)
    {
      dir = opendir(tmp->file);
      if (dir != NULL)
	{
	  while ((dent = readdir(dir)) != NULL)
	    {
	      if (dent->d_name[0] == '.')
		((dent = readdir(dir)) != NULL) ? (0) : (exit(84));
	      if ((dent->d_type == DT_DIR) && (dent->d_name[0] != '.'))
		my_printf("\033[34;01m%s\033[00m\n", dent->d_name);
		else if (dent->d_name[0] != '.')
		my_printf("%s\n", dent->d_name);
	    }
	}
      closedir(dir);
      tmp = tmp->next;
    }
}
