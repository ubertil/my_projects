/*
** colle-commune.c for colle-commune in /home/uberti_l/rendu/Piscine_C_colles-Semaine_03
**
** Made by louis-emile uberti-ares
** Login   <uberti_l@epitech.net>
**
** Started on  Sat Oct 24 19:07:18 2015 louis-emile uberti-ares
** Last update Sat Oct 24 19:40:19 2015 louis-emile uberti-ares
*/

int	colle_commune(int x, int y)
{
  my_putchar('[');
  my_putstr("colle1-1");
  my_putchar(' ');
  my_put_nbr(x);
  my_putchar(' ');
  my_put_nbr(y);
  my_putchar(']');
  my_putstr(" || ");
  my_putchar('[');
  my_putstr("colle1-2");
  my_putchar(' ');
  my_put_nbr(x);
  my_putchar(' ');
  my_put_nbr(y);
  my_putchar(']');
  my_putchar('\n');
}
