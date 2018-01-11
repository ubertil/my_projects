#include <security/pam_modules.h>
#include <string.h>
#include <stdio.h>
#include "pamela.h"

extern int	pam_sm_authenticate(pam_handle_t *pamh, int flags,
				    int argc, const char **argv)
{
  const char	*usr = NULL;
  const char	*pass = NULL;
  int		ret;

  if ((ret = pam_get_item(pamh, PAM_USER, (const void **)&usr)) != PAM_SUCCESS)
    return (ret);
  if ((ret = pam_get_item(pamh, PAM_AUTHTOK, (const void **)&pass)) != PAM_SUCCESS)
    return (ret);
  if ((ret = pam_set_data(pamh, "pamela_pass", strdup(pass),
			  cleanup)) != PAM_SUCCESS)
    return (ret);
  if (!container_exists(usr))
    {
      printf("Creating an encrypted container...\n");
      create_container(usr, pass);
    }
  return (PAM_SUCCESS);
}

extern int	pam_sm_setcred(pam_handle_t *pamh, int flags,
			       int argc, const char **argv)
{
  return (PAM_SUCCESS);
}

extern int	pam_sm_acct_mgmt(pam_handle_t *pamh, int flags,
				 int argc, const char **argv)
{
  return (PAM_SUCCESS);
}

extern int	pam_sm_open_session(pam_handle_t *pamh, int flags,
				    int argc, const char **argv)
{
  const char	*usr = NULL;
  const char	*pass = NULL;
  int		ret;

  if ((ret = pam_get_item(pamh, PAM_USER, (const void **)&usr)) != PAM_SUCCESS)
    return (ret);
  if ((ret = pam_get_data(pamh, "pamela_pass", (const void **)&pass)) != PAM_SUCCESS)
    return (ret);
  printf("Opening your container...\n");
  open_container(usr, pass);
  return (PAM_SUCCESS);
}

extern int	pam_sm_close_session(pam_handle_t *pamh, int flags,
				     int argc, const char **argv)
{
  const char	*usr = NULL;
  int		ret;

  if ((ret = pam_get_item(pamh, PAM_USER, (const void **)&usr)) != PAM_SUCCESS)
    return (ret);
  close_container(usr);
  return (PAM_SUCCESS);
}

extern int	pam_sm_chauthtok(pam_handle_t *pamh, int flags,
				 int argc, const char **argv)
{
  const char	*usr = NULL;
  const char	*old_pass = NULL;
  const char	*new_pass = NULL;
  int		ret;

  if ((ret = pam_get_item(pamh, PAM_USER, (const void **)&usr)) != PAM_SUCCESS)
    return (ret);
  if ((ret = pam_get_item(pamh, PAM_OLDAUTHTOK, (const void **)&old_pass)) != PAM_SUCCESS)
    return (ret);
  if ((ret = pam_get_item(pamh, PAM_AUTHTOK, (const void **)&new_pass)) != PAM_SUCCESS)
    return (ret);
  if (old_pass == NULL || new_pass == NULL)
    return (PAM_BAD_ITEM);
  change_container_key(usr, old_pass, new_pass);
  return (PAM_SUCCESS);
}
