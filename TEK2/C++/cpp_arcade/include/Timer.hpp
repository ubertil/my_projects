//
// Timer.hpp for timer in /home/uberti_l/rendu/Prog_Elem/cpp_arcade
//
// Made by Lous-Emile Uberti-Ares
// Login   <uberti_l@epitech.net>
//
// Started on  Tue Apr  4 12:45:27 2017 Lous-Emile Uberti-Ares
// Last update Thu Apr  6 11:50:22 2017 Lous-Emile Uberti-Ares
//

#pragma once
# include <ctime>

namespace arcade
{
  class Timer
  {
  public:
    Timer() :
      resetted(false), running(false), beg(0), end(0) {}

    ~Timer() = default;

    void		start()
    {
      if (!this->running)
	{
	  if (this->resetted)
	    this->beg = clock();
	  else
	    this->beg -= this->end - clock();
	  this->running = true;
	  this->resetted = false;
	}
    }

    void		stop()
    {
      if (this->running)
	{
	  this->end = clock();
	  this->running = false;
	}
    };

    void		reset()
    {
      bool wereRunning = running;

      if (wereRunning)
	this->stop();
      this->resetted = true;
      this->beg = 0;
      this->end = 0;
      if (wereRunning)
	this->start();
    }

    bool		isRunning() const
    {
      return (this->running);
    }

    clock_t		getTime() const
    {
      if (this->running)
	return ((unsigned long)clock() - this->beg) / CLOCKS_PER_SEC;
      else
	return ((this->end - this->beg) / CLOCKS_PER_SEC);
    }
  private:
    bool		resetted;
    bool		running;
    clock_t		beg;
    clock_t		end;
  };
};
