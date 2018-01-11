//
// main.cpp for main in /home/uberti_l/rendu/PiscineCPP/cpp_gkrellm/srcs
//
// Made by Lous-Emile Uberti-Ares
// Login   <uberti_l@epitech.net>
//
// Started on  Fri Jan 20 23:59:35 2017 Lous-Emile Uberti-Ares
// Last update Sun Jan 22 06:18:14 2017 Lous-Emile Uberti-Ares
//

#include <algorithm>
#include "Damdosh.hpp"
#include "AModule.hpp"
#include "CPU.hpp"
#include "ComputerInfo.hpp"
#include "Date.hpp"
#include "OS.hpp"
#include "RAM.hpp"
#include "Network.hpp"
# define TERM_BOLD "\e[1m"
# define TERM_DEF "\e[0m"
# define TERM_RED "\e[31m"

static const char *arguments[] =
  {"--noRAM", "--noOS", "--noNET", "--noCPU", "--noTIME", "--noINFO", "-d", "--dump", "--mode=text", "--mode=graphic",
   "--help", "-h"};

void				print_title()
{
  init_pair(1, COLOR_RED, COLOR_BLACK);
  attron(COLOR_PAIR(1));
  printw("  .,-:::::/   :::  .   :::::::..  .,::::::   :::      :::     .        :  \n");
  printw(",;;-'````'    ;;; .;;,.;;;;``;;;; ;;;;''''   ;;;      ;;;     ;;,.    ;;; \n");
  printw("[[[   [[[[[[/ [[[[[/'   [[[,/[[['  [[cccc    [[[      [[[     [[[[, ,[[[[, \n");
  printw("\"$$c.    \"$$ _$$$$,     $$$$$$c    $$\"\"\"\"    $$'      $$'     $$$$$$$$\"$$$ \n");
  printw(" `Y8bo,,,o88o\"888\"88o,  888b \"88bo,888oo,__ o88oo,.__o88oo,.__888 Y88\" 888o\n");
  printw("   `'YMUP\"YMM MMM \"MMP\" MMMM   \"W\" \"\"\"\"YUMMM\"\"\"\"YUMMM\"\"\"\"YUMMMMMM  M'  \"MMM\n\n");
  attroff(COLOR_PAIR(1));
}

int				launch(std::map<std::string, bool> activate, bool mode)
{
  int				c = 0;
  std::vector<AModule *>	modules;
  if (!mode)
    {
      Damdosh			monitor;
      modules.push_back(new ComputerInfo(activate["INFO"], monitor.getFont()));
      modules.push_back(new OS(activate["OS"], monitor.getFont()));
      modules.push_back(new Date(activate["TIME"], monitor.getFont()));
      modules.push_back(new CPU(activate["CPU"], monitor.getFont()));
      modules.push_back(new RAM(activate["RAM"], monitor.getFont()));
      modules.push_back(new Network(activate["NET"], monitor.getFont()));
      for (std::vector<AModule *>::iterator it = modules.begin(); it != modules.end(); ++it)
	{
	  if ((*it)->getDisplay() == false)
	    {
	      it = modules.erase(it);
	      --it;
	    }
	}
      monitor.start(modules);
    }
  else
    {
      modules.push_back(new ComputerInfo(activate["INFO"]));
      modules.push_back(new OS(activate["OS"]));
      modules.push_back(new Date(activate["TIME"]));
      modules.push_back(new CPU(activate["CPU"]));
      modules.push_back(new RAM(activate["RAM"]));
      modules.push_back(new Network(activate["NET"]));
      start_color();
      initscr();
      noecho();
      curs_set(0);
      timeout(0);
      c = getch();
      while (c != 'q')
	{
	  clear();
	  print_title();
	  for (AModule *md : modules)
	    {
	      if (md->refresh() == 84)
		return (-1);
	      md->renderNcurses();
	    }
	  refresh();
	  c = getch();
	}
      endwin();
    }
  return (0);
}

int				dumpMode()
{
  std::vector<AModule *>	modules;

  modules.push_back(new ComputerInfo(true));
  modules.push_back(new OS(true));
  modules.push_back(new Date(true));
  modules.push_back(new CPU(true));
  modules.push_back(new RAM(true));
  modules.push_back(new Network(true));
  for (std::vector<AModule *>::iterator it = modules.begin(); it != modules.end(); ++it)
    (*it)->dump();
  return (0);
}

