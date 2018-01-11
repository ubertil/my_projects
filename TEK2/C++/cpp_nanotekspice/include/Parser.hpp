/*
** Parser.hpp for nanotekspice in /home/uberti_p/delivery/nanotekspice/Parser.hpp
**
** Made by Louis-Emile Uberti-Ares
** Login   <louis-emile.uberti-ares@epitech.eu>
**
** Started on  jeu. févr. 02 11:03:05 2017 Louis-Emile Uberti-Arès
** Last update jeu. févr. 02 11:03:05 2017 Louis-Emile Uberti-Arès
*/

#pragma once
# include <map>
# include <memory>
# include <unordered_set>
# include "IParser.hpp"
# include "Manager.hpp"

namespace nts
{
    class Parser : public IParser
    {
    public:
        Parser();
        ~Parser() {}
        void                deleteAll();
        void                feed(std::string const &input) final;
        void                parseTree(t_ast_node &root) final;
        void                updateValue(const std::string &, const std::string &, bool);
        void                Dump() const;
        void                createLink(t_ast_node &root);
        void                createComponent(t_ast_node &root);
        void                simulateAll();
        void                displayAll() const;
        std::string const   allLinked() const;
        nts::ASTNodeType    getType(const std::string &) const;
        std::string const   updateType(const std::string &);
        std::string const   getName(const std::string &);
        std::string const   getValue(const std::string &);
        t_ast_node          *createTree();
        t_ast_node          *createChildren(t_ast_node *, std::string const &);
    private:
        std::string                                             _section;
        std::vector<std::string>                                _content;
        std::map<std::string, IComponent *>                     _cmp;
        std::map<std::string, nts::CmpOutput *>                 _outputs;
        std::unordered_set<std::string>                         _verify;
        std::unordered_set<std::string>                         _names;
        std::unique_ptr<nts::Manager>                           _manager;
    };
};