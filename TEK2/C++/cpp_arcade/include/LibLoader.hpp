/*
** LibLoader.hh for cpp_arcade in /home/uberti_p/delivery/cpp_arcade/LibLoader.hh
**
** Made by Louis-Emile Uberti-Ares
** Login   <louis-emile.uberti-ares@epitech.eu>
**
** Started on  sam. mars 18 21:58:33 2017 Louis-Emile Uberti-Arès
// Last update Sun Apr  9 22:47:17 2017 Lous-Emile Uberti-Ares
*/

#pragma once
# include <string>
# include <dlfcn.h>
# include "Vec.hpp"
# include "Error.hpp"

namespace arcade
{
  template <typename T>
  class LibLoader
  {
  private:
    void		*handle;
  public:
    LibLoader(const std::string &path)
    {
      this->handle = nullptr;
      this->loadLibrary(path);
    }

    ~LibLoader()
    {
      if (this->handle != nullptr)
	dlclose(this->handle);
    }

    T			*getFunc(const Vec2i &dim, const std::string &name, const std::string &func)
    {
      T			*(*ptr)(const Vec2i &, const std::string &);

      ptr = reinterpret_cast<T *(*)(const Vec2i &, const std::string &)>(dlsym(this->handle, func.c_str()));
      if (ptr == nullptr)
	return (nullptr);
      return (ptr(dim, name));
    }

    void		loadLibrary(const std::string &path)
    {
      if (this->handle != nullptr)
	dlclose(this->handle);
      this->handle = dlopen(path.c_str(), RTLD_NOW);
      if (this->handle == nullptr)
	throw arcade::LibError(dlerror());
    }
  };
};
