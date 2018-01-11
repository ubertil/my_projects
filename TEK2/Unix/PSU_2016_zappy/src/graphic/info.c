#include <stdlib.h>
#include "graphic/core.h"
#include "graphic/info.h"

void		handle_click(t_core *core,
			     SDL_MouseMotionEvent *pos)
{
  int32_t	pixel;

  core->info->display_client = false;
  core->info->display_case = false;
  if ((pixel = core->collision_buf[pos->x + pos->y * WIDTH]) == 0)
    {
      core->info->display_case = true;
      core->info->pos_case_to_display.x = (pos->x - 10) /
	(MAP_SIZE / core->map->width);
      core->info->pos_case_to_display.y = (pos->y - 10) /
	(MAP_SIZE / core->map->height);
    }
  else if (pixel > 0)
    {
      core->info->display_client = true;
      core->info->client_id_to_display = pixel;
    }
}

t_info		*init_info()
{
  t_info	*i;

  if ((i = malloc(sizeof(t_info))) == NULL)
    return (NULL);
  i->display_client = false;
  i->display_case = false;
  return (i);
}

void		free_info(t_info *info)
{
  free(info);
}
