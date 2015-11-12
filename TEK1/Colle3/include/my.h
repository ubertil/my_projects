/*
** my.h for my in /home/uberti_l/rendu/Piscine_C_J09/include
**
** Made by louis-emile uberti-ares
** Login   <uberti_l@epitech.net>
**
** Started on  Thu Oct  8 11:18:13 2015 louis-emile uberti-ares
** Last update Sat Oct 24 19:21:38 2015 louis-emile uberti-ares
*/

#ifndef		MY_H_
# define	MY_H_
# define	BUFF_SIZE (4096)

void		my_putchar(char c);
int		my_isneg(int nb);
int		my_put_nbr(int nb);
int		my_swap(int *a, int *b);
int		my_putstr(char *str);
int		my_strlen(char *str);
int		my_getnbr(char *str);
void		my_sort_int_tab(int *tab, int size);
int		my_power_rec(int nb, int power);
int		my_square_root(int nb);
int		my_is_prime(int nombre);
int		my_find_prime_sup(int nb);
char		*my_strcpy(char *dest, char *src);
char		*my_strncpy(char *dest, char *src, int nb);
char		*my_revstr(char *str);
char		*my_strstr(char *str, char *to_find);
int		my_strcmp(char *s1, char *s2);
int		my_strncmp(char *s1, char *s2, int nb);
char		*my_strupcase(char *str);
char		*my_strlowcase(char *str);
char		*my_strcapitalize(char *str);
int		my_str_isalpha(char *str);
int		my_str_isnum(char *str);
int		my_str_islower(char *str);
int		my_str_isupper(char *str);
int		my_str_isprintable(char *str);
int		my_showstr(char *str);
int		my_showmem(char *str, int size);
char		*my_strcat(char *dest, char *src);
char		*my_strncat(char *dest, char *src, int nb);
int		my_strlcat(char *dest, char *src, int size);
int		colle3(char *buff);
int		what_is_x(char *buff, int i, int x);
int		what_is_y(char *buff, int i, int y);
int		check_A(char *buff, int x, int y);
int		colle1_1(int x, int y);
int		colle1_2(int x, int y);
int		colle1_3(int x, int y);
int		colle1_4(int x, int y);
int		colle1_5(int x, int y);
int		colle_commune(int x, int y);

#endif