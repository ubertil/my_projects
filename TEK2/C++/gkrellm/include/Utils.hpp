//
// utils.hpp for RUSH3 in /home/papadi_a/work/epitech/Rush/cpp_gkrellm/gui/include
//
// Made by alexis papadimitriou
// Login   <papadi_a@epitech.net>
//
// Started on  Fri Jan 20 23:09:06 2017 alexis papadimitriou
// Last update Sat Jan 21 04:03:44 2017 alexis papadimitriou
//

#ifndef UTILS_HPP_
# define UTILS_HPP_
# include <cstdint>

# define R		(2)
# define G		(1)
# define B		(0)
# define A		(3)

# define BLACK		(0xFF000000)
# define RED		(0xFFFF0000)
# define GREEN		(0xFF00FF00)
# define BLUE		(0xFF0000FF)
# define PURPLE		(0xFFFF00FF)
# define TEAL		(0xFF00FFFF)
# define YELLOW		(0xFFFFFF00)
# define WHITE		(0xFFFFFFFF)
# define PINK		(0xFFFF7777)
# define PINK2		(0xFFFF69B4)

union			Color
{
  uint32_t		full;
  uint8_t		argb[4];
};

struct			Pos
{
  uint16_t		x;
  uint16_t		y;
};

class			Utils
{
public:
  static Color		getColor(int32_t start, int32_t end, int32_t current,
				 Color *colors);
};

#endif /* UTILS_HPP_ */
