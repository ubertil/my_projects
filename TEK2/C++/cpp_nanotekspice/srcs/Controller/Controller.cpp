/*
** Controller.cpp for nanotekspice in /home/uberti_p/delivery/nanotekspice/Controller.cpp
**
** Made by Louis-Emile Uberti-Ares
** Login   <louis-emile.uberti-ares@epitech.eu>
**
** Started on  mar. févr. 07 11:18:56 2017 Louis-Emile Uberti-Arès
** Last update mar. févr. 07 11:18:56 2017 Louis-Emile Uberti-Arès
*/

#include <fstream>
#include <regex>
#include <algorithm>
#include <signal.h>
#include "Controller.hpp"

static bool        toloop;

static inline void trim(std::string &s)
{
    s.erase(s.begin(), std::find_if(s.begin(), s.end(),
                                    std::not1(std::ptr_fun<int, int>(std::isspace))));
    s.erase(std::find_if(s.rbegin(), s.rend(),
                         std::not1(std::ptr_fun<int, int>(std::isspace))).base(), s.end());
}

nts::Controller::Controller() :
    _oldfile(""), _parser(new Parser())
{
    _actions["display"] = [this]() { _parser->displayAll(); };
    _actions["dump"] = [this]() { _parser->Dump(); };
    _actions["clear"] = []() { std::cout << "\033c"; };
    _actions["loop"] = [this]() { loop(); };
    _actions["simulate"] = [this]() { _parser->simulateAll(); };
    _actions["help"] = [this]() { usage(); };
}

int                 nts::Controller::usage() const
{
    std::cout << "\033c" << std::endl;
    std::cout << BOLD << "NAME" << BASIC << std::endl << "\tnanotekspice - Electrical circuit simulator" << std::endl << std::endl;
    std::cout << BOLD << "SYNOPSIS" << std::endl << "\t" << BASIC << USAGE << std::endl << std::endl;
    std::cout << BOLD << "DESCRIPTION" << BASIC << std::endl << "\tnanotekspice is an EPITECH project to develop an electrical circuit simulator" << std::endl << std::endl;
    std::cout << BOLD << "COMMAND-LINE OPTIONS" << BASIC << std::endl << "\tThose arguments need to be used DURING the execution of the program. (except '--help' AND '-h')\n\tArguments available are case-sensitive" << std::endl << std::endl;
    std::cout << BOLD << "\t-h --help" << BASIC << std::endl << "\t\tDisplays a help page and exit" << std::endl << std::endl;
    std::cout << BOLD << "\tloop" << BASIC << std::endl << "\t\tSimulates without prompting until a SIGINT signal is sent" << std::endl << std::endl;
    std::cout << BOLD << "\tsimulate" << BASIC << std::endl << "\t\tLaunches a simulation" << std::endl << std::endl;
    std::cout << BOLD << "\tload file.nts" << BASIC << std::endl << "\t\tLoads the new file and feeds it to the tree" << std::endl << "\t\tOn error, reload the old configuration" << std::endl << std::endl;
    std::cout << BOLD << "\tdump" << BASIC << std::endl << "\t\tCalls the Dump method of every IComponent" << std::endl << std::endl;
    std::cout << BOLD << "\tdisplay" << BASIC << std::endl << "\t\tPrints on stdout the value of all outputs sorted by name" << std::endl << std::endl;
    std::cout << BOLD << "\texit" << BASIC << std::endl << "\t\tCloses the program" << std::endl << std::endl;
    std::cout << BOLD << "\tINPUT=x" << BASIC << std::endl << "\t\tChanges the INPUT's value to the desired value (0 or 1).\n\t\tWarning : Input's name are case sensitive" << std::endl << std::endl;
    std::cout << BOLD << "AUTHORS" << BASIC << std::endl << "\tnanotekspice was developed by a team of 2 talented developers :" << std::endl
                  << "\t- Louis-Emile UBERTI-ARES : Parser implementation and data structure" << std::endl
                  << "\t- Come GRELLARD : Research / specification and component development" << std::endl << std::endl << "nanotekspice 1.0.0 - 2017" << std::endl;
    return (0);
}

