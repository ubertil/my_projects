/*
** reverse_obj_info.c for reverse_obj_info in /home/uberti_l/rendu/Infographie/gfx_raytracer2
**
** Made by louis-emile uberti-ares
** Login   <uberti_l@epitech.net>
**
** Started on  Sat May  7 16:58:49 2016 louis-emile uberti-ares
** Last update Mon May  9 16:35:50 2016 louis-emile uberti-ares
*/

#include "raytracer2.h"

t_faces		*reverse_faces_info(t_faces *root)
{
  t_faces	*new_root;
  t_faces	*next;

  new_root = NULL;
  while (root)
    {
      next = root->next;
      root->next = new_root;
      new_root = root;
      root = next;
    }
  return (new_root);
}

t_objinfo	*reverse_obj_info(t_objinfo *root)
{
  t_objinfo	*next;
  t_objinfo	*new_root;

  new_root = NULL;
  while (root)
    {
      next = root->next;
      root->next = new_root;
      new_root = root;
      root = next;
    }
  return (new_root);
}
