/*
** raytracer.h for raytracer in /home/uberti_l/rendu/Infographie/gfx_raytracer1/include
**
** Made by louis-emile uberti-ares
** Login   <uberti_l@epitech.net>
**
** Started on  Thu Feb  4 16:42:01 2016 louis-emile uberti-ares
** Last update Thu Feb 18 17:02:34 2016 louis-emile uberti-ares
*/

#ifndef RAYTRACER_H_
# define RAYTRACER_H_
#include <lapin.h>

typedef struct			s_camera
{
  const t_bunny_position	*screen_info;
  int				x;
  int				y;
  int				z;
}				t_camera;

typedef struct			s_sphere
{
  double			pos[3];
  double			radius;
  t_color			color;
  struct s_sphere		*next;
}				t_sphere;

typedef struct			s_cube
{
  double			pos[3];
  t_color			color;
  struct s_cube			*next;
}				t_cube;

typedef struct			s_torus
{
  double			pos[3];
  double			s_radius;
  double			l_radius;
  t_color			color;
  struct s_torus		*next;
}				t_torus;

typedef struct			s_lux
{
  double			pos[3];
  t_color			color;
  struct s_lux			*next;
}				t_lux;

typedef struct			s_cone
{
  double			pos[3];
  double			angle;
  t_color			color;
  struct s_cone			*next;
}				t_cone;

typedef struct			s_plane
{
  double			a[3];
  double			x[3];
  t_color			color;
  struct s_plane		*next;
}				t_plane;

typedef struct			s_cylinder
{
  double			pos[2];
  double			r;
  t_color			color;
  struct s_cylinder		*next;
}				t_cylinder;

typedef struct			s_object
{
  t_sphere			sphere;
  t_cube			cube;
  t_torus			torus;
  t_cone			cone;
  t_lux				lux;
  t_plane			plane;
  t_cylinder			cylinder;
}				t_object;

typedef struct			s_raytracer
{
  t_bunny_position		*pos;
  t_bunny_window		*win;
  t_bunny_pixelarray		*pix;
  t_camera			*cam;
  t_object			*obj;
  int				width;
  int				height;
  int				ini_idx;
}				t_ray;

typedef struct			s_scene
{
  char				*object;
  void				(*func)(t_bunny_ini *ini, t_ray *ray,
					char *form);
}				t_scene;

void				my_putchar(char c);
void				my_putstr_err(char *str);
double				my_getdouble(const char *str);
int				my_putstr(char *str);
int				my_getnbr(char *str);
int				my_strlen(char *str);
int				my_strcmp(char *src1, char *src2);
int				my_put_nbr(int nbr);
char				*my_strcpy(char *dest, char *src);
char				*my_strdup(char *src);
void				ini_loader(int ac, char **av, t_ray *ray);
void				from_ini_to_sphere(t_bunny_ini *ini,
						   t_ray *ray,
						   char *form);
void				from_ini_to_cube(t_bunny_ini *ini,
						 t_ray *ray,
						 char *form);
void				from_ini_to_torus(t_bunny_ini *ini,
						  t_ray *ray,
						  char *form);
void				from_ini_to_light(t_bunny_ini *ini,
						  t_ray *ray,
						  char *form);
void				from_ini_to_cylinder(t_bunny_ini *ini,
						     t_ray *ray,
						     char *form);
void				from_ini_to_cone(t_bunny_ini *ini,
						 t_ray *ray,
						 char *form);
void				from_ini_to_plane(t_bunny_ini *ini,
						  t_ray *ray,
						  char *form);
void				tekpixel(t_bunny_pixelarray *pix,
					 t_bunny_position *pos,
					 unsigned int color);
t_color				get_ini_color(char *col);
#endif /* !RAYTRACER_H_ */
