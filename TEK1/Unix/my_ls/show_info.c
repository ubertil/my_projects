/*
** show_right.c for show_rights in /home/uberti_l/rendu/PSU_2015_my_ls
**
** Made by louis-emile uberti-ares
** Login   <uberti_l@epitech.net>
**
** Started on  Fri Nov 27 15:07:10 2015 louis-emile uberti-ares
** Last update Sun Nov 29 22:24:01 2015 louis-emile uberti-ares
*/

#include <stdlib.h>
#include <sys/stat.h>
#include <grp.h>
#include <pwd.h>
#include <time.h>
#include <dirent.h>
#include <unistd.h>
#include "include/my.h"

void		display_core(char *directory)
{
  struct dirent	*dent;
  DIR		*dir;

  dir = opendir(directory);
  if (dir != NULL)
    {
      while ((dent = readdir(dir)) != NULL)
	{
	  show_rights(dent->d_name);
	  if ((dent->d_type == DT_DIR) && (dent->d_name[0] != '.'))
	    my_printf(" \033[34;01m%s\033[00m\n", dent->d_name);
	  else if (dent->d_name[0] != '.')
	    my_printf(" %s\n", dent->d_name);
	}
    }
  closedir(dir);
}

int		show_name(char *file)
{
  struct dirent	*dent;
  DIR		*dir;

  dir = opendir(file);
  dent = readdir(dir);
  if ((dent->d_type == DT_DIR) && (dent->d_name[0] != '.'))
    my_printf(" \033[34;01m%s\033[00m\n", dent->d_name);
  else if (dent->d_name[0] != '.')
    my_printf(" %s\n", dent->d_name);
  return (0);
}

int		show_time(char *file)
{
  char		*disp;
  struct stat	sb;

  if (file[0] == '.')
    return (1);
  lstat(file, &sb);
  disp = ctime(&sb.st_mtime);
  write (1, disp + 4, 12);
  show_name(file);
  return (0);
}

int		show_owners(char *file)
{
  struct stat	sb;
  struct passwd	*uid;
  struct group	*gid;

  if (file[0] == '.')
    return (1);
  lstat(file, &sb);
  uid = getpwuid(sb.st_uid);
  gid = getgrgid(sb.st_gid);
  my_printf("%d %s %s\t", (int)sb.st_nlink, uid->pw_name, gid->gr_name);
  my_printf("%d  ", sb.st_size);
  show_time(file);
  return (0);
}

int		show_rights(char *file)
{
  struct stat	sb;
  DIR		*dir;

  if (file[0] == '.')
    return (1);
  lstat(file, &sb);
  if ((dir = opendir(file)) != NULL)
    my_putchar('d');
  else
    my_putchar('-');
  ((sb.st_mode) & (S_IRUSR)) ? (my_putchar('r')) : (my_putchar('-'));
  ((sb.st_mode) & (S_IWUSR)) ? (my_putchar('w')) : (my_putchar('-'));
  ((sb.st_mode) & (S_IXUSR)) ? (my_putchar('x')) : (my_putchar('-'));
  ((sb.st_mode) & (S_IRGRP)) ? (my_putchar('r')) : (my_putchar('-'));
  ((sb.st_mode) & (S_IWGRP)) ? (my_putchar('w')) : (my_putchar('-'));
  ((sb.st_mode) & (S_IXGRP)) ? (my_putchar('x')) : (my_putchar('-'));
  ((sb.st_mode) & (S_IROTH)) ? (my_putchar('r')) : (my_putchar('-'));
  ((sb.st_mode) & (S_IWOTH)) ? (my_putchar('w')) : (my_putchar('-'));
  ((sb.st_mode) & (S_IXOTH)) ? (my_putchar('x')) : (my_putchar('-'));
  my_putchar(' ');
  show_owners(file);
  return (0);
}