int		help()
{
  std::cout << "\033c" << std::endl;
  std::cout << TERM_BOLD << "NAME" << TERM_DEF << std::endl << "\tmy_gkrellm - Process viewer" << std::endl << std::endl;
  std::cout << TERM_BOLD << "SYNOPSIS" << std::endl << "\tmy_gkrellm" << TERM_DEF << " [OPTIONS]" << std::endl << std::endl;
  std::cout << TERM_BOLD << "DESCRIPTION" << TERM_DEF << std::endl << "\tmy_gkrellm is an EPITECH project to develop a graphic process viewer" << std::endl << std::endl
	    << "\tThis program displays several modules which each are self explaning : " << std::endl
	    << TERM_BOLD << "\t- RAM " << TERM_DEF << ": RAM usage" << std::endl
	    << TERM_BOLD << "\t- OS " << TERM_DEF << ": Operating system and kernel" << std::endl
	    << TERM_BOLD << "\t- NET " << TERM_DEF << ": Network usage" << std::endl
	    << TERM_BOLD << "\t- CPU " << TERM_DEF << ": CPU info, load and usage" << std::endl
	    << TERM_BOLD << "\t- TIME " << TERM_DEF << ": Current time and uptime" << std::endl
	    << TERM_BOLD << "\t- INFO " << TERM_DEF << ": Computer's name and username" << std::endl << std::endl;
  std::cout << TERM_BOLD << "COMMAND-LINE OPTIONS" << TERM_DEF << std::endl
	    << "\tArguments available are case-sensitive" << std::endl << std::endl;
  std::cout << TERM_BOLD << "\t-h --help" << TERM_DEF << std::endl << "\t\tDisplay a help page and exit" << std::endl << std::endl;
  std::cout << TERM_BOLD << "\t--mode={text,graphic}" << TERM_DEF << std::endl << "\t\tChoose between text mode(Ncurses) or graphic(SDL)" << std::endl
	    << "\t\tDefault is graphic" << std::endl << std::endl;
  std::cout << TERM_BOLD << "\t-d --dump" << TERM_DEF << std::endl << "\t\tDirectly print in the terminal the full list of info" << std::endl << std::endl;
  std::cout << TERM_BOLD << "\t--no[MODULE]" << TERM_DEF << std::endl << "\t\tIgnore the specified MODULE" << std::endl
	    << "\t\tModules are : RAM | OS | NET | CPU | TIME | INFO" << std::endl << "\t\tRefer to the DECRIPTION section" << std::endl << std::endl;
  std::cout << TERM_BOLD << "AUTHORS" << TERM_DEF << std::endl << "\tmy_gkrellm was developed by a team of 3 developpers :" << std::endl << std::endl
	    << "\t- Alexis PAPADIMITRIOU : GUI" << std::endl
	    << "\t- Louis-Emile UBERTI-ARES : Modules implementation" << std::endl
	    << "\t- Felix GRELLARD : Research and specification" << std::endl << std::endl << "my_gkrellm 1.0.0" << std::endl;
  return (0);
}

inline bool	cmdOptions(char **begin, char **end, const std::string &opt)
{
  return (std::find(begin + 1, end, opt) != end);
}

int				parse_args(int ac, char **av,
					   std::map<std::string, bool> &activate)
{
  std::string			tmp;
  bool				mode = false;

  if (cmdOptions(av, av + ac, "-h") || (cmdOptions(av, av + ac, "--help")))
    return (help());
  if (cmdOptions(av, av + ac, "-d") || (cmdOptions(av, av + ac, "--dump")))
    return (dumpMode());
  if (cmdOptions(av, av + ac, "--mode=text"))
    mode = true;
  for (int i = 1; i != ac; ++i)
    {
      tmp = av[i];
      if (std::find(arguments, arguments + 12, tmp) != arguments + 12)
	activate[tmp.substr(tmp.find("o") + 1, tmp.size())] = false;
      else
	std::cerr << "Ignored command-line option " << TERM_RED  << "`" << tmp
		  << "`" << TERM_DEF << std::endl << "Consider using the -h / --help flag."
		  << std::endl;
    }
  return(launch(activate, mode));
}

int				main(int ac, char **av)
{
  std::map<std::string, bool>	activate;

  activate["RAM"] = true;
  activate["OS"] = true;
  activate["NET"] = true;
  activate["CPU"] = true;
  activate["TIME"] = true;
  activate["INFO"] = true;
  if (ac < 1)
    return(launch(activate, false));
  else
    return (parse_args(ac, av, activate));
}
