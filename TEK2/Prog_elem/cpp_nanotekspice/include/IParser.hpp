/*
** IParser.hpp for cpp_nanotekspice in /home/uberti_p/delivery/cpp_nanotekspice/IParser.hpp
**
** Made by Louis-Emile Uberti-Ares
** Login   <louis-emile.uberti-ares@epitech.eu>
**
** Started on  mer. févr. 01 14:25:19 2017 Louis-Emile Uberti-Arès
** Last update mer. févr. 01 14:25:19 2017 Louis-Emile Uberti-Arès
*/

#pragma once
# include <string>
# include <vector>

namespace nts
{
    enum class ASTNodeType : int
    {
        DEFAULT = -1,
        NEWLINE = 0,
        SECTION,
        COMPONENT,
        LINK,
        LINK_END,
        STRING
    };

    typedef struct s_ast_node
    {
        s_ast_node(std::vector<struct s_ast_node*> *children)
                : children(children) { }
        std::string    lexeme;
        ASTNodeType    type;
        std::string    value;
        std::vector<struct s_ast_node*> *children;
    } t_ast_node;

    class IParser
    {
    public:
        virtual void feed(std::string const& input) = 0;
        virtual void parseTree(t_ast_node& root) = 0;
        virtual t_ast_node *createTree() = 0;
    };
};