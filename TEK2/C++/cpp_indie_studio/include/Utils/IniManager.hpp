/*
** IniManager.hpp for cpp_indie_studio in /home/login_p/delivery/cpp_indie_studio/IniManager.hpp
**
** Made by Alexis Papadimitriou
** Login   <alexis.papadimitriou@epitech.eu>
**
** Started on  Mon May 29 14:32:50 2017 Alexis Papadimitriou
** Last update Mon May 29 14:32:50 2017 Alexis Papadimitriou
*/

#pragma once
# include <string>
# include <unordered_map>
# include <vector>
# include <fstream>
# include <regex>
# include "Error.hpp"

namespace                        Sprint
{
    namespace                    Utils
    {
        enum                    iniMode
        {
            RD_MODE = std::fstream::in,
            WR_MODE = std::fstream::out
        };

        class                   IniManager
        {
        private:
            std::unordered_map<std::string, std::unordered_map<std::string, std::vector<std::string>>>  m_data;
            std::regex          m_r_sanitizer;
            std::regex          m_r_scope;
            std::regex          m_r_field;
            std::string         m_filepath;

            void                getFieldData(std::string const &scope, std::string const &field, std::string const &data);

        public:
            IniManager(std::string const &file);
            IniManager(const IniManager &cpy) = delete;

            ~IniManager();


            template <class T>
            T             getData(const std::string &scope, const std::string &field, const int idx) const;

            const std::unordered_map<std::string, std::vector<std::string>>   &getFromScope(std::string const &scope) const;
            void                loadFile(std::string const &path);
            void                save();
            void                resetFile();
            void                resetScope(std::string const &scope);
            void                resetField(std::string const &scope, std::string const &field);
            void                removeScope(std::string const &scope);
            void                removeField(std::string const &scope, std::string const &field);

            void                addData(std::string const &scope, std::string const &field) {}

            template <typename Arg, typename... Args>
            void                addData(std::string const &scope, std::string const &field, const Arg &arg, Args&&... args)
            {
                this->m_data[scope][field].emplace_back(arg);
                return addData(scope, field, std::forward<Args>(args)...);
            }

            template <typename Arg, typename... Args>
            void                resetData(std::string const &scope, std::string const &field, const Arg &arg, Args&&... args)
            {
                this->m_data[scope][field].clear();
                return this->addData(scope, field, arg, std::forward<Args>(args)...);
            }
        };
    }
}