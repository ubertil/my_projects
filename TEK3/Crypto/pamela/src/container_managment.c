#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "../include/pamela.h"

void	create_container(const char *usr, const char *pass)
{
  char	cmd[CMD_LEN] = {0};


  sprintf(cmd, CMD_VERIF_HOME, usr);
  system(cmd);
  memset(cmd, 0, CMD_LEN);
  sprintf(cmd, CMD_CREATE_CONTAINER, usr, usr, CONTAINER_SIZE);
  system(cmd);
  memset(cmd, 0, CMD_LEN);
  sprintf(cmd, CMD_FORMAT_CONTAINER, pass, usr, usr);
  system(cmd);
  memset(cmd, 0, CMD_LEN);
  sprintf(cmd, CMD_OPEN_CONTAINER, pass, usr, usr, usr);
  system(cmd);
  memset(cmd, 0, CMD_LEN);
  sprintf(cmd, CMD_MKFS_CONTAINER, usr);
  system(cmd);
  memset(cmd, 0, CMD_LEN);
  sprintf(cmd, CMD_CREATE_MOUNTING_POINT, usr);
  system(cmd);
  memset(cmd, 0, CMD_LEN);
  sprintf(cmd, CMD_SET_USER_RIGHTS, usr, usr);
  system(cmd);
  memset(cmd, 0, CMD_LEN);
  sprintf(cmd, CMD_CLOSE_CONTAINER, usr);
  system(cmd);
}

bool	container_exists(const char *usr)
{
  FILE	*container;
  char	path[CMD_LEN] = {0};

  sprintf(path, CONTAINER_PATH, usr, usr);
  if ((container = fopen(path, "r")) == NULL)
    return (false);
  return (true);
}

void	open_container(const char *usr, const char *pass)
{
  char	cmd[CMD_LEN] = {0};

  sprintf(cmd, CMD_OPEN_CONTAINER, pass, usr, usr, usr);
  system(cmd);
  memset(cmd, 0, CMD_LEN);
  sprintf(cmd, CMD_MOUNT_CONTAINER, usr, usr);
  system(cmd);
  memset(cmd, 0, CMD_LEN);
  sprintf(cmd, CMD_SET_USER_RIGHTS, usr, usr);
  system(cmd);
}

void	close_container(const char *usr)
{
  char	cmd[CMD_LEN] = {0};

  sprintf(cmd, CMD_UMOUNT_CONTAINER, usr);
  system(cmd);
  memset(cmd, 0, CMD_LEN);
  sprintf(cmd, CMD_CLOSE_CONTAINER, usr);
  system(cmd);
}

void	change_container_key(const char *usr, const char *old_pass, const char *new_pass)
{
  char	cmd[CMD_LEN] = {0};

  sprintf(cmd, CMD_CHANGE_CONTAINER_KEY, old_pass, new_pass, new_pass, usr, usr);
  system(cmd);
  memset(cmd, 0, CMD_LEN);
  sprintf(cmd, CMD_REMOVE_OLD_KEY, old_pass, usr, usr);
  system(cmd);
}
