/*
** get_width.c for get_width in /home/uberti_l/rendu/Unix/PSU_2016_nmobjdump
**
** Made by Lous-Emile Uberti-Ares
** Login   <uberti_l@epitech.net>
**
** Started on  Sun Feb 26 01:38:28 2017 Lous-Emile Uberti-Ares
** Last update Sun Feb 26 01:39:16 2017 Lous-Emile Uberti-Ares
*/

unsigned int	get_width(unsigned long nb)
{
  unsigned int	width;

  width = 0;
  while (nb > 0)
    {
      nb /= 16;
      ++width;
    }
  return ((width > 4) ? (width) : (4));
}
