/*
** main.c for main in /home/uberti_l/rendu/Prog_elem/CPE_2015_Lemin/bonus
**
** Made by louis-emile uberti-ares
** Login   <uberti_l@epitech.net>
**
** Started on  Wed Apr 20 15:17:00 2016 louis-emile uberti-ares
** Last update Sun Apr 24 13:15:11 2016 louis-emile uberti-ares
*/

#include "visu.h"

int			show_help()
{
  my_putstr("Welcome on the help section of this lemin bonus !\n");
  my_putstr("This bonus is a graphical interface displaying the ants ");
  my_putstr("movement.\nProgram built using liblapin 1.7 by Jason.\n");
  my_putstr("\033[01;31m");
  my_putstr("Usage : ./lem_in < [MAP] | ./visu [OPTION]\n\n");
  my_putstr("\033[01;32m");
  my_putstr("Options : --help\tDisplay this page\n\t  --abel\t");
  my_putstr("Because we love him ");
  my_putstr("\033[01;31m<3\033[00m\n\n");
  my_putstr("Developped by Come GRELLARD, Nicolas TROGNOT, Nicolas WADEL");
  my_putstr(" and Louis-Emile UBERTI\n");
  return (0);
}

void			delete_all_clipables(t_visu *visu)
{
  bunny_delete_clipable(&visu->pix->clipable);
  bunny_delete_clipable(&visu->ant->clipable);
  bunny_delete_clipable(&visu->screen->clipable);
  bunny_delete_clipable(&visu->room->clipable);
  bunny_delete_clipable(&visu->room_end->clipable);
}

t_bunny_response	events(t_bunny_event_state state,
			       t_bunny_keysym key,
			       void *_visu)
{
  t_visu		*visu;

  visu = _visu;
  if (state == GO_DOWN)
    {
      if (key == BKS_ESCAPE)
	return (EXIT_ON_SUCCESS);
      if (key == BKS_SPACE)
	visu->start_rendu = 1;
    }
  return (GO_ON);
}

t_bunny_response	main_loop(void *_visu)
{
  t_visu		*visu;

  visu = _visu;
  if (visu->start_rendu == 1)
    {
      if (move_all_ants(visu) == -1)
	return (EXIT_ON_SUCCESS);
    }
  else
    {
      bunny_blit(&visu->win->buffer, &visu->screen->clipable, NULL);
      bunny_display(visu->win);
    }
  return (GO_ON);
}

int		main(int ac, char **av)
{
  t_visu	*visu;

  if (ac == 2 && my_strcmp(av[1], "--help") == 0)
    return (show_help());
  if ((visu = bunny_malloc(sizeof(t_visu))) == NULL)
    return (-1);
  visu->start_rendu = 0;
  if (!(visu->win = bunny_start(WIDTH, HEIGHT, false, "LEMIN DISPLAYER"))
      || (!(visu->pix = bunny_new_pixelarray(WIDTH, HEIGHT)))
      || (check_args(visu) == -1) || (load_ant(visu, av[1]) == -1)
      || (load_screen(visu, av[1]) == -1) || (start_music(visu, av[1]) == -1)
      || (init_ant_struct(visu) == -1))
    return (-1);
  visu->rooms = reverse_rooms(visu->rooms);
  bunny_set_key_response(events);
  bunny_set_loop_main_function(main_loop);
  bunny_loop(visu->win, 60, visu);
  close_music(visu);
  delete_all_clipables(visu);
  free_all(visu);
  return (0);
}
