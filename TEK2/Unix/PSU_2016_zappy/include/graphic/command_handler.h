/*
** command_handler.h for command_handler.h in /home/nicolas.trognot/rendu/Reseau/PSU_2016_zappy/include/graphic
**
** Made by Nicolas TROGNOT
** Login   <nicolas.trognot@epitech.net>
**
** Started on  Thu Jun 29 11:09:11 2017 Nicolas TROGNOT
** Last update Thu Jun 29 11:09:15 2017 Nicolas TROGNOT
*/

#ifndef COMMAND_HANDLER_H_
# define COMMAND_HANDLER_H_
# define NB_CMDS_GRAPHIC 9
# include <stdbool.h>
# include "graphic/client.h"
# include "graphic/core.h"

typedef struct		s_command
{
  char			*command;
  bool			(*func)(t_core *core, char *str);
}			t_command;

bool			handle_current_command(t_core *core,
					       char *str);
bool			handle_commands(t_core *core);
bool			handle_msz(t_core *core, char *str);
bool			handle_bct(t_core *core, char *str);
bool			handle_pnw(t_core *core, char *str);
bool			handle_ppo(t_core *core, char *str);
bool			handle_tna(t_core *core, char *str);
bool			handle_pdi(t_core *core, char *str);
bool			handle_plv(t_core *core, char *str);
bool			handle_pin(t_core *core, char *str);
bool			handle_pgt(t_core *core, char *str);

#endif /* !COMMAND_HANDLER_H_ */
