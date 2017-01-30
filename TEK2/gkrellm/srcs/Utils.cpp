//
// Utils.cpp for rush3 in /home/papadi_a/work/epitech/Rush/cpp_gkrellm/gui/include
//
// Made by alexis papadimitriou
// Login   <papadi_a@epitech.net>
//
// Started on  Sat Jan 21 03:41:03 2017 alexis papadimitriou
// Last update Sun Jan 22 06:01:19 2017 Lous-Emile Uberti-Ares
//

#include "Utils.hpp"

Color		Utils::getColor(int32_t start, int32_t end, int32_t current,
				 Color *colors)
{
  Color		ret;
  float		t;

  t = (current - start) / (float)(end - start);
  ret.argb[R] = colors[0].argb[R] * (1 - t) + t * colors[1].argb[R];
  ret.argb[G] = colors[0].argb[G] * (1 - t) + t * colors[1].argb[G];
  ret.argb[B] = colors[0].argb[B] * (1 - t) + t * colors[1].argb[B];
  return (ret);
}
