//
// Starfield.hpp for rush3 in /home/papadi_a/work/epitech/Rush/cpp_gkrellm/merge
//
// Made by alexis papadimitriou
// Login   <papadi_a@epitech.net>
//
// Started on  Sun Jan 22 04:25:46 2017 alexis papadimitriou
// Last update Sun Jan 22 04:52:22 2017 alexis papadimitriou
//

#ifndef STARFIELD_HPP_
# define STARFIELD_HPP_
# include "PixelBuffer.hpp"

class		Starfield
{
private:
  struct	Star
  {
    int		x;
    int		y;
    int		z;
    int		speed;
    Color	color;
  };

  Star		*_stars;
  int		_width;
  int		_height;
  int		_nb;
  double	_fov;
  float		_angle;

public:
  Starfield(int nb, int width, int height);
  ~Starfield();

  void		renderAndUpdateStars(PixelBuffer &buffer);
};

#endif /* !STARFIELD_HPP_ */
