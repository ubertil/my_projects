//
// Highscore.hpp for Highscore in /home/uberti_l/rendu/Prog_Elem/cpp_arcade
//
// Made by Lous-Emile Uberti-Ares
// Login   <uberti_l@epitech.net>
//
// Started on  Fri Apr  7 23:30:32 2017 Lous-Emile Uberti-Ares
// Last update Sun Apr  9 22:50:08 2017 Lous-Emile Uberti-Ares
//

#pragma once
# include <algorithm>
# include <vector>
# include <fstream>

static bool			compareHighScore(const std::string &str1,
						 const std::string &str2)
{
  int				score1;
  int				score2;
  std::string			s1;
  std::string			s2;

  s1 = str1.substr(str1.find_last_of("_") + 1, str1.find_last_of("."));
  s1 = s1.substr(s1.find_first_of(" ") + 1, s1.size());
  s2 = str2.substr(str2.find_last_of("_") + 1, str2.find_last_of("."));
  s2 = s2.substr(s2.find_first_of(" ") + 1, s2.size());
  score1 = std::atoi(s1.c_str());
  score2 = std::atoi(s2.c_str());
  return (score1 > score2);
}

namespace arcade
{
  class Highscore
  {
  public:
    Highscore() :
      key("@%$**/")
    {
      std::fstream	file(".highscores.save", std::fstream::in | std::fstream::app);
      std::string	line;

      while (std::getline(file, line))
	this->highscores.insert(this->highscores.end(), this->encryptDecrypt(line));
      file.close();
    }

    ~Highscore() = default;

    std::vector<std::string>		getHighscores(const std::string &gameName,
						      const int required) const
    {
      std::vector<std::string>		all;
      std::vector<std::string>		ret;
      int				nb = 0;
      size_t				from;
      size_t				to;
      std::string			score;

      for (auto const &e : this->highscores)
	{
	  from = e.find_first_of("|");
	  to = e.find_last_of("|");
	  if (from != std::string::npos && to != std::string::npos)
	    if (e.substr(0, from).compare(gameName) == 0)
	      {
		score = e.substr(from + 1, e.size());
		to = score.find_last_of("|");
		if (to != std::string::npos)
		  {
		    score = score.replace(to, 1, " ");
		    all.insert(all.end(), score);
		  }
	      }
	}
      std::sort(all.begin(), all.end(), compareHighScore);
      for (auto const &e : all)
	{
	  if (nb == required)
	    return (ret);
	  ret.insert(ret.end(), e);
	  nb++;
	}
      return (ret);
    }

    void				setHighscore(const std::string &gameName,
						     const std::string &name,
						     int score)
    {
      std::ofstream			file(".highscores.save", std::ios::app);
      std::string			nb(6 - std::to_string(score).size(), '0');
      std::string			toEncrypt;

      nb.append(std::to_string(score));
      toEncrypt += gameName + "|" + name + "|" + nb;
      this->highscores.insert(this->highscores.end(), toEncrypt);
      file << this->encryptDecrypt(toEncrypt) << std::endl;
      file.close();
    }

    int					getHighestScore(const std::string &gameName) const
    {
      size_t				from;
      size_t				to;
      int				highest;
      int				compare;

      highest = 0;
      for (auto const &e : this->highscores)
	{
	  from = e.find_first_of("|");
	  to = e.find_last_of("|");
	  if (from != std::string::npos && to != std::string::npos)
	    {
	      if (e.substr(0, from).compare(gameName) == 0)
		{
		  compare = std::atoi(e.substr(to + 1, e.size()).c_str());
		  if (compare > highest)
		    highest = compare;
		}
	    }
	}
      return (highest);
    }
  private:
    const std::string			encryptDecrypt(const std::string &toEncrypt) const
    {
      std::string			output;
      size_t				i;

      for (i = 0; i < toEncrypt.size(); i++)
	output += (toEncrypt[i] ^ key[i % key.size()]);
      return (output);
    }
    const std::string			key;
    std::vector<std::string>		highscores;
  };
};
