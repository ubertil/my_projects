/*
** Vec.hpp.hh for cpp_arcade in /home/uberti_p/delivery/cpp_arcade/Vec.hpp.hh
**
** Made by Louis-Emile Uberti-Ares
** Login   <louis-emile.uberti-ares@epitech.eu>
**
** Started on  dim. mars 19 18:17:38 2017 Louis-Emile Uberti-Arès
// Last update Sun Apr  9 22:52:30 2017 Lous-Emile Uberti-Ares
*/

#pragma once
# include <string>

template <typename T>
class Vec2
{
public:
  T		x;
  T		y;

  Vec2() :
    x(0), y(0) {}

  Vec2(T x, T y) :
    x(x), y(y) {}

  Vec2(const Vec2 &v) :
    x(v.x), y(v.y) {}

  Vec2&	operator=(const Vec2 &v)
  {
    x = v.x;
    y = v.y;
    return (*this);
  }

  bool	operator==(const Vec2 &v) const
  {
    return (this->x == v.x && this->y == v.y);
  }

  Vec2&	operator-=(const Vec2 &v)
  {
    x -= v.x;
    y -= v.y;
    return (*this);
  }

  bool	operator<(const Vec2 &v) const
  {
    return (this->x < v.x && this->y < v.y);
  }

  Vec2&		operator+=(const Vec2 &v)
  {
    x += v.x;
    y += v.y;
    return (*this);
  }

  void		set(T x, T y)
  {
    this->x = x;
    this->y = y;
  }

  static inline T	dot(Vec2 &v1, Vec2 &v2)
  {
    return ((v1.x * v2.x) + (v1.y * v2.y));
  }

  static inline T	cross(Vec2 &v1, Vec2 &v2)
  {
    return ((v1.x * v2.y) - (v1.y * v2.y));
  }
};

template <typename T>
struct Hasher
{
    std::size_t	operator()(const Vec2<T>& v) const
    {
      return ((std::hash<T>()(v.x)
	       ^ (std::hash<T>()(v.y) << 1)) >> 1);
    }
};

typedef Vec2<int>	Vec2i;
typedef Vec2<double>	Vec2d;
typedef Vec2<float>	Vec2f;
typedef Hasher<int>	HashInt;
typedef Hasher<double>	HashDouble;
typedef Hasher<int>	HashFloat;
