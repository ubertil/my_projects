/*
** opcode.h for opcode in /home/uberti_l/rendu/Unix/PSU_2016_ftrace
**
** Made by Lous-Emile Uberti-Ares
** Login   <uberti_l@epitech.net>
**
** Started on  Sat May  6 18:11:52 2017 Lous-Emile Uberti-Ares
** Last update Sun May  7 14:37:56 2017 Lous-Emile Uberti-Ares
*/

#ifndef OPCODE_H_
# define OPCODE_H_

# define CALLNEAR 0xE8
# define CALLFAR 0xFF
# define RET 0xC3

typedef union	u_opcode
{
  long		val;
  unsigned char	addr[sizeof(long)];
}		t_opcode;

#endif /* !OPCODE_H_ */
