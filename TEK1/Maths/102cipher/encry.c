/*
** encry.c for encry.c in /home/uberti_l/rendu/102cipher
**
** Made by louis-emile uberti-ares
** Login   <uberti_l@epitech.net>
**
** Started on  Mon Nov 16 11:34:33 2015 louis-emile uberti-ares
** Last update Sat Nov 28 19:43:37 2015 Nicolas Wadel
*/

#include <stdio.h>
#include <stdlib.h>
#include "include/cipher.h"

void		my_disp_keymatrix(t_stock *a)
{
  int		idx;

  idx = 0;
  printf("Key matrix :\n");
  if (my_strlen(a->keyword) <= 4)
    {
      a->matrix_row = 2;
      a->matrix = malloc(2 * sizeof(int));
      while (idx != a->matrix_row * 2)
	{
	  if (idx > my_strlen(a->keyword))
	    a->matrix[idx] = 0;
	  else
	    a->matrix[idx] = a->keyword[idx];
	  idx = idx + 1;
	}
      idx = 0;
      while (a->matrix_row != 0)
	{
	  printf("%d\t%d\n", a->matrix[idx], a->matrix[idx + 1]);
	  idx = idx + 2;
	  a->matrix_row = a->matrix_row - 1;
	}
    }
  else if (my_strlen(a->keyword) > 4 && my_strlen(a->keyword) <= 9)
    {
      a->matrix_row = 3;
      a->matrix = malloc(3 * sizeof(int));
      while (idx != a->matrix_row * 3)
	{
	  if (idx > my_strlen(a->keyword))
	    {
	      a->matrix[idx] = 0;
	      idx = idx + 1;
	    }
	  else
	    {
	      a->matrix[idx] = a->keyword[idx];
	      idx = idx + 1;
	    }
	}
      idx = 0;
      while (a->matrix_row != 0)
	{
	  printf("%d\t%d\t%d\n", a->matrix[idx], a->matrix[idx + 1], a->matrix[idx + 2]);
	  idx = idx + 3;
	  a->matrix_row = a->matrix_row - 1;
	}
    }
  else if (my_strlen(a->keyword) > 9 && my_strlen(a->keyword) <= 16)
    key_super_matrix(a);
}

void		my_disp_encrypted_msg(t_stock *a)
{
  int		i;
  int		idx;
  int		space;

  space = 0;
  i = 0;
  idx = 0;
  printf("\nEncrypted message :\n");
  if (my_strlen(a->keyword) <= 4)
    {
      while (i < my_strlen(a->message))
	{
	  if (space != 0)
	    printf(" ");
	  a->encry_msg[idx] = (a->matrix_message[i] * a->matrix[0])
	    + (a->matrix_message[i + 1] * a->matrix[2]);
	  printf("%d", a->encry_msg[idx]);
	  space = space + 1;
	  if (space != 0)
	    printf(" ");
	  idx = idx + 1;
	  a->encry_msg[idx] = (a->matrix_message[i] * a->matrix[1])
	    + (a->matrix_message[i + 1] * a->matrix[3]);
	  printf("%d", a->encry_msg[idx]);
	  i = i + 2;
	  idx = idx + 1;
	}
    }
  else if (my_strlen(a->keyword) > 4 && my_strlen(a->keyword) <= 9)
    {
      while (i < my_strlen(a->message))
	{
	  if (space != 0)
	    printf(" ");
	  a->encry_msg[idx] = ((a->matrix[0] * a->matrix_message[i])
			       + (a->matrix[3] * a->matrix_message[i + 1])
			       + (a->matrix[6] * a->matrix_message[i + 2]));
	  printf("%d", a->encry_msg[idx]);
	  space = space + 1;
	  idx = idx + 1;
	  if (space != 0)
	    printf(" ");
	  a->encry_msg[idx] = ((a->matrix[1] * a->matrix_message[i])
			       + (a->matrix[4] * a->matrix_message[i + 1])
			       + (a->matrix[7] * a->matrix_message[i + 2]));
	  printf("%d", a->encry_msg[idx]);
	  idx = idx +  1;
	  if (space != 0)
	    printf(" ");
	  a->encry_msg[idx] = ((a->matrix[2] * a->matrix_message[i])
			       + (a->matrix[5] * a->matrix_message[i + 1])
			       + (a->matrix[8] * a->matrix_message[i + 2]));
	  printf("%d", a->encry_msg[idx]);
	  idx = idx + 1;
	  i = i + 3;
	}
    }
  else
    super_encryption(a);
  printf("\n");
}

void		my_mode_encry(t_stock *a)
{
  my_disp_keymatrix(a);
  my_disp_encrypted_msg(a);
  free(a);
}
