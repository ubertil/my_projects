/*
** client.h for client in /home/uberti_l/rendu/Unix/PSU_2015_minitalk/client/include
**
** Made by louis-emile uberti-ares
** Login   <uberti_l@epitech.net>
**
** Started on  Mon Feb  1 11:42:11 2016 louis-emile uberti-ares
** Last update Tue Feb  2 15:38:40 2016 louis-emile uberti-ares
*/

#ifndef CLIENT_H_
# define CLIENT_H_

void		my_putchar(char c);
void		ascii_to_binary(char *str, int pid);
int		my_power_it(int nbr, int power);
int		my_putstr_err(char *str);
int		my_putstr(char *str);
int		my_strlen(char *str);
int		my_getnbr(char *str);
char		*my_strdup(char *src);

#endif /* !CLIENT_H_ */
