/*
** envline_cpy.c for envline_cpy.c in /home/uberti_l/rendu/Unix/PSU_2015_minishell1
**
** Made by louis-emile uberti-ares
** Login   <uberti_l@epitech.net>
**
** Started on  Sun Jan 24 21:19:29 2016 louis-emile uberti-ares
** Last update Sun Jan 24 21:21:56 2016 louis-emile uberti-ares
*/

char	*envline_cpy(char *dest, char *env)
{
  int	i;
  int	j;

  i = 0;
  j = 0;
  while (env[i] != '=')
    i += 1;
  i += 1;
  while (env[i] != '\0')
    {
      dest[j] = env[i];
      i += 1;
      j += 1;
    }
  dest[j] = '\0';
  return (dest);
}
