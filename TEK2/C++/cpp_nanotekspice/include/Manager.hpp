/*
** Component.hpp for nanotekspice in /home/uberti_p/delivery/nanotekspice/Component.hpp
**
** Made by Louis-Emile Uberti-Ares
** Login   <louis-emile.uberti-ares@epitech.eu>
**
** Started on  jeu. févr. 02 11:14:07 2017 Louis-Emile Uberti-Arès
** Last update jeu. févr. 02 11:14:07 2017 Louis-Emile Uberti-Arès
*/

#pragma once
# include <unordered_map>
# include "IComponent.hpp"
# include "Cmp4001.hpp"
# include "Cmp4008.hpp"
# include "Cmp4011.hpp"
# include "Cmp4013.hpp"
# include "Cmp4017.hpp"
# include "Cmp4030.hpp"
# include "Cmp4040.hpp"
# include "Cmp4069.hpp"
# include "Cmp4071.hpp"
# include "Cmp4081.hpp"
# include "Cmp4094.hpp"
# include "Cmp4514.hpp"
# include "Cmp4801.hpp"
# include "Cmp2716.hpp"
# include "CmpInput.hpp"
# include "CmpClock.hpp"
# include "CmpTrue.hpp"
# include "CmpFalse.hpp"
# include "CmpOutput.hpp"

namespace nts
{
    class Manager
    {
    public:
        Manager();
        ~Manager() {}
        IComponent *createComponent(const std::string &type, const std::string &value) const;
    private:
        IComponent *create4001(const std::string &value) const;
        IComponent *create4008(const std::string &value) const;
        IComponent *create4011(const std::string &value) const;
        IComponent *create4013(const std::string &value) const;
        IComponent *create4017(const std::string &value) const;
        IComponent *create4030(const std::string &value) const;
        IComponent *create4040(const std::string &value) const;
        IComponent *create4069(const std::string &value) const;
        IComponent *create4071(const std::string &value) const;
        IComponent *create4081(const std::string &value) const;
        IComponent *create4094(const std::string &value) const;
        IComponent *create4514(const std::string &value) const;
        IComponent *create4801(const std::string &value) const;
        IComponent *create2716(const std::string &value) const;
        IComponent *createInput(const std::string &value) const;
        IComponent *createClock(const std::string &value) const;
        IComponent *createTrue(const std::string &value) const;
        IComponent *createFalse(const std::string &value) const;
        IComponent *createOutput(const std::string &value) const;
        std::unordered_map<std::string, std::function<IComponent *(std::string const &)>> _components;
    };
};