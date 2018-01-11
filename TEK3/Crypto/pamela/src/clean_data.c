#include <security/pam_modules.h>
#include <stdlib.h>

void	cleanup(pam_handle_t *pam, void *data, int error_status)
{
  char	*str;

  if (!data)
    return ;
  free(data);
}
