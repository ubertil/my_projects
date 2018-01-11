/*
** Core.cpp for plazza in /home/login_p/delivery/plazza/Core.cpp
**
** Made by Alexis Papadimitriou
** Login   <alexis.papadimitriou@epitech.eu>
**
** Started on  Mon Apr 24 20:51:49 2017 Alexis Papadimitriou
// Last update Sat Apr 29 16:11:27 2017 Lous-Emile Uberti-Ares
*/

#include "Thread/Pool.hh"
#include "Core.hh"
#ifdef USE_UI
    #include "UI/UI.hh"
#endif

Plazza::Core::Core(const size_t nb_workers) :
  _nb_workers(nb_workers), _sanitizer("[^ \t]+"), _separator("[^;]+")
{
  this->_manager = std::make_unique<Process::Manager>(_nb_workers);
  this->_info_type["PHONE_NUMBER"] = PHONE_NUMBER;
  this->_info_type["EMAIL_ADDRESS"] = EMAIL_ADDRESS;
  this->_info_type["IP_ADDRESS"] = IP_ADDRESS;
}

void Plazza::Core::manageCommandList(const std::string &input)
{
  std::string command = input;
  std::smatch part;

  while (std::regex_search(command, part, this->_separator))
    {
      this->processCommand(part[0]);
      command = part.suffix().str();
    }
}

void Plazza::Core::processCommand(const std::string &command)
{
  std::vector<std::string>	files;
  std::string			    command_part = command;
  std::smatch			    info_part;
  Information			    info_to_retrieve;
  bool				        has_info = false;

  while (std::regex_search(command_part, info_part, this->_sanitizer))
    {

	if (this->_info_type.find(info_part[0]) != this->_info_type.end())
	  {
	    if (has_info)
	      return ;
	    info_to_retrieve = this->_info_type[info_part[0]];
	    has_info = true;
	  }
      else
	  files.emplace_back(info_part[0]);
      command_part = info_part.suffix().str();
    }
  if (has_info)
    for (auto const &file : files)
      this->_cmd_queue.emplace(std::make_pair(file, info_to_retrieve));
  else
    std::cerr << "Invalid command '" << command << "' " << std::endl;
}

bool Plazza::Core::getCommand()
{
  std::string cmd;

  if (not std::getline(std::cin, cmd))
    return (false);
  this->manageCommandList(cmd);
  return (true);
}

void	Plazza::Core::run()
{
#ifdef USE_UI
    std::unique_ptr<Plazza::UI> ui;
    std::string                 line;

    ui = std::make_unique<Plazza::UI>(this->_nb_workers, this->_manager->getClientList());
    while (ui->getCommand(line))
    {
        this->manageCommandList(line);
        this->_manager->sendCommand(this->_cmd_queue);
    }
#else
  while (this->getCommand())
    this->_manager->sendCommand(this->_cmd_queue);
#endif
    this->_manager->killAll();
}
