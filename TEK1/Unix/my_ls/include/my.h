/*
** my.h for my in /home/uberti_l/rendu/PSU_2015_my_ls/include
**
** Made by louis-emile uberti-ares
** Login   <uberti_l@epitech.net>
**
** Started on  Wed Nov 18 10:16:57 2015 louis-emile uberti-ares
** Last update Sun Nov 29 22:17:57 2015 louis-emile uberti-ares
*/

#ifndef MY_H_
# define MY_H_
# define LINE_A "\n\t/* Bienvenue sur le man de my_ls de uberti_l *\\\n"
# define LINE_B "Voici les commandes disponibles à l'utilisation :\n"
# define LINE_C "-d : Liste les dossiers et non leurs contenus\n\n"
# define LINE_D "-l : Utilise un formatage plus long / affiche plus d'infos\n\n"
# define LINE_E "-r : Inverse l'ordre d'affichage des résultats lors du tri\n\n"
# define LINE_F "-R : Ouvre les dossiers de manière récursive\n\n"
# define LINE_G "-t : Tri par date de dernière modification\n"
# define USAGE "\t\t\033[36;04mUSAGE\033[00m : ./my_ls [-dlrRt] [file]\n\n"

typedef struct	s_dir
{
  char		*file;
  struct s_dir	*next;
}		t_dir;

typedef struct	s_stock
{
  char		*flags;
  t_dir		*dir;
  int		nb;
  int		display_reverse;
  int		display_time;
  int		display_dir;
  int		display_all;
  char		did_l;
  char		did_d;
  char		did_R;
  char		did_r;
  char		did_t;
  int		parceur;
}		t_stock;

typedef struct	s_format
{
  char		format;
  void		(*func)(t_dir *);
}		t_format;

void		my_putchar(char c);
void		my_putnbr_special(unsigned long nb);
int		my_putstr(char *str);
int		find_help(int nb, char **av);
int		parceur(int nb, char **av);
void		my_printf(const char *format, ...);
int		my_strlen(char *str);
int		init_my_dir(int ac, char **av, t_stock *a);
int		my_core(t_stock *a);
void		my_show_dir(t_dir *a);
void		my_show_all(t_dir *a);
void		my_show_recursive(t_dir *a);
void		my_show_reverse(t_dir *a);
void		my_show_time(t_dir *a);
void		my_show_basic(t_dir *a);
void		display_core(char *directory);
int		show_time(char *file);
int		show_owners(char *file);
int		show_rights(char *file);
int		show_name(char *file);
void		disp_recursive(char *directory);
int		get_total(char *directory);

#endif /* !MY_H_ */
