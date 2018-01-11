#ifndef PAMELA_H_
# define PAMELA_H_
# define CMD_LEN			(1024)
# define CONTAINER_SIZE			(1024)
# define CONTAINER_PATH			("/home/%s/%s_container")
# define CMD_VERIF_HOME			("mkdir -p /home/%s")
# define CMD_CREATE_CONTAINER		("dd if=/dev/urandom of=/home/%s/%s_container bs=1M count=%d\n")
# define CMD_FORMAT_CONTAINER		("echo \"%s\" | cryptsetup luksFormat /home/%s/%s_container")
# define CMD_OPEN_CONTAINER		("echo \"%s\" | cryptsetup luksOpen /home/%s/%s_container %s_container")
# define CMD_MKFS_CONTAINER		("mkfs.ext4 /dev/mapper/%s_container")
# define CMD_CREATE_MOUNTING_POINT	("mkdir /home/%s/secure_data-rw")
# define CMD_SET_USER_RIGHTS		("chown %s /home/%s/secure_data-rw/")
# define CMD_CLOSE_CONTAINER		("cryptsetup luksClose %s_container")
# define CMD_MOUNT_CONTAINER		("mount /dev/mapper/%s_container /home/%s/secure_data-rw")
# define CMD_UMOUNT_CONTAINER		("umount /home/%s/secure_data-rw")
# define CMD_CHANGE_CONTAINER_KEY	("printf \"%s\n%s\n%s\n\" | cryptsetup luksAddKey /home/%s/%s_container")
# define CMD_REMOVE_OLD_KEY		("printf \"%s\n\" | cryptsetup luksRemoveKey /home/%s/%s_container")

# include <stdbool.h>
# include <security/pam_modules.h>

void	cleanup(pam_handle_t *pamh, void *data, int error_status);

void	create_container(const char *usr, const char *pass);
bool	container_exists(const char *usr);
void	open_container(const char *usr, const char *pass);
void	close_container(const char *usr);
void	change_container_key(const char *usr, const char *old_pass, const char *new_pass);

#endif /* !PAMELA_H_ */
