/*
** CmpOutput.hpp for nanotekspice in /home/uberti_p/delivery/nanotekspice/CmpOutput.hpp
**
** Made by Louis-Emile Uberti-Ares
** Login   <louis-emile.uberti-ares@epitech.eu>
**
** Started on  jeu. févr. 02 15:24:21 2017 Louis-Emile Uberti-Arès
** Last update jeu. févr. 02 15:24:21 2017 Louis-Emile Uberti-Arès
*/

#pragma once
# include "IComponent.hpp"

namespace nts
{
    class   CmpOutput : public IComponent
    {
    public:
        CmpOutput(const std::string &);
        virtual ~CmpOutput() {}
        nts::Tristate Compute(size_t pin_num_this = 1) final;
        void SetLink(size_t pin_num_this,
                     nts::IComponent &component,
                     size_t pin_num_target) final;
        void Dump(void) const final;
        void setValue(nts::Tristate value);
        void Display() const;
    private:
        std::string const   _name;
        nts::Tristate       _value;
        IComponent          *_comp;
        size_t              _pin_this;
        size_t              _pin_target;
    };
}
