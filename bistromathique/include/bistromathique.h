/*
** bistromathique.h for bistromathique in /home/uberti_l/rendu/Piscine_C_bistromathique/include
**
** Made by louis-emile uberti-ares
** Login   <uberti_l@epitech.net>
**
** Started on  Wed Oct 21 09:32:35 2015 louis-emile uberti-ares
** Last update Sun Nov  1 10:11:12 2015 louis-emile uberti-ares
*/

#ifndef BISTROMATHIQUE_H
# define BISTROMATHIQUE_H

#define	ERROR_MSG "Error : Wrong syntax\n"
#define	USAGE_MSG "Usage : ./calc \"base\" \"operators\" \"size_read\"\n"
#define	PAR_MSG "Error : Wrong syntax\nPlease check your parenthesis twice\n"
#define	R_MSG "Error : read_size too big. Please retry using the right size\n"
#define	OPERATORS_MSG "Please check your operators twice\n"
#define	DIV_0 "Error : Division by zero\n Please check your calculus\n"
#define	EOS '\0'
#define	EOL '\n'

/*
** STRUCTURES
*/

struct		s_add_sub
{
  int		l1;
  int		l2;
  int		n1;
  int		n2;
  int		n_res;
  int		carry;
  int		rank;
  int		tmp_is_higher;
  int		final_rank;
  char		*final_return;
};

struct		s_mult
{
  int		l1;
  int		l2;
  int		perm_l1;
  int		n1;
  int		n2;
  int		n_res;
  int		carry;
  int		perm_idx;
  int		zero_toadd;
  int		tmp_idx;
  char		*tmp1;
  char		*tmp2;
};

struct		s_div
{
  char		*dvd;
  char		*dvs;
  char		*temp_fact;
  char		*temp_cmp;
  char		*total;
  int		length;
  char		*mod;
};

struct		s_stack
{
  char		*value;
  unsigned int	stack_idx;
  unsigned int	buff_idx;
  char		*tmp;
  unsigned int	tmp_idx;
  char		operators;
};

struct		s_op
{
  int	(*func)(char *nb1, char *nb2);
};	t_op

t_op		my_op[] =
  {
    {&add_sub},
    {&add_sub},
    {&multiplication},
    {&my_division},
    {&my_modulo},
  };

typedef struct	s_add_sub t_add_sub;
typedef struct	s_mult t_mult;
typedef struct	s_div t_div;
typedef struct	s_stack t_stack;

/*
** VERIFICATION SYNTAXE
*/

char	*get_expr(unsigned int size);
int	par_checker(char *expr, char *to_use);
char	my_get_to_use(char *expr, char *to_use, char *base, char *operators);
int	check_ops(char *expr, char *to_use);
int	check_expr_twice(char *expr, char *to_use, char *base, char *operators);
int	is_expr_valid(int ac, char **av);

/*
** NPI (Notation Polonaise Inversée)
*/



/*
** ADDITION / SOUSTRACTION
*/

int	my_display_sum(int mode, char **argv, char *display, t_add_sub *a);
int	my_display_sub(int mode, char **argv, char *display, t_add_sub *a);
int	my_do_op_sum(t_add_sub *as, char **argv, int rank, char *display);
int	my_do_op_sub_cmp(char *n1, char *n2, int s1, int s2);
void	my_put_in_final_return(t_add_sub *a, char what_to_put);
t_add_sub	*init_my_a(char **av);
int		my_clean_str(char **av, int mode, t_add_sub *a, char s2);
int		my_do_op_sub(t_add_sub *a, char **av, int r, char *display);
char		*add_sub(char *n1, char *n2);

/*
** MULTIPLICATION
*/

t_mult		*my_preparator(char *n1, char *n2, char *final);
t_mult		*my_zero_checker(t_mult *a);
char		*my_mult(char *n1, char *n2, t_mult *a, char *final);
t_mult		*my_lenght_checker(char *n1, char *n2, t_mult *a, char *final);
int		multiplication(char *n1, char *n2);
char		*my_final_return(t_mult *a, char *final);

/*
** DIVISION
*/

t_div		*init_my_div(char *n1, char *n2);
char		*my_division(char *n1, char *n2);
int		add_zero(t_div *d);
int		remove_zero(t_div *d);
int		check_digits(t_div *d);
char		*get_minus(char *str);


/*
** MODULO
*/

char		*my_modulo(char *n1, char *n2);
t_div		*init_my_mod(char *n1, char *n2);

#endif /* !BISTROMATHIQUE_H */
