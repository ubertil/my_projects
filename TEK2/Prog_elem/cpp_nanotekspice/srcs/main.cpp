/*
** main.cpp for cpp_nanotekspice in /home/uberti_p/delivery/cpp_nanotekspice/main.cpp
**
** Made by Louis-Emile Uberti-Ares
** Login   <louis-emile.uberti-ares@epitech.eu>
**
** Started on  mer. févr. 01 15:58:55 2017 Louis-Emile Uberti-Arès
** Last update mer. févr. 01 15:58:55 2017 Louis-Emile Uberti-Arès
*/

#include <iostream>
#include <algorithm>
#include "Error.hpp"
#include "Controller.hpp"

static inline bool  CmdOptions(char const * const *start, char const * const *end, const std::string &cmd)
{
    return (std::find(start, end, cmd) != end);
}

int                 main(int ac, const char **av)
{
    nts::Controller Controller;

    if (CmdOptions(av, av + ac, "--help") || CmdOptions(av, av + ac, "-h"))
	    return (Controller.usage());
    if (ac < 2)
    {
	    std::cerr << USAGE << std::endl;
	    std::cerr << "Use '--help' or '-h' for more information" << std::endl;
	    return (1);
    }
    try
    {
	    Controller.readFeed(av[1], true);
	    Controller.run(ac, av);
    }
    catch (nts::Error const &e)
    {
	    std::cerr << "nanotekspice: " << e.what() << std::endl;
    }
    return (0);
}
