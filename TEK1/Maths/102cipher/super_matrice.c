/*
** super_matrice.c for super_matrice in /home/wadel_n/rendu/102cipher
**
** Made by Nicolas Wadel
** Login   <wadel_n@epitech.net>
**
** Started on  Sat Nov 28 07:54:06 2015 Nicolas Wadel
** Last update Sun Nov 29 22:36:20 2015 Nicolas Wadel
*/
#include "include/cipher.h"
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

void	key_super_matrix(t_stock *a)
{
  int	idx;

  idx = 0;
  a->matrix_row = 4;
  a->matrix  = malloc(4 * sizeof(int));
  while (idx < 16)
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
      printf("%d\t%d\t%d\t%d\n", a->matrix[idx], a->matrix[idx + 1], a->matrix[idx + 2], a->matrix[idx + 3]);
      idx = idx + 4;
      a->matrix_row = a->matrix_row - 1;
    }
}

void	super_encryption(t_stock *a)
{
  int	i;
  int	idx;
  int	space;

  space = 0;
  i = 0;
  idx = 0;
  while (i < my_strlen(a->message))
    {
      if (space != 0)
	printf(" ");
      a->encry_msg[idx] = ((a->matrix_message[i] * a->matrix[0])
			   + (a->matrix_message[i + 1] * a->matrix[4])
			   + (a->matrix_message[i + 2] * a->matrix[8])
			   + (a->matrix_message[i + 3] * a->matrix[12]));
      printf("%d", a->encry_msg[idx]);
      space = space + 1;
      if (space != 0)
	printf(" ");
      idx = idx + 1;
      a->encry_msg[idx] = ((a->matrix_message[i] * a->matrix[1])
			   + (a->matrix_message[i + 1] * a->matrix[5])
			   + (a->matrix_message[i + 2] * a->matrix[9])
			   + (a->matrix_message[i + 3] * a->matrix[13]));
      printf("%d", a->encry_msg[idx]);
      if (space != 0)
	printf(" ");
      idx = idx + 1;
      a->encry_msg[idx] = ((a->matrix_message[i] * a->matrix[2])
			   + (a->matrix_message[i + 1] * a->matrix[6])
			   + (a->matrix_message[i + 2] * a->matrix[10])
			   + (a->matrix_message[i + 3] * a->matrix[14]));
      printf("%d", a->encry_msg[idx]);
      if (space != 0)
	printf(" ");
      idx = idx + 1;
      a->encry_msg[idx] = ((a->matrix_message[i] * a->matrix[3])
			   + (a->matrix_message[i + 1] * a->matrix[7])
			   + (a->matrix_message[i + 2] * a->matrix[11])
			   + (a->matrix_message[i + 3] * a->matrix[15]));
      printf("%d", a->encry_msg[idx]);
      idx = idx + 1;
      i = i + 4;
    }
}

