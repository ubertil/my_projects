/*
** Parser.cpp for nanotekspice in /home/uberti_p/delivery/nanotekspice/Parser.cpp
**
** Made by Louis-Emile Uberti-Ares
** Login   <louis-emile.uberti-ares@epitech.eu>
**
** Started on  jeu. févr. 02 11:41:58 2017 Louis-Emile Uberti-Arès
** Last update jeu. févr. 02 11:41:58 2017 Louis-Emile Uberti-Arès
*/

#include <algorithm>
#include <regex>
#include "Error.hpp"
#include "Parser.hpp"

int                     nts::timer = -1;

static inline bool      is_num(const std::string &s)
{
    return (s.find_first_not_of(" 0123456789") == std::string::npos);
}

nts::Parser::Parser() :
    _section("uberti_l:grella_c"), _manager(new nts::Manager())
{
    _verify.insert({"4001", "4008", "4011", "4013", "4017", "4030", "4040", "4040", "4069", "4071", "4081",
                   "4514", "4801", "2716", "clock", "input", "false", "true", "output", "terminal"});
}

void                    nts::Parser::feed(std::string const &input)
{
    static std::regex   normalize("[\\s]+");
    std::string         line(std::regex_replace(input, normalize, " "));
    size_t              pos = (line.find('#') == std::string::npos) ? (0) : (line.find('#'));

    if (line[0] != '#' && pos > 0)
        _content.push_back(line.substr(0, pos));
    else if (line[0] != '#')
        _content.push_back(line);
}

void                    nts::Parser::parseTree(t_ast_node &root)
{
    if (root.type == nts::ASTNodeType ::LINK || root.type == nts::ASTNodeType::LINK_END)
        createLink(root);
    else if (root.type == nts::ASTNodeType::COMPONENT)
        createComponent(root);
    if (root.children->front() != nullptr)
       parseTree(*root.children->front());
}

void                    nts::Parser::Dump() const
{
    if (!_cmp.empty())
    {
        std::cout << BOLD << "List of all components:" << BASIC << std::endl;
        for (auto const &component : _cmp)
        {
            std::cout << GREEN << " Component '" << component.first << "':" << BASIC << "\n";
            component.second->Dump();
            std::cout << std::endl;
        }
    }
}

void                    nts::Parser::simulateAll()
{
    nts::timer += 1;
    for (auto const &e : _outputs)
        e.second->Compute(1);
}

void                    nts::Parser::displayAll() const
{
    for (auto const &e : _outputs)
        e.second->Display();
}

void                    nts::Parser::updateValue(const std::string &cmp_name, const std::string &value, bool dothrow)
{
    if (_cmp.empty())
        throw ExecError("No components found in file");
    if (_cmp.find(cmp_name) != _cmp.end())
    {
        if (dynamic_cast<nts::CmpInput *>(_cmp[cmp_name]) == nullptr && dynamic_cast<nts::CmpClock *>(_cmp[cmp_name]) == nullptr)
        {
            if (dothrow)
                throw InputError("Cannot change value of non Input/Clock type.");
            else
            {
                std::cerr << "Cannot change value of non Input/Clock type." << std::endl;
                return;
            }
        }
        (dynamic_cast<nts::CmpInput *>(_cmp[cmp_name]) != nullptr) ?
        (dynamic_cast<nts::CmpInput *>(_cmp[cmp_name])->setValue((std::atoi(value.c_str()) == 1) ?
                                                                (nts::Tristate::TRUE) : (nts::Tristate::FALSE))) :
        (dynamic_cast<nts::CmpClock *>(_cmp[cmp_name])->setValue((std::atoi(value.c_str()) == 1) ?
                                                                 (nts::Tristate::TRUE) : (nts::Tristate::FALSE)));
    }
    else if (dothrow)
        throw nts::InputError("No component named '" + cmp_name + "'");
    else
        std::cerr << "No component named '" << cmp_name << "'" <<std::endl;
}

void                    nts::Parser::createLink(t_ast_node &root)
{
    std::string         name1 = root.lexeme.substr(0, root.lexeme.find_first_of(':'));
    std::string         name2 = root.value.substr(0, root.value.find_first_of(':'));
    size_t              pin1 = std::atoi(root.lexeme.substr(root.lexeme.find_first_of(':') + 1, root.lexeme.size()).c_str());
    size_t              pin2 = std::atoi(root.value.substr(root.value.find_first_of(':') + 1, root.value.size()).c_str());

    _cmp[name1]->SetLink(pin1, *_cmp[name2], pin2);
    _cmp[name2]->SetLink(pin2, *_cmp[name1], pin1);
    if (dynamic_cast<nts::CmpOutput *>(_cmp[name1]) != nullptr)
        _outputs[name1] = dynamic_cast<nts::CmpOutput *>(_cmp[name1]);
    if (dynamic_cast<nts::CmpOutput *>(_cmp[name2]) != nullptr)
        _outputs[name2] = dynamic_cast<nts::CmpOutput *>(_cmp[name2]);
}

