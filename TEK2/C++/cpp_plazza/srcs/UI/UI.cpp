/*
** UI.cpp for plazza in /home/uberti_p/delivery/plazza/UI.cpp
**
** Made by Louis-Emile Uberti-Ares
** Login   <louis-emile.uberti-ares@epitech.eu>
**
** Started on  sam. avr. 29 12:20:15 2017 Louis-Emile Uberti-Arès
** Last update sam. avr. 29 12:20:15 2017 Louis-Emile Uberti-Arès
*/

#include <ctime>
#include <dirent.h>
#include <iostream>
#include "UI/UI.hh"

Plazza::UI::UI(const std::size_t nb_workers, const std::unordered_map<int, std::pair<pid_t, Process::Status>> &process_list) :
    m_process_list(process_list), m_nb_workers(nb_workers), m_delim(0)
{
    std::time_t result = std::time(nullptr);

    this->m_commands["clear"] = [this] { std::cout << "\033c" << std::endl; };
    this->m_commands["status"] = [this] { this->displayStatus(); };
    this->m_commands["help"] = [this] { this->help(); };
    this->m_commands["list"] = [this] { this->listDir(); };
    this->m_commands["clear"]();
    std::cout << " ____  _        _     __________   _    " << std::endl;
    std::cout << "|  _ \\| |      / \\   |__  /__  /  / \\  " << std::endl;
    std::cout << "| |_) | |     / _ \\    / /  / /  / _ \\  " << std::endl;
    std::cout << "|  __/| |___ / ___ \\  / /_ / /_ / ___ \\ " << std::endl;
    std::cout << "|_|   |_____/_/   \\_\\/____/____/_/   \\_\\" << std::endl;
    std::cout << GREEN << "[+] Starting new session " << std::asctime(std::localtime(&result)) << DEFAULT;
    std::cout << "Use 'help' to get started" << std::endl << std::endl;
}

void    Plazza::UI::help() const
{
    std::cout << "Available commands :" << std::endl;
    std::cout << "\thelp : show this page" << std::endl;
    std::cout << "\tlist DIR : list the content of DIR" << std::endl;
    std::cout << "\tclear : clear the console" << std::endl;
    std::cout << "\tstatus : Display multiple informations about the scrapper(occupency, thread status, remaining work)" << std::endl << std::endl;
}

void    Plazza::UI::listDir() const
{
    std::string dir;

    if (this->m_delim == this->m_cmd.size())
        return;
    dir = this->m_cmd.substr(this->m_delim + 1, this->m_cmd.size());

    DIR* dirp = opendir(dir.c_str());
    struct dirent *dp;

    if (dirp == NULL)
        return ;
    while ((dp = readdir(dirp)) != NULL)
        std::cout << dp->d_name << std::endl;
    closedir(dirp);
}

void    Plazza::UI::displayStatus() const
{
    std::cout << GREEN << "[*] Plazza status" << DEFAULT << std::endl;
    std::cout << "Number of threads per process : " << this->m_nb_workers <<  std::endl;
    std::cout << "Number of process running : " << this->m_process_list.size() << std::endl;
    for (auto const &process : this->m_process_list)
    {
        std::cout << "---------------" << std::endl;
        std::cout << GREEN << "[*] Process PID " << process.second.first << DEFAULT << std::endl;
        std::cout << "Status : " << process.second.second << std::endl;
        std::cout << "Socket ID : " << process.first << std::endl;
    }
}

bool Plazza::UI::getCommand(std::string &line)
{
    std::cout << "$> ";
    if (std::getline(std::cin, line))
    {
        this->m_cmd = line;
        if (line.compare("exit") == 0)
            return (false);
        this->m_delim = (line.find_first_of(" ") == std::string::npos) ? (line.size()) : (line.find_first_of(" "));
        if (this->m_commands.find(line.substr(0, this->m_delim)) != this->m_commands.end())
        {
            this->m_commands.at(line.substr(0, this->m_delim))();
            line.clear();
        }
        return (true);
    }
    return (false);
}