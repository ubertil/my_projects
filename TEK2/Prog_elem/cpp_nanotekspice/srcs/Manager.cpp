/*
** Manager.cpp for nanotekspice in /home/uberti_p/delivery/nanotekspice/Manager.cpp
**
** Made by Louis-Emile Uberti-Ares
** Login   <louis-emile.uberti-ares@epitech.eu>
**
** Started on  jeu. févr. 02 11:42:38 2017 Louis-Emile Uberti-Arès
** Last update jeu. févr. 02 11:42:38 2017 Louis-Emile Uberti-Arès
*/

#include "Manager.hpp"

nts::Manager::Manager()
{
    _components["4001"] = std::bind(&nts::Manager::create4001, this, std::placeholders::_1);
    _components["4008"] = std::bind(&nts::Manager::create4008, this, std::placeholders::_1);
    _components["4011"] = std::bind(&nts::Manager::create4011, this, std::placeholders::_1);
    _components["4013"] = std::bind(&nts::Manager::create4013, this, std::placeholders::_1);
    _components["4017"] = std::bind(&nts::Manager::create4017, this, std::placeholders::_1);
    _components["4030"] = std::bind(&nts::Manager::create4030, this, std::placeholders::_1);
    _components["4040"] = std::bind(&nts::Manager::create4040, this, std::placeholders::_1);
    _components["4069"] = std::bind(&nts::Manager::create4069, this, std::placeholders::_1);
    _components["4071"] = std::bind(&nts::Manager::create4071, this, std::placeholders::_1);
    _components["4081"] = std::bind(&nts::Manager::create4081, this, std::placeholders::_1);
    _components["4094"] = std::bind(&nts::Manager::create4094, this, std::placeholders::_1);
    _components["4514"] = std::bind(&nts::Manager::create4514, this, std::placeholders::_1);
    _components["4801"] = std::bind(&nts::Manager::create4801, this, std::placeholders::_1);
    _components["2716"] = std::bind(&nts::Manager::create2716, this, std::placeholders::_1);
    _components["input"] = std::bind(&nts::Manager::createInput, this, std::placeholders::_1);
    _components["clock"] = std::bind(&nts::Manager::createClock, this, std::placeholders::_1);
    _components["true"] = std::bind(&nts::Manager::createTrue, this, std::placeholders::_1);
    _components["false"] = std::bind(&nts::Manager::createFalse, this, std::placeholders::_1);
    _components["output"] = std::bind(&nts::Manager::createOutput, this, std::placeholders::_1);
}

nts::IComponent     *nts::Manager::createComponent(const std::string &type, const std::string &value) const
{
    std::string     error("Cannot create component of unknown type '");

    if (_components.find(type) == _components.end())
    {
        error.append(type).append("'");
        throw nts::ComponentError(error);
    }
    else
        return (_components.at(type)(value));

}

nts::IComponent     *nts::Manager::create4001(const std::string &value) const
{
    return (new Cmp4001(value));
}

nts::IComponent     *nts::Manager::create4008(const std::string &value) const
{
    return (new Cmp4008(value));
}

nts::IComponent     *nts::Manager::create4011(const std::string &value) const
{
    return (new Cmp4011(value));
}

nts::IComponent     *nts::Manager::create4013(const std::string &value) const
{
    return (new Cmp4013(value));
}

nts::IComponent     *nts::Manager::create4017(const std::string &value) const
{
    return (new Cmp4017(value));
}

nts::IComponent     *nts::Manager::create4030(const std::string &value) const
{
    return (new Cmp4030(value));
}

nts::IComponent     *nts::Manager::create4040(const std::string &value) const
{
    return (new Cmp4040(value));
}

nts::IComponent     *nts::Manager::create4069(const std::string &value) const
{
    return (new Cmp4069(value));
}

nts::IComponent     *nts::Manager::create4071(const std::string &value) const
{
    return (new Cmp4071(value));
}

nts::IComponent     *nts::Manager::create4081(const std::string &value) const
{
    return (new Cmp4081(value));
}

nts::IComponent     *nts::Manager::create4094(const std::string &value) const
{
    return (new Cmp4094(value));
}

nts::IComponent     *nts::Manager::create4514(const std::string &value) const
{
    return (new Cmp4514(value));
}

nts::IComponent     *nts::Manager::create4801(const std::string &value) const
{
    return (new Cmp4801(value));
}

nts::IComponent     *nts::Manager::create2716(const std::string &value) const
{
    return (new Cmp2716(value));
}

nts::IComponent     *nts::Manager::createInput(const std::string &value) const
{
    return (new CmpInput(value));
}

nts::IComponent     *nts::Manager::createClock(const std::string &value) const
{
    return (new CmpClock(value));
}

nts::IComponent     *nts::Manager::createTrue(const std::string &value) const
{
    return (new CmpTrue(value));
}

nts::IComponent     *nts::Manager::createFalse(const std::string &value) const
{
    return (new CmpFalse(value));
}

nts::IComponent     *nts::Manager::createOutput(const std::string &value) const
{
    return (new CmpOutput(value));
}