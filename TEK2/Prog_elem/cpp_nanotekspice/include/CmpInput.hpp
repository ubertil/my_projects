/*
** CmpInput.hpp for nanotekspice in /home/uberti_p/delivery/nanotekspice/CmpInput.hpp
**
** Made by Louis-Emile Uberti-Ares
** Login   <louis-emile.uberti-ares@epitech.eu>
**
** Started on  jeu. févr. 02 15:09:19 2017 Louis-Emile Uberti-Arès
** Last update jeu. févr. 02 15:09:19 2017 Louis-Emile Uberti-Arès
*/

#pragma once
# include "IComponent.hpp"

namespace nts
{
    class   CmpInput : public IComponent
    {
    public:
        CmpInput(const std::string &);  
        virtual ~CmpInput() {}
        nts::Tristate Compute(size_t pin_num_this = 1) final;
        void SetLink(size_t pin_num_this,
                     nts::IComponent &component,
                     size_t pin_num_target) final;
        void Dump(void) const final;
        void setValue(nts::Tristate value);
    private:
        std::string const   _name;
        nts::Tristate       _value;
    };
}
