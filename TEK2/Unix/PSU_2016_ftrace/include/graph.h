/*
** graph.h for graph in /home/uberti_l/rendu/Unix/PSU_2016_ftrace
**
** Made by Lous-Emile Uberti-Ares
** Login   <uberti_l@epitech.net>
**
** Started on  Sun Apr 23 22:41:53 2017 Lous-Emile Uberti-Ares
** Last update Sun May  7 16:54:27 2017 Lous-Emile Uberti-Ares
*/

#ifndef GRAPH_H_
# define GRAPH_H_

# define GRAPH_FILE "ftrace_graph.dot"
# define GRAPH_START "digraph G {\n node [style=filled];\n"
# define GRAPH_END "}\n"
# define GRAPH_ERR "Error: Could not create graph file\n"

# define STYLE_DEFAULT "\"%s\""
# define GRAPH_LINK "\"%s\" -> \"%s\";\n"
# define STYLE_FUNC "\"%s\" [shape=diamond, color=purple, style=radial];\n"
# define STYLE_SYSCALL "\"%s\" [shape=circle color=red];\n"
# define STYLE_END_NODE "\"%s\" [color=blue];\n"

typedef enum	e_type
  {
    F_LINKED,
    F_NOT_LINKED,
    SYS
  }		e_type;

_Bool		open_graph(int *fd);
_Bool		add_to_graph(const int fd, const char *start, const char *end,
			     e_type type);
void		close_graph();

#endif /* !GRAPH_H_ */
