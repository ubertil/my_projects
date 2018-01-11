#include <stdio.h>
#include "graphic/gui.h"
#include "graphic/font.h"

static int	get_nb_player_on_case(t_core *core, t_pos pos)
{
  int		ret;
  t_player	*p;

  ret = 0;
  p = core->player_list->head;
  while (p)
    {
      if ((p->pos.x == pos.x && p->pos.y == pos.y) ||
	  (p->pos.x == -1 && p->pos.y == -1))
	ret++;
      p = p->next;
    }
  return (ret);
}

static void	render_gui_client(t_core *core)
{
  t_player	*t;
  t_pos		pos;
  char		*buf;

  if ((t = get_from_id(core->player_list,
		       core->info->client_id_to_display)) == NULL)
    return ;
  asprintf(&buf, "DETAIL PLAYER (%s#%d)%s%d%s%d%s%d%s%d%s%d%s%d%s%d",
	   t->team,
	   core->info->client_id_to_display,
	   "\nLINEMATE  : ", t->inventory[0],
	   "\nDERAUMERE : ", t->inventory[1],
	   "\nSIBUR     : ", t->inventory[2],
	   "\nMENDIANE  : ", t->inventory[3],
	   "\nPHIRAS    : ", t->inventory[4],
	   "\nTHYSTAME  : ", t->inventory[5],
	   "\nFOOD      : ", t->inventory[6]);
  if (buf == NULL)
    return ;
  pos.x = MAP_SIZE + 20;
  pos.y = 10;
  render_font(core->screen, buf, core->font, pos);
  free(buf);
}

static void	render_gui_case(t_core *c)
{
  t_pos		t;
  t_pos		pos;
  char		*buf;

  t.x = c->info->pos_case_to_display.x;
  t.y = c->info->pos_case_to_display.y;
  asprintf(&buf, "DETAIL CASE (%d, %d)%s%d%s%d%s%d%s%d%s%d%s%d%s%d%s%d",
	   t.x + 1,
	   t.y + 1,
	   "\nLINEMATE  : ", c->map->items[t.x + t.y * c->map->width].data[0],
	   "\nDERAUMERE : ", c->map->items[t.x + t.y * c->map->width].data[1],
	   "\nSIBUR     : ", c->map->items[t.x + t.y * c->map->width].data[2],
	   "\nMENDIANE  : ", c->map->items[t.x + t.y * c->map->width].data[3],
	   "\nPHIRAS    : ", c->map->items[t.x + t.y * c->map->width].data[4],
	   "\nTHYSTAME  : ", c->map->items[t.x + t.y * c->map->width].data[5],
	   "\nFOOD      : ", c->map->items[t.x + t.y * c->map->width].data[6],
	   "\nPLAYER(S) : ", get_nb_player_on_case(c, t));
  if (buf == NULL)
    return ;
  pos.x = MAP_SIZE + 20;
  pos.y = 10;
  render_font(c->screen, buf, c->font, pos);
  free(buf);
}

void		render_gui(t_core *core)
{
  if (core->info->display_client)
    render_gui_client(core);
  else if (core->info->display_case)
    render_gui_case(core);
}
