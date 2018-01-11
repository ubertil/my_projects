//
// GraphContainerGUI.hpp for rush3 in /home/papadi_a/work/epitech/Rush/cpp_gkrellm/gui
//
// Made by alexis papadimitriou
// Login   <papadi_a@epitech.net>
//
// Started on  Sat Jan 21 05:51:04 2017 alexis papadimitriou
// Last update Sun Jan 22 03:55:11 2017 alexis papadimitriou
//

#ifndef GRAPHCONTAINERGUI_HPP_
# define GRAPHCONTAINERGUI_HPP_
# include "ContainerGUI.hpp"
# include <vector>

class			GraphContainerGUI : public ContainerGUI
{
private:
  std::vector<uint32_t>	_data;
  uint32_t		_max;
  Pos			_graph_pos;
  Color			_graph_background;

public:
  GraphContainerGUI(Pos pos, uint32_t width, uint32_t height,
		    std::string const &title, Font &font, uint32_t max);
  void			setMax(uint32_t max) {this->_max = max;}
  uint32_t		getMax(void) {return (this->_max);}

  void			pushData(int data);
  void			render(void);
  void			renderGraph(void);
};

#endif /* !GRAPHCONTAINERGUI_HPP_ */