void	super_determinant(t_stock *a)
{
  int	determinant;
  float	value[16];
  int	inversion[16];
  int	i;
  int	idx;

  i = 0;
  determinant = ((a->matrix[0] * a->matrix[5] * a->matrix[10] * a->matrix[15])
		 + (a->matrix[0] * a->matrix[6] * a->matrix[11] * a->matrix[13])
		 + (a->matrix[0] * a->matrix[7] * a->matrix[9] * a->matrix[14])
		 + (a->matrix[1] * a->matrix[4] * a->matrix[11] * a->matrix[14])
		 + (a->matrix[1] * a->matrix[6] * a->matrix[8] * a->matrix[15])
		 + (a->matrix[1] * a->matrix[7] * a->matrix[10] * a->matrix[12])
		 + (a->matrix[2] * a->matrix[4] * a->matrix[9] * a->matrix[15])
		 + (a->matrix[2] * a->matrix[5] * a->matrix[11] * a->matrix[12])
		 + (a->matrix[2] * a->matrix[7] * a->matrix[8] * a->matrix[13])
		 + (a->matrix[3] * a->matrix[4] * a->matrix[10] * a->matrix[13])
		 + (a->matrix[3] * a->matrix[5] * a->matrix[8] * a->matrix[14])
		 + (a->matrix[3] * a->matrix[6] * a->matrix[9] * a->matrix[12])
		 - (a->matrix[0] * a->matrix[5] * a->matrix[11] * a->matrix[14])
		 - (a->matrix[0] * a->matrix[6] * a->matrix[9] * a->matrix[15])
		 - (a->matrix[0] * a->matrix[7] * a->matrix[10] * a->matrix[13])
		 - (a->matrix[1] * a->matrix[4] * a->matrix[10] * a->matrix[15])
		 - (a->matrix[1] * a->matrix[6] * a->matrix[11] * a->matrix[12])
		 - (a->matrix[1] * a->matrix[7] * a->matrix[8] * a->matrix[14])
		 - (a->matrix[2] * a->matrix[4] * a->matrix[11] * a->matrix[13])
		 - (a->matrix[2] * a->matrix[5] * a->matrix[8] * a->matrix[15])
		 - (a->matrix[2] * a->matrix[7] * a->matrix[9] * a->matrix[12])
		 - (a->matrix[3] * a->matrix[4] * a->matrix[9] * a->matrix[14])
		 - (a->matrix[3] * a->matrix[5] * a->matrix[10] * a->matrix[12])
		 - (a->matrix[3] * a->matrix[6] * a->matrix[8] * a->matrix[13]));
  if (determinant == 0)
    {
      printf("Error : No matrix inersion possible\n");
      exit (84);
    }
  printf("Key matrix :\n");
  i = 0;
  inversion[0] = ((a->matrix[5] * a->matrix[10] * a->matrix[15])
		  + (a->matrix[6] * a->matrix[11] * a->matrix[13])
		  + (a->matrix[7] * a->matrix[9] * a->matrix[14])
		  - (a->matrix[5] * a->matrix[11] * a->matrix[14])
		  - (a->matrix[6] * a->matrix[9] * a->matrix[15])
		  - (a->matrix[7] * a->matrix[10] * a->matrix[13]));
  inversion[1] = ((a->matrix[1] * a->matrix[11] * a->matrix[14])
		  + (a->matrix[2] * a->matrix[9] * a->matrix[15])
		  + (a->matrix[3] * a->matrix[10] * a->matrix[13])
		  - (a->matrix[1] * a->matrix[10] * a->matrix[15])
		  - (a->matrix[2] * a->matrix[11] * a->matrix[13])
		  - (a->matrix[3] * a->matrix[9] * a->matrix[14]));
  inversion[2] = ((a->matrix[1] * a->matrix[6] * a->matrix[15])
		  + (a->matrix[2] * a->matrix[7] * a->matrix[13])
		  + (a->matrix[3] * a->matrix[5] * a->matrix[14])
		  - (a->matrix[1] * a->matrix[7] * a->matrix[14])
		  - (a->matrix[2] * a->matrix[5] * a->matrix[15])
		  - (a->matrix[3] * a->matrix[6] * a->matrix[13]));
  inversion[3] = ((a->matrix[1] * a->matrix[7] * a->matrix[10])
		  + (a->matrix[2] * a->matrix[5] * a->matrix[11])
		  + (a->matrix[3] * a->matrix[6] * a->matrix[9])
		  - (a->matrix[1] * a->matrix[6] * a->matrix[11])
		  - (a->matrix[2] * a->matrix[7] * a->matrix[9])
		  - (a->matrix[3] * a->matrix[5] * a->matrix[10]));
  inversion[4] = ((a->matrix[4] * a->matrix[11] * a->matrix[14])
		  + (a->matrix[6] * a->matrix[8] * a->matrix[15])
		  + (a->matrix[7] * a->matrix[10] * a->matrix[12])
		  - (a->matrix[4] * a->matrix[10] * a->matrix[15])
		  - (a->matrix[6] * a->matrix[11] * a->matrix[12])
		  - (a->matrix[7] * a->matrix[8] * a->matrix[14]));
  inversion[5] = ((a->matrix[0] * a->matrix[10] * a->matrix[15])
		  + (a->matrix[2] * a->matrix[11] * a->matrix[12])
		  + (a->matrix[3] * a->matrix[8] * a->matrix[14])
		  - (a->matrix[0] * a->matrix[11] * a->matrix[14])
		  - (a->matrix[2] * a->matrix[9] * a->matrix[15])
		  - (a->matrix[3] * a->matrix[10] * a->matrix[12]));
  inversion[6] = ((a->matrix[0] * a->matrix[7] * a->matrix[14])
		  + (a->matrix[2] * a->matrix[4] * a->matrix[15])
		  + (a->matrix[3] * a->matrix[6] * a->matrix[12])
		  - (a->matrix[0] * a->matrix[6] * a->matrix[15])
		  - (a->matrix[2] * a->matrix[7] * a->matrix[12])
		  - (a->matrix[3] * a->matrix[4] * a->matrix[14]));
  inversion[7] = ((a->matrix[0] * a->matrix[6] * a->matrix[11])
		  + (a->matrix[2] * a->matrix[7] * a->matrix[8])
		  + (a->matrix[3] * a->matrix[4] * a->matrix[10])
		  - (a->matrix[0] * a->matrix[7] * a->matrix[10])
		  - (a->matrix[2] * a->matrix[4] * a->matrix[11])
		  - (a->matrix[3] * a->matrix[6] * a->matrix[8]));
  inversion[8] = ((a->matrix[4] * a->matrix[9] * a->matrix[15])
		  + (a->matrix[5] * a->matrix[11] * a->matrix[12])
		  + (a->matrix[7] * a->matrix[8] * a->matrix[13])
		  - (a->matrix[4] * a->matrix[11] * a->matrix[13])
		  - (a->matrix[5] * a->matrix[8] * a->matrix[15])
		  - (a->matrix[7] * a->matrix[9] * a->matrix[12]));
  inversion[9] = ((a->matrix[0] * a->matrix[11] * a->matrix[13])
		  + (a->matrix[1] * a->matrix[8] * a->matrix[15])
		  + (a->matrix[3] * a->matrix[9] * a->matrix[12])
		  - (a->matrix[0] * a->matrix[9] * a->matrix[15])
		  - (a->matrix[1] * a->matrix[11] * a->matrix[12])
		  - (a->matrix[3] * a->matrix[8] * a->matrix[13]));
  inversion[10] = ((a->matrix[0] * a->matrix[5] * a->matrix[15])
		  + (a->matrix[1] * a->matrix[7] * a->matrix[12])
		  + (a->matrix[3] * a->matrix[4] * a->matrix[13])
		  - (a->matrix[0] * a->matrix[7] * a->matrix[13])
		  - (a->matrix[1] * a->matrix[4] * a->matrix[15])
		  - (a->matrix[3] * a->matrix[5] * a->matrix[12]));
  inversion[11] = ((a->matrix[0] * a->matrix[7] * a->matrix[9])
		  + (a->matrix[1] * a->matrix[4] * a->matrix[11])
		  + (a->matrix[3] * a->matrix[5] * a->matrix[8])
		  - (a->matrix[0] * a->matrix[5] * a->matrix[11])
		  - (a->matrix[1] * a->matrix[7] * a->matrix[8])
		  - (a->matrix[3] * a->matrix[4] * a->matrix[9]));
  inversion[12] = ((a->matrix[4] * a->matrix[10] * a->matrix[13])
		  + (a->matrix[5] * a->matrix[8] * a->matrix[14])
		  + (a->matrix[6] * a->matrix[9] * a->matrix[12])
		  - (a->matrix[4] * a->matrix[9] * a->matrix[14])
		  - (a->matrix[5] * a->matrix[10] * a->matrix[12])
		  - (a->matrix[6] * a->matrix[8] * a->matrix[13]));
  inversion[13] = ((a->matrix[0] * a->matrix[9] * a->matrix[14])
		  + (a->matrix[1] * a->matrix[10] * a->matrix[12])
		  + (a->matrix[2] * a->matrix[8] * a->matrix[13])
		  - (a->matrix[0] * a->matrix[10] * a->matrix[13])
		  - (a->matrix[1] * a->matrix[8] * a->matrix[14])
		  - (a->matrix[2] * a->matrix[9] * a->matrix[12]));
  inversion[14] = ((a->matrix[0] * a->matrix[6] * a->matrix[13])
		  + (a->matrix[1] * a->matrix[4] * a->matrix[14])
		  + (a->matrix[2] * a->matrix[5] * a->matrix[12])
		  - (a->matrix[0] * a->matrix[5] * a->matrix[14])
		  - (a->matrix[1] * a->matrix[6] * a->matrix[12])
		  - (a->matrix[2] * a->matrix[4] * a->matrix[13]));
  inversion[15] = ((a->matrix[0] * a->matrix[5] * a->matrix[10])
		  + (a->matrix[1] * a->matrix[6] * a->matrix[8])
		  + (a->matrix[2] * a->matrix[4] * a->matrix[9])
		  - (a->matrix[0] * a->matrix[6] * a->matrix[9])
		  - (a->matrix[1] * a->matrix[4] * a->matrix[10])
		  - (a->matrix[2] * a->matrix[5] * a->matrix[8]));
  i = 0;
  while (i < 16)
    {
      if (inversion[i] == 0)
	{
	  value[i] = 0;
	  i = i + 1;
	}
      else
	{
	  value[i] = ((float)inversion[i] / (float)determinant);
	  i = i + 1;
	}
    }
  i = 0;
  while (i < 16)
    {
      if (value[i] == 0 && (i != 3 || i != 7 || i != 11 || i != 15))
	printf("0.0\t");
      else if (value[i] == 0 && ( i == 3 || i == 7 || i == 11 || i == 15))
	printf("0.0\n");
      else
	{
	  if ( i == 3 || i == 7 || i == 11 || i == 15)
	    printf("%0.3f\n", value[i]);
	  else
	    printf("%0.3f\t", value[i]);
	}
      i = i + 1;
    }
  i = 0;
  idx = 0;
  printf("\nDecrypted message :\n");
  while (idx < a->size_av1)
    {
      a->message[idx] = round(((value[0] * a->matrix_message[i])
			       + (value[4] * a->matrix_message[i + 1])
			       + (value[8] * a->matrix_message[i + 2])
			       + (value[12] * a->matrix_message[i + 3])));
      printf("%c", a->message[idx]);
      idx = idx + 1;
      a->message[idx] = round(((value[1] * a->matrix_message[i])
			       + (value[5] * a->matrix_message[i + 1])
			       + (value[9] * a->matrix_message[i + 2])
			       + (value[13] * a->matrix_message[i + 3])));
      printf("%c", a->message[idx]);
      idx = idx + 1;
      a->message[idx] = round(((value[2] * a->matrix_message[i])
			       + (value[6] * a->matrix_message[i + 1])
			       + (value[10] * a->matrix_message[i + 2])
			       + (value[14] * a->matrix_message[i + 3])));
      printf("%c", a->message[idx]);
      idx = idx + 1;
      a->message[idx] = round(((value[3] * a->matrix_message[i])
			       + (value[7] * a->matrix_message[i + 1])
			       + (value[11] * a->matrix_message[i + 2])
			       + (value[15] * a->matrix_message[i + 3])));
      printf("%c", a->message[idx]);
      idx = idx + 1;
      i = i + 4;
    }
  printf("\n");
}

void	super_decryption(t_stock *a)
{
  super_determinant(a);
}