void                nts::Controller::readFeed(const std::string &filename, bool error)
{
    std::ifstream   file;
    std::string     line;

    _content.clear();
    if (filename.substr((filename.find_last_of('.') == std::string::npos) ? (0) : (filename.find_last_of('.')),
                        filename.size()).compare(".nts") != 0)
    {
        if (error)
            throw nts::InputError("File has wrong extension (should be .nts)");
        else
        {
            std::cerr << "File has wrong extension (should be .nts)" << std::endl;
            readFeed(_oldfile, false);
            return ;
        }
    }
    file.open(filename);
    if (!file.good())
    {
        if (error)
            throw nts::InputError(filename + ": No such file");
        else
        {
            std::cerr << filename << ": No such file\nGoing back to old config '" << _oldfile << "'" << std::endl;
            readFeed(_oldfile, false);
            return ;
        }
    }
    while (file.good())
    {
        std::getline(file, line);
        _content.push_back(line);
    }
    for (const std::string &line : _content)
        _parser->feed(line);
    _oldfile = filename;
}

void                    nts::Controller::handleCMD(const std::string &cmd, bool dothrow)
{
    static std::regex   checker("[[:alnum:]]+=[0-1]");

    if (cmd.substr(0, cmd.find_first_of(" ")).compare("load") == 0)
    {
        load(cmd);
        return ;
    }
    if (_actions.find(cmd) == _actions.end())
    {
        if (std::regex_match(cmd.begin(), cmd.end(), checker))
            _parser->updateValue(cmd.substr(0, cmd.find_first_of('=')),
                                 cmd.substr(cmd.find_first_of('=') + 1, cmd.size()), dothrow);
        else if (dothrow)
            throw nts::CommandLineError("Argument '" + cmd + "' is not recognized.");
        else
            std::cerr << "nanotekspice: Unknown command '" << BOLD << cmd << BASIC << "'." << std::endl;
    }
    else if (_actions.find(cmd) != _actions.end() && dothrow)
        throw nts::ExecError("Cannot use option '" + cmd + "' in program arguments.");
    else if (!dothrow)
        _actions[cmd]();
}

void                nts::Controller::load(const std::string &cmd)
{
    size_t          pos = ((cmd.find_last_of(" ") == std::string::npos) ? (0) : (cmd.find_last_of(" ") + 1));
    std::string     save;

    if (pos == 0)
    {
        std::cerr << "load: No file provided" << std::endl;
        return ;
    }
    _parser->deleteAll();
    save = _oldfile;
    readFeed("./" + cmd.substr(pos, cmd.size()), false);
    try
    {
        _parser->parseTree(*_parser->createTree());
        _actions["simulate"]();
        _actions["display"]();
    }
    catch (const nts::Error &e)
    {
        std::cerr << "nanotekspice: Error while simulating with file '" << _oldfile << "': " << e.what() << std::endl;
        std::cerr << "Going back to old config file '" << save << "'" << std::endl;
        _parser->deleteAll();
        readFeed(save, false);
        _parser->parseTree(*_parser->createTree());
        _actions["simulate"]();
        _actions["display"]();
    }
}

void            nts::Controller::loop()
{
    toloop = true;
    signal(SIGINT, [](int) { toloop = false; });
    std::cout << "Looping... (Use Ctrl+C to abort)" << std::endl;
    while (toloop)
        _actions["simulate"]();
    signal(SIGINT, SIG_DFL);
}

void                    nts::Controller::run(int ac, const char **av)
{
    t_ast_node          *tree;
    std::string         input;
    std::string         check;

    tree = _parser->createTree();
    _parser->parseTree(*tree);
    check = _parser->allLinked();
    if (check.compare("ALL LINKED !") != 0)
        throw nts::ExecError("Output '" + check + "' is not linked to anything");
    for (int i = 2; i < ac; i++)
        handleCMD(av[i], true);
    _actions["simulate"]();
    _actions["display"]();
    std::cout << "> ";
    while (std::getline(std::cin, input))
    {
        trim(input);
        if (input.compare("exit") == 0)
            break;
        if (!input.empty())
            handleCMD(input, false);
        std::cout << "> ";
    }
}