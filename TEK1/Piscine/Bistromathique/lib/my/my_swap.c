/*
** my_swap.c for my_swap in /home/uberti_l/day04
**
** Made by louis-emile uberti-ares
** Login   <uberti_l@epitech.net>
**
** Started on  Thu Oct  1 09:55:36 2015 louis-emile uberti-ares
** Last update Wed Oct 14 17:52:23 2015 louis-emile uberti-ares
*/

int	my_swap(int *a, int *b)
{
  int	temp;

  temp = *b;
  *b = *a;
  *a = temp;
}
