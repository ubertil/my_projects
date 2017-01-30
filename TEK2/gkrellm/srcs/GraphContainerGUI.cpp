//
// GraphContainerGUI.cpp for rush" in /home/papadi_a/work/epitech/Rush/cpp_gkrellm/gui
//
// Made by alexis papadimitriou
// Login   <papadi_a@epitech.net>
//
// Started on  Sat Jan 21 06:09:23 2017 alexis papadimitriou
// Last update Sun Jan 22 06:00:55 2017 Lous-Emile Uberti-Ares
//

#include "GraphContainerGUI.hpp"

GraphContainerGUI::GraphContainerGUI(Pos pos, uint32_t width,
				     uint32_t height,
				     std::string const &title, Font &font,
				     uint32_t max) :
  ContainerGUI(pos, width, height, title, font)
{
  this->_max = max;
  this->_graph_pos.x = 4;
  this->_graph_pos.y = (this->_height - 24) / 2;
  this->_graph_background.full = 0xFF333333;
  for (uint32_t i = 0; i < width - 8; i++)
    this->pushData(0);
}

void		GraphContainerGUI::pushData(int data)
{
  this->_data.insert(this->_data.begin(), data);
  if (this->_data.size() > (uint32_t)(this->_width - 8))
    this->_data.pop_back();
}

void		GraphContainerGUI::render(void)
{
  this->_buffer.fill(this->_border);
  this->_buffer.drawRect((Pos){2, 20}, this->_width - 4,
			 this->_height - 22, this->_background);
  this->_font.render(this->_buffer, this->_title, 2, 2, 3, 3);
  if (this->_info.length() != 0)
    this->_graph_pos.y = this->_font.render(this->_buffer, this->_info,
					    this->_info_pos.x + 4, this->_info_pos.y + 24, 2, 2);
  else
    this->_graph_pos.y = 22;
  this->renderGraph();
}

void		GraphContainerGUI::renderGraph()
{
  Color		colors[2];
  Color		line_colors[2];
  Pos		pos;
  float		interpol;
  uint32_t	height = this->_height - this->_graph_pos.y - 4;
  Pos		prev_pos = {0, (uint16_t)(this->_height - 4 - (height - 2) * (this->_data.front() / (float)this->_max))};
  uint32_t	prev_val = this->_data.front();

  this->_buffer.drawRect(this->_graph_pos, this->_width - 8,
			 height, this->_graph_background);
  prev_pos.x = this->_width - 4;
  pos.x = this->_width - 4;
  colors[0].full = 0xFF3CCE3C;
  colors[1].full = 0xFFCE3C3C;
  for (uint32_t val : this->_data)
    {
      interpol = val / (float)(this->_max);
      pos.y = this->_height - 4 - (height - 2) * interpol;
      pos.x--;
      line_colors[0] = Utils::getColor(0, this->_max, prev_val, colors);
      line_colors[1] = Utils::getColor(0, this->_max, val, colors);
      this->_buffer.putLine(prev_pos, pos, line_colors);
      prev_pos = pos;
      prev_val = val;
    }
}
