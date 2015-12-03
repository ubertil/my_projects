/*
** cypher.h for cypher in /home/uberti_l/rendu/102cipher/include
**
** Made by louis-emile uberti-ares
** Login   <uberti_l@epitech.net>
**
** Started on  Mon Nov 16 10:54:03 2015 louis-emile uberti-ares
** Last update Sun Nov 29 19:13:28 2015 Nicolas Wadel
*/

#ifndef CIPHER_H_
# define CIPHER_H_

typedef struct	s_stock
{
  char		*message;
  int		*matrix_message;
  int		size_av1;
  int		mode;
  int		*matrix;
  int		matrix_row;
  char		*keyword;
  char		*key_matrix;
  int		*encry_msg;
  char		*decry_msg;
  float		*decry_matrix;
}		t_stock;

int		my_strlen(char *str);
int		my_init(char **av);
void		my_mode_encry(t_stock *a);
void		my_mode_decry(t_stock *a);
void		key_super_matrix(t_stock *a);
void		super_encryption(t_stock *a);
void		super_decryption(t_stock *a);

#endif /* !CIPHER_H */
