/*
** my_revstr.c for my_revstr in /home/uberti_l/rendu/Piscine_C_J06
**
** Made by louis-emile uberti-ares
** Login   <uberti_l@epitech.net>
**
** Started on  Mon Oct  5 11:50:55 2015 louis-emile uberti-ares
** Last update Wed Oct 14 17:33:56 2015 louis-emile uberti-ares
*/

char	*my_revstr(char *str)
{
  int	i;
  int	str_size;
  int	temp_var;

  i = 0;
  str_size= (my_strlen(str) - 1);
  while (i < str_size)
    {
      temp_var = str[i];
      str[i] = str[str_size];
      str[str_size] = temp_var;
      i = i + 1;
      str_size = str_size - 1;
    }
  return (str);
}
