/*
** decry.c for decry in /home/uberti_l/rendu/102cipher
**
** Made by louis-emile uberti-ares
** Login   <uberti_l@epitech.net>
**
** Started on  Mon Nov 16 13:41:18 2015 louis-emile uberti-ares
** Last update Sun Nov 29 22:29:17 2015 Nicolas Wadel
*/

#include <stdio.h>
#include <stdlib.h>
#include "include/cipher.h"
#include <math.h>

void		get_matrix(t_stock *a)
{
  int		idx;

  idx = 0;
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
    }
  else if (my_strlen(a->keyword) > 4 && my_strlen(a->keyword) <= 9)
    {
      a->matrix_row = 3;
      a->matrix = malloc(3 * sizeof(int));
      while (idx != a->matrix_row * 3)
	{
	  if (idx > my_strlen(a->keyword))
	    a->matrix[idx] = 0;
	  else
	    a->matrix[idx] = a->keyword[idx];
	  idx = idx + 1;
	}
    }
  else
    {
      a->matrix_row = 4;
      a->matrix = malloc(4 * sizeof(int));
      while (idx != a->matrix_row * 4)
	{
	  if (idx > my_strlen(a->keyword))
	    a->matrix[idx] = 0;
	  else
	    a->matrix[idx] = a->keyword[idx];
	  idx = idx + 1;
	}
      idx = 0;
    }
}

void		other_matrix(t_stock *a)
{
  float		determinant;
  float		inversion[9];
  int		i;
  float		value[9];
  int		idx;

  determinant = a->matrix[0] * a->matrix[4] * a->matrix[8];
  determinant = determinant + (a->matrix[1] * a->matrix[5] * a->matrix[6]);
  determinant = determinant + (a->matrix[2] * a->matrix[3] * a->matrix[7]);
  determinant = determinant - (a->matrix[2] * a->matrix[4] * a->matrix[6]);
  determinant = determinant - (a->matrix[5] * a->matrix[7] * a->matrix[0]);
  determinant = determinant - (a->matrix[8] * a->matrix[1] * a->matrix[3]);
  if (determinant == 0)
    {
      printf("Error : No matrix inversion possible\n");
      exit (84);
    }
  i = 0;
  printf("Key matrix :\n");
  inversion[0] = (a->matrix[4] * a->matrix[8]) - (a->matrix[5] * a->matrix[7]);
  inversion[1] = (a->matrix[2] * a->matrix[7]) - (a->matrix[1] * a->matrix[8]);
  inversion[2] = (a->matrix[1] * a->matrix[5]) - (a->matrix[2] * a->matrix[4]);
  inversion[3] = (a->matrix[5] * a->matrix[6]) - (a->matrix[3] * a->matrix[8]);
  inversion[4] = (a->matrix[0] * a->matrix[8]) - (a->matrix[2] * a->matrix[6]);
  inversion[5] = (a->matrix[2] * a->matrix[3]) - (a->matrix[0] * a->matrix[5]);
  inversion[6] = (a->matrix[3] * a->matrix[7]) - (a->matrix[4] * a->matrix[6]);
  inversion[7] = (a->matrix[1] * a->matrix[6]) - (a->matrix[0] * a->matrix[7]);
  inversion[8] = (a->matrix[0] * a->matrix[4]) - (a->matrix[1] * a->matrix[3]);
  while (i < 9)
    {
      if (inversion[i] == 0)
	{
	  value[i] = 0;
	  i = i + 1;
	}
      else
	{
	  value[i] = (1 / determinant) * inversion[i];
	  i = i + 1;
	}
    }
  i = 0;
  while (i < 9)
    {
      if (value[i] == 0 && (i == 0 || i == 1 || i == 3 || i == 4 || i == 6 || i == 7))
	printf("0.0\t");
      else if (value [i] == 0 && (i != 0 || i != 1 || i != 3 || i != 4 || i != 6 || i != 7))
	printf("0.0\n");
      else
	{
	  if (i == 0 || i == 1 || i == 3 || i == 4 || i == 6 || i == 7)
	    printf("%0.3f\t", value[i]);
	  else
	    printf("%0.3f\n", value[i]);
	}
      i = i + 1;
    }
  i = 0;
  idx = 0;
  printf("\nDecrypted message :\n");
  while (idx < a->size_av1)
    {
      a->message[idx] = round(((value[0] * a->matrix_message[i])
			       + (value[3] * a->matrix_message[i + 1])
			       + (value[6] * a->matrix_message[i + 2])));
      printf("%c", a->message[idx]);
      idx = idx + 1;
      a->message[idx] = round(((value[1] * a->matrix_message[i])
			       + (value[4] * a->matrix_message[i + 1])
			       + (value[7] * a->matrix_message[i + 2])));
      printf("%c", a->message[idx]);
      idx = idx + 1;
      a->message[idx] = round(((value[2] * a->matrix_message[i])
			       + (value[5] * a->matrix_message[i + 1])
			       + (value[8] * a->matrix_message[i + 2])));
      printf("%c", a->message[idx]);
      idx = idx + 1;
      i = i + 3;
    }
  printf("\n");
}

void		square_matrix(t_stock *a)
{
  float		determinant;
  float		inversion[4];
  int		value;
  int		i;
  int		tmp;
  int		k;

  i = 0;
  value = ((a->matrix[0] * a->matrix[3]) - (a->matrix[1] * a->matrix[2]));
  if (value == 0)
    {
      printf("Error : No matrix inversion possible\n");
      exit(84);
    }
  determinant = (float)1 / value;
  tmp = a->matrix[0];
  a->matrix[0] = a->matrix[3];
  a->matrix[3] = tmp;
  a->matrix[2] = -a->matrix[2];
  a->matrix[1] = -a->matrix[1];
  printf("Key matrix :\n");
  while (i < 4)
    {
      inversion[i] = (a->matrix[i] * determinant);
      if (inversion[i] == 0 && (i == 0 || i == 2))
	printf("0.0\t");
      else if (inversion [i] == 0 && (i != 0 || i != 1))
	printf("0.0\n");
      else
	{
	  if (i == 0 || i == 2)
	    printf("%0.3f\t", inversion[i]);
	  else
	    printf("%0.3f\n", inversion[i]);
	}
      i = i + 1;
    }
  printf("Decrypted message :\n");
  i = 0;
  k = 0;
  while (k < a->size_av1)
    {
      a->message[k] = round(((inversion[0] * a->matrix_message[i])
			     + (inversion[2] * a->matrix_message[i + 1])));
      printf("%c", a->message[k]);
      k = k + 1;
      a->message[k] = round(((inversion[1] * a->matrix_message[i])
			     + (inversion[3] * a->matrix_message[i + 1])));
      printf("%c", a->message[k]);
      k = k + 1;
      i = i + 2;
    }
  printf("\n");
}

void		my_mode_decry(t_stock *a)
{
  get_matrix(a);
  if (my_strlen(a->keyword) <= 4)
    square_matrix(a);
  else if (my_strlen(a->keyword) > 4 && my_strlen(a->keyword) <= 9)
    other_matrix(a);
  else
    super_decryption(a);
}