void                    nts::Parser::deleteAll()
{
    _section = "grella_c:uberti_l";
    _content.clear();
    _cmp.clear();
    _outputs.clear();
    _names.clear();
}

std::string const       nts::Parser::allLinked() const
{
    for (auto const &e : _cmp)
    {
        if (dynamic_cast<nts::CmpOutput *>(e.second) != nullptr &&
                _outputs.find(e.first) == _outputs.end())
            return (e.first);
    }
    return ("ALL LINKED !");
}

void                    nts::Parser::createComponent(t_ast_node &root)
{
    _cmp[root.lexeme] = _manager->createComponent(root.value, root.lexeme);
}

std::string const       nts::Parser::updateType(const std::string &line)
{
    if (line.compare(".chipsets:") != 0 && line.compare(".links:") != 0)
        throw (nts::InputError("Unknown section '" + line + "'"));
    else if (_section.compare(line) == 0)
        throw (nts::InputError("Redefinition of section '" + line + "' is strictly FORBIDDEN"));
    else if (_section.compare("uberti_l:grella_c") == 0 && line.compare(".links:") == 0)
        throw (nts::InputError("Cannot define .links section before .chipsets"));
    else
    {
        _section = line;
        return (_section);
    }
}

std::string const       nts::Parser::getName(const std::string &line)
{
    if (line.empty())
        return ("NEWLINE");
    size_t              grep = ((line.find_first_of(' ') == std::string::npos) ? (0) : (line.find_first_of(' ') + 1));
    std::string         search(line.substr(grep, line.size()));

    if (line[0] == '.')
        return (updateType(line));
    if (_section.compare(".chipsets:") == 0)
    {
        if (!_names.empty() && _names.find(search) != _names.end())
            throw (nts::InputError("Redefinition of component '" + search + "' is strictly FORBIDDEN"));
        _names.insert(search);
    }
    else if (_section.compare(".links:") == 0)
    {
        if (_names.find(search.substr(0, search.find_first_of(':'))) == _names.end())
            throw (nts::InputError("Component '" + search.substr(0, search.find_first_of(':')) + "' hasn't been defined"));
        if (!is_num(search.substr(search.find_first_of(':') + 1, search.size())))
            throw (nts::InputError("Cannot bind alphanumerical value to component '" +
                              search.substr(0, search.find_first_of(':')) + "'"));
    }
    return (search);

}

std::string const       nts::Parser::getValue(const std::string &line)
{
    if (line.empty())
        return ("NEWLINE");
    std::string         search(line.substr(0, line.find_first_of(' ')));

    if (line[0] == '.')
        return (_section);
    if (_section.compare(".chipsets:") == 0)
    {
        if (_verify.find(search) == _verify.end())
            throw (nts::InputError("Unknown type '" + search + "' cannot be evaluated"));
    }
    else if (_section.compare(".links:") == 0)
    {
        if (_names.find(search.substr(0, search.find_first_of(':'))) == _names.end())
            throw (nts::InputError("Component '" + search.substr(0, search.find_first_of(':')) +
                                   "' hasn't been defined"));
        else if (!is_num(search.substr(search.find_first_of(':') + 1, search.find_first_of(' '))))
        {
            throw (nts::InputError(
                    "Cannot bind alphanumerical value to component '" + search.substr(0, search.find_first_of(':')) +
                    "'"));
        }
    }
    return (search);
}

nts::ASTNodeType        nts::Parser::getType(const std::string &line) const
{
    if (line.empty())
        return (nts::ASTNodeType::NEWLINE);
    else if (line[0] == '.')
        return (nts::ASTNodeType::SECTION);
    else if (_section.compare(".chipsets:") == 0)
        return (nts::ASTNodeType::COMPONENT);
    else if (_section.compare(".links:") == 0)
        return (nts::ASTNodeType::LINK);
    else
        return (nts::ASTNodeType::DEFAULT);
}

nts::t_ast_node         *nts::Parser::createChildren(nts::t_ast_node *tree, std::string const &line)
{
    if (tree == nullptr)
    {
        try
        {
            tree = new t_ast_node(new std::vector<nts::t_ast_node *>);
            tree->children->push_back(nullptr);
        }
        catch (std::bad_alloc const &e)
        {
            std::cerr << e.what() << std::endl;
        }
        tree->value = getValue(line);
        tree->lexeme = getName(line);
        tree->type = getType(line);
    }
    else
    {
        if (tree->children->front() != nullptr)
            createChildren(tree->children->front(), line);
        else
        {
            try
            {
                tree->children->front() = new t_ast_node(new std::vector<nts::t_ast_node *>);
                tree->children->front()->children->push_back(nullptr);
            }
            catch (std::bad_alloc const &e)
            {
                std::cerr << e.what() << std::endl;
            }
            tree->children->front()->type = getType(line);
            tree->children->front()->value = getValue(line);
            tree->children->front()->lexeme = getName(line);
        }
    }
    return (tree);
}

nts::t_ast_node         *nts::Parser::createTree()
{
    nts::t_ast_node     *tree = nullptr;

    for (auto const &line : _content)
        tree = createChildren(tree, line);
    return (tree);
}