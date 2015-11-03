/*
** my_aff_params.c for my_aff_params in /home/uberti_l/rendu/Piscine_C_J07/ex_04
**
** Made by louis-emile uberti-ares
** Login   <uberti_l@epitech.net>
**
** Started on  Wed Oct  7 11:15:09 2015 louis-emile uberti-ares
** Last update Wed Oct  7 22:11:04 2015 louis-emile uberti-ares
*/

int	my_aff_params(int argc, char **argv)
{
  int	i;

  i = 0;
  while (argc > i)
    {
      my_putstr(argv[i]);
      i = i + 1;
      my_putchar('\n');
    }
}
