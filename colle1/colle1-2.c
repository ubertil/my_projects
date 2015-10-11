/*
** colle1-2.c for colle1-2 in /home/uberti_l/rendu/Piscine_C_colles-Semaine_01
** 
** Made by louis-emile uberti-ares
** Login   <uberti_l@epitech.net>
** 
** Started on  Sat Oct  3 15:38:14 2015 louis-emile uberti-ares
** Last update Sat Oct  3 20:21:10 2015 louis-emile uberti-ares
*/

int	my_putchar(char c)
{
  write (1, &c, 1);
}

int	my_special_cube(int x, int y)
{
  int	up;
  int	down;
  
  up = 0;
  down = 0;
  x = x + 1;
  if ((x > 1) && (y == 1))
    {
      while (up != x)
	{
	  up = up + 1;
	  my_putchar('*');
	}
    }
  if ((x == 1) && (y > 1))
    {
      my_putchar('*');
      while (down != (y - 1))
	{
	  my_putchar('\n');
	  my_putchar('*');
	  down = down + 1;
	}
    }
  my_putchar('\n');
}

int	my_garbage(int height, int lenght, int x, int y)
{
  if ((height > 0) && (height < (y-1)) && (lenght > 0) && (lenght < x))
    {
      my_putchar(' ');
    }
  else
    {
      if (((height == 0) && (lenght == 0)) || ((height == (y - 1)) && (lenght == x)))
	{
	  my_putchar('/');
	}
      else
	{
	  if (((lenght == x) && (height == 0)) || ((lenght == 0) && (height == y - 1)))
	    {
	      my_putchar('\\');
	    }
	  else
	    {
	      my_putchar('*');
	    }
	}
    }
}
    
int	colle(int x, int y)
{
  int	height;
  int	lenght;

  x = x - 1;
  height = 0;
  if ((x > 0) && (y > 1))
    {
      while (height != y)
	{
	  lenght = 0;
	  while (lenght != x)
	      {
 		my_garbage(height, lenght, x, y);
		lenght = lenght + 1;
	      }
	  my_garbage(height, lenght, x, y);
	  my_putchar('\n');
	  height = height + 1;
	}
    }
  else 
    {
      my_special_cube(x, y);
    }
}

int	main()
{
  colle(5, 8);
  return (0);
}
