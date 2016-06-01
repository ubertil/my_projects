/*
** raytracer2.h for raytracer2 in /home/uberti_l/rendu/Infographie/gfx_raytracer2
**
** Made by louis-emile uberti-ares
** Login   <uberti_l@epitech.net>
**
** Started on  Mon Mar 14 12:27:30 2016 louis-emile uberti-ares
** Last update Sun May 22 18:27:26 2016 Félix Grellard
*/

#ifndef RAYTRACER2_H_
# define RAYTRACER2_H_
# include <pthread.h>
# include <lapin.h>
# define NB_THREADS (8)
# define FOV (30)
# define EPSILON (0.00000001)
# define POS (pos->x + (pos->y * pix->clipable.buffer.width))
# define MALLOC_ERR "Error : Bunny malloc failed. Aborting.\n"
# define MTL_COL_ERR ".mtl: Error: Invalid color parameters. Aborting.\n"
# define MTL_FORMAT_ERR ".mtl: Error: Invalid line format. Aborting.\n"
# define OBJ_FORMAT_ERR ".obj: Error: Invalid line format. Aborting.\n"
# define OBJ_WRONG_IDX ".obj: Error: Wrong index used. Aborting.\n"
# define OBJ_NO_CAM ".obj: Error: Missing camera and light param. Aborting.\n"
# define OPEN_ERR "Error : Cannot open required file.\n"

/*
** STRUCTURES
*/

typedef struct		s_materials
{
  char			*name;
  double		kd[3];
  double		ka[3];
  double		ks[3];
  double		oppacity;
  double		ns;
  int			illum;
  struct s_materials	*next;
}			t_materials;

typedef struct		s_faces
{
  int			**pos;
  int			type;
  int			nb;
  char			*mat;
  struct s_faces	*next;
}			t_faces;

typedef struct		s_objinfo
{
  double		pos[3];
  struct s_objinfo	*next;
}			t_objinfo;

typedef struct		s_triangles
{
  double		**pos;
  double		**norm;
  double		**tex;
  char			*mat;
  struct s_triangles	*next;
}			t_triangles;

typedef struct	s_rtc	t_rtc;

typedef struct		s_threads
{
  pthread_t		thread;
  pthread_mutex_t	*working;
  t_rtc			*rtc;
  t_bunny_pixelarray	*pos;
  short			nb;
  int			start_x;
  int			start_y;
}			t_threads;

typedef struct		s_rtc
{
  t_bunny_window	*win;
  t_bunny_pixelarray	*cam;
  t_objinfo		*norm;
  t_objinfo		*peak;
  t_objinfo		*tex;
  t_faces		*faces;
  t_materials		*mat;
  t_triangles		*triangles;
  t_threads		threads[NB_THREADS];
  int			nb_lines;
  int			width;
  int			height;
  int			fullscreen;
  char			*scene_file;
  char			*curr_mat;
  double		cam_pos[3];
  double		light_pos[3];
  double		**obj;
  double		**norm_tab;
}			t_rtc;

typedef struct		s_options
{
  char			*str;
  int			(*f)(t_rtc *rtc, char *str);
}			t_options;

typedef struct		s_objparse
{
  char			*str;
  int			(*f)(t_rtc *rtc, char *str, t_objinfo **old);
}			t_objparse;

typedef struct		s_mtloptions
{
  char			*str;
  int			(*f)(t_materials *mat, char *str);
}			t_mtloptions;

/*
** TOOLS
*/

void		tekpixel(t_bunny_pixelarray *pix,
			 t_bunny_position *pos,
			 t_color color);
void		tekpixel_alpha(t_bunny_pixelarray *pix,
			       t_bunny_position *pos,
			       t_color color);
void		tekray(const t_bunny_position *screen_info,
		       double *x, double *y, double *z);
void		set_background(t_bunny_pixelarray *pix,
			       unsigned int color);
