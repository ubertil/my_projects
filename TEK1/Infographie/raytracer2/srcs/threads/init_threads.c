/*
** init_threads.c for init_threads in /home/uberti_l/rendu/Infographie/gfx_raytracer2
**
** Made by louis-emile uberti-ares
** Login   <uberti_l@epitech.net>
**
** Started on  Sat May 14 18:10:51 2016 louis-emile uberti-ares
** Last update Sun May 22 17:14:42 2016 louis-emile uberti-ares
*/

#include "raytracer2.h"

static void		do_your_work(t_threads *thread)
{
  t_triangles		*tmp;
  t_bunny_position	pos[2];
  double		info[2][3];
  double		dist;

  pos[0].x = thread->rtc->width;
  pos[0].y = thread->rtc->height;
  pos[1].y = -1;
  dist = 1000000;
  while (++pos[1].y < pos[0].y)
    {
      pos[1].x = thread->start_x - 1;
      while (++pos[1].x < thread->start_x + (thread->rtc->width / NB_THREADS))
	{
	  tmp = thread->rtc->triangles;
	  tekray(pos, &info[0][0], &info[0][1], &info[0][2]);
	  while (tmp)
	    {
	      if (intersect(thread->rtc, tmp, info, &dist) == 0)
		tekpixel(thread->rtc->cam, &pos[1],
			 phong(thread->rtc, info, tmp->mat, tmp));
	      tmp = tmp->next;
	    }
	}
    }
}

static void		*thread(void *_arg)
{
  t_threads		*thread;

  thread = (t_threads *)_arg;
  pthread_mutex_lock(thread->working);
  do_your_work(thread);
  pthread_mutex_unlock(thread->working);
  pthread_exit(NULL);
}

int			init_threads(t_rtc *rtc)
{
  pthread_mutex_t	working;
  int			i;

  working = (pthread_mutex_t)PTHREAD_MUTEX_INITIALIZER;
  i = -1;
  while (++i < NB_THREADS)
    {
      rtc->threads[i].rtc = rtc;
      rtc->threads[i].working = &working;
      rtc->threads[i].nb = i;
      rtc->threads[i].start_x = i * (rtc->width / NB_THREADS);
      if (pthread_create(&rtc->threads[i].thread, NULL, thread,
			 &rtc->threads[i]))
	return (my_puterr("Error: threads: thread's creation failed.\n"));
    }
  i = -1;
  while (++i < NB_THREADS)
    pthread_join(rtc->threads[i].thread, NULL);
  return (0);
}
