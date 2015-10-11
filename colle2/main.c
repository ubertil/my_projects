/*
** main.c for main in /home/uberti_l/rendu/Piscine_C_colles-Semaine_02
**
** Made by louis-emile uberti-ares
** Login   <uberti_l@epitech.net>
**
** Started on  Sat Oct 10 13:26:20 2015 louis-emile uberti-ares
** Last update Sat Oct 10 21:07:59 2015 louis-emile uberti-ares
*/

int	main(int argc, char **argv)
{
  int	i;

  i = 0;
  if ((((argc < 3) || (argc >= 4))
      || ((argv[2][i] < 48) || (argv[2][i] > 57))
       && ((argv[2][i] != 45) && ((argv[2][i] != 43)))))
    {
      my_putstr("Usage : ./colle2-5 text size ");
      my_putchar('\n');
      return (0);
    }
  if (my_getnbr(argv[2]) <= 0)
    {
      my_putstr("Size too small");
      my_putchar('\n');
      return (0);
    }
  else
    {
      my_arena_v2(argc, argv);
    }
}