void		my_putstr(char *str);
void		my_put_nbr(int nbr);
void		free_faces(t_faces *old);
int		is_separator(const char *str, const char sep);
int		free_tab(char **tab);
int		getnbr_from(char *str, int i);
int		my_strlen(const char *str);
int		my_puterr(char *str);
int		quick_match(char *s1, char *s2);
int		my_strcmp(char *s1, char *s2);
int		my_strncmp(char *s1, char *s2, int n);
double		my_getdouble(char *s1);
char		*my_strcpy(char *dest, const char *src);
char		*my_strdup(const char *str);
char		*get_shell_line(const int fd);
char		**my_str_to_wordtab(const char *str, const char *sep);

/*
** FUNCTIONS
*/

void		free_all(t_rtc *rtc);
void		free_objtab(t_rtc *rtc);
void		free_objinfo(t_objinfo *old);
void		free_norm(t_rtc *rtc);
void		free_triangles(t_triangles *old);
void		move1(t_bunny_event_state state,
		      t_bunny_keysym key,
		      t_rtc *rtc);
void		move2(t_bunny_event_state state,
		      t_bunny_keysym key,
		      t_rtc *rtc);
int		get_all_triangles(t_rtc *rtc);
int		parse_args(t_rtc *rtc, int ac, char **av);
int		print_help(void);
int		get_user_width(t_rtc *rtc, char *str);
int		get_user_height(t_rtc *rtc, char *str);
int		get_user_fullscreen(t_rtc *rtc, char *str);
int		get_obj_file(t_rtc *rtc, char *str);
int		parse_mtl_file(t_rtc *rtc, char *file);
int		unused(t_rtc *rtc, char *str);
t_color		get_mat_color(t_materials *mat, char *str);

/*
** OBJ PARSING
*/

int		get_all_triangles(t_rtc *rtc);
int		parse_obj_file(t_rtc *rtc);
int		create_obj_tab(t_rtc *rtc);
int		add_peak(t_rtc *rtc, char *str);
int		add_normvec(t_rtc *rtc, char *str);
int		add_face(t_rtc *rtc, char *str);
int		add_tex_coor(t_rtc *rtc, char *str);
int		use_texture(t_rtc *rtc, char *str);
int		smoothing_group(t_rtc *rtc, char *str);
int		norm_tab(t_rtc *rtc);
t_objinfo	*reverse_obj_info(t_objinfo *root);
t_faces		*reverse_faces_info(t_faces *root);
t_faces		*get_coordinates_face(t_faces *new, char **args);

/*
** MTL PARSING
*/

int		parse_mtl_file(t_rtc *rtc, char *file);
int		add_illum(t_materials *mat, char *str);
int		add_diffuse_reflec(t_materials *mat, char *str);
int		add_ambiant_reflec(t_materials *mat, char *str);
int		add_specular_reflec(t_materials *mat, char *str);
int		add_oppacity(t_materials *mat, char *str);
int		add_specular_focus(t_materials *mat, char *str);
t_materials	*add_new_material(t_materials **old, char *str, int fd);

/*
** CALCULUS
*/

void		subdive_triangles(t_rtc *rtc);
void		cross(double vector[3], double *u, double *v);
void		vector(double vector[3], double *b, double *c);
void		normalize(double *vec);
void		get_normal(double norm[3][3], double **pos);
int		intersect(t_rtc *rtc, t_triangles *triangles,
			  double info[2][3], double *dist);
int		check_z_buffer(t_rtc *rtc, double info[2][3], double *dist);
double		dot(double *v, double *u);
double		norm(double *v);
double		assemble_all_colors(t_rtc *rtc, double *color,
				    double info[2][3], double norm[3]);
t_color		phong(t_rtc *rtc, double info[2][3], char *mat,
		      t_triangles *tmp);

/*
** THREADS
*/

int		init_threads(t_rtc *rtc);

#endif /* !RAYTRACER2_H_ */
