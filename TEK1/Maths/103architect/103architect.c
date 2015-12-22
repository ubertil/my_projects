/*
** 103architect.c for 103architect.c in /home/trogno_n/rendu/103test
**
** Made by nicolas trognot
** Login   <trogno_n@epitech.net>
**
** Started on  Wed Dec  9 12:34:00 2015 nicolas trognot
** Last update Tue Dec 15 17:19:16 2015 louis-emile uberti-ares
*/

#include "include/architect.h"
#include <stdlib.h>
#include <stdio.h>
#include <math.h>

float		cosd(int angle)
{
  return (cos(angle * (M_PI / 180)));
}

float		sind(int angle)
{
  return (sin(angle * (M_PI / 180)));
}

void	do_symmetry(t_info *info)
{
  printf("Symmetry about an axis inclined with an angle of %d degrees\n", (int)info->numbers->next->next->number);
  if (info->disp_matrix == 1)
    {
      printf("%0.2f\t%0.2f\t%0.2f\n%0.2f\t%0.2f\t%0.2f\n%0.2f\t%0.2f\t%0.2f\n",
	     cos(2 * info->numbers->next->next->number * M_PI/180), sin(2 * info->numbers->next->next->number *M_PI/180), (float)0,
	     sin(2 * info->numbers->next->next->number * M_PI/180), -cos(2 * info->numbers->next->next->number * M_PI/180), (float)0,
	     (float)0, (float)0, (float)1);
    }
  else
    delete(info, 's');
  return (0);
}

int	rotation_m(int a)
{
  printf("%0.2f\t%0.2f\t%0.2f\n%0.2f\t%0.2f\t%0.2f\n%0.2f\t%0.2f\t%0.2f\n",
	 cosd(a), -sind(a), 0.0, sind(a), cosd(a), 0.0, 0.0, 0.0, 1.0);
}

int	do_rotation(t_info *info)
{
  int	old_x;
  int	old_y;

  old_x = info->numbers->number;
  old_y = info->numbers->next->number;
  info->numbers->number =
    (cosd(info->numbers->next->next->number) * old_y);
  info->numbers->next->number =
    (sind(info->numbers->next->next->number) * old_x);
  printf("Rotation at a %d degree angle\n", (int)info->numbers->next->next->number);
  if (info->disp_matrix == 1)
    {
      rotation_m(info->numbers->next->next->number);
      printf("(%d,%d) => (%0.2f,%0.2f)\n",
	     (int)old_x,
	     (int)old_y,
	     info->numbers->number,
	     info->numbers->next->number);
    }
  else
    delete(info, 'r');
  return (0);
}

int	homothety_m(int m, int n)
{
  printf("%0.2f\t%0.2f\t%0.2f\n%0.2f\t%0.2f\t%0.2f\n%0.2f\t%0.2f\t%0.2f\n",
	 (float)m, 0.0, 0.0, 0.0, (float)n, 0.0, 0.0, 0.0, 1.0);
}

int	do_homothety(t_info *info)
{
  int	old_x;
  int	old_y;

  old_x = info->numbers->number;
  old_y = info->numbers->next->number;
  info->numbers->number =
    info->numbers->number * info->numbers->next->next->number;
  info->numbers->next->number =
    info->numbers->next->number * info->numbers->next->next->next->number;
  printf("Homothety by the ratios %d and %d\n",
	 (int)info->numbers->next->next->number,
	 (int)info->numbers->next->next->next->number);
  if (info->disp_matrix == 1)
    {
      homothety_m(info->numbers->next->next->number,
		  info->numbers->next->next->next->number);
      printf("(%d,%d) => (%0.2f,%0.2f)\n",
	     (int)old_x,
	     (int)old_y,
	     (float)(info->numbers->number),
	     (float)(info->numbers->next->number));
    }
  else
    delete(info, 'h');
  return (0);
}

int	translation_m(int i, int j)
{
  printf("%0.2f\t%0.2f\t%0.2f\n%0.2f\t%0.2f\t%0.2f\n%0.2f\t%0.2f\t%0.2f\n",
	 1.0, 0.0, (float)(i), 0.0, 1.0, (float)(j), 0.0, 0.0, 1.0);
}

int	do_translation(t_info *info)
{
  float	old_x;
  float	old_y;

  old_x = info->numbers->number;
  old_y = info->numbers->next->number;
  info->numbers->number = info->numbers->number +
    info->numbers->next->next->number;
  info->numbers->next->number = info->numbers->next->number +
    info->numbers->next->next->next->number;
  printf("Translation by the vector (%d, %d)\n",
	 (int)info->numbers->next->next->number,
	 (int)info->numbers->next->next->next->number);
  if (info->disp_matrix == 1)
    {
      translation_m(info->numbers->next->next->number,
		    info->numbers->next->next->next->number);
      printf("(%d,%d) => (%0.2f,%0.2f)\n",
	     (int)old_x,
	     (int)old_y,
	     (float)(info->numbers->number),
	     (float)(info->numbers->next->number));
    }
  else
    delete(info, 't');
  return (0);
}
