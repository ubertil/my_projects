/*
** IniManager.cpp for cpp_indie_studio in /home/login_p/delivery/cpp_indie_studio/IniManager.cpp
**
** Made by Alexis Papadimitriou
** Login   <alexis.papadimitriou@epitech.eu>
**
** Started on  Mon May 29 15:16:17 2017 Alexis Papadimitriou
** Last update Mon May 29 15:16:17 2017 Alexis Papadimitriou
*/

#include <iostream>
#include <sstream>
#include "Error.hpp"
#include "Utils/IniManager.hpp"

Sprint::Utils::IniManager::IniManager(std::string const &file) :
#ifdef _WIN32
	m_r_sanitizer("( |\\t)"), m_r_scope("^\\[\\w+\\]$"), m_r_field("^[a-zA-Z]+=[a-zA-Z0-9,.]+$")
#else
	m_r_sanitizer("( |\t)"), m_r_scope("^\\[[a-zA-Z0-9]+\\]$"), m_r_field("^[a-zA-Z]+=[a-zA-Z0-9,.]+$")
#endif
{
    this->loadFile(file);
}

Sprint::Utils::IniManager::~IniManager()
{
    this->save();
}

const std::unordered_map<std::string, std::vector<std::string>>   &Sprint::Utils::IniManager::getFromScope(std::string const &scope) const
{
    return (this->m_data.at(scope));
};

void                            Sprint::Utils::IniManager::getFieldData(std::string const &scope, std::string const &field, std::string const &data)
{
    std::stringstream           s_data(data);
    std::string                 part;

	while (std::getline(s_data, part, ','))
		this->m_data[scope][field].emplace_back(part);
}

void                            Sprint::Utils::IniManager::loadFile(std::string const &path)
{
    std::ifstream               file(path);
    std::string                 current_scope = "default";
    std::string                 line;

	this->m_filepath = path;
	if (!file.is_open())
        return ;
	this->m_data.clear();

	while (std::getline(file, line))
    {
		line = std::regex_replace(line, this->m_r_sanitizer, "");
		if (std::regex_match(line, this->m_r_scope))
        {
			current_scope = line.substr(1, line.length() - 2);
			this->m_data[current_scope];
        }
        else if (std::regex_match(line, this->m_r_field))
            this->getFieldData(current_scope, line.substr(0, line.find('=')), line.substr(line.find('=') + 1));
    }
    file.close();
}

void                            Sprint::Utils::IniManager::save()
{
    std::ofstream   file(this->m_filepath, std::ios::trunc);

    if (file.is_open()) {
        for (const auto &scope : this->m_data)
        {
            file << "[";
            file << scope.first << "]" << std::endl;
            for (const auto &field : scope.second)
            {
                file << field.first << "=";
                for (const auto &data : field.second)
                    file << data << ",";
                file << std::endl;
            }
        }
    }
    file.close();
}

namespace Sprint
{
    namespace Utils
    {
        template <>
        std::string     IniManager::getData<std::string>(const std::string &scope, const std::string &field, const int idx) const
        {
			try
            {
                return (this->m_data.at(scope).at(field).at(idx));
            }
            catch (const std::out_of_range &err)
            {
                throw Sprint::Error::UtilError("Failed to retrieve string from scope: " + scope);
            }
        }

        template <>
        int             IniManager::getData<int>(const std::string &scope, const std::string &field, const int idx) const
        {
			try
            {
                return (std::stoi(this->m_data.at(scope).at(field).at(idx)));
            }
            catch (const std::out_of_range &err)
            {
				throw Sprint::Error::UtilError("Failed to retrieve int from scope: " + scope);
            }
        }

        template <>
        float           IniManager::getData<float>(const std::string &scope, const std::string &field, const int idx) const
        {
			try
            {
                return (std::stof(this->m_data.at(scope).at(field).at(idx)));
            }
            catch (const std::out_of_range &err)
            {
                throw Sprint::Error::UtilError("Failed to retrieve float from scope: " + scope);
            }
        }

        template <>
        bool            IniManager::getData<bool>(const std::string &scope, const std::string &field, const int idx) const
        {
			try
            {
                return (std::stoi(this->m_data.at(scope).at(field).at(idx)) != 0);
            }
            catch (const std::out_of_range &err)
            {
                throw Sprint::Error::UtilError("Failed to retrieve bool from scope: " + scope);
            }
        }
    };
};

void                            Sprint::Utils::IniManager::resetFile()
{

}

void                            Sprint::Utils::IniManager::resetScope(std::string const &scope)
{
    this->m_data.at(scope).clear();
}

void                            Sprint::Utils::IniManager::resetField(std::string const &scope, std::string const &field)
{
    this->m_data.at(scope).at(field).clear();
}

void                            Sprint::Utils::IniManager::removeScope(std::string const &scope)
{
    this->m_data.erase(scope);
}

void                            Sprint::Utils::IniManager::removeField(std::string const &scope, std::string const &field)
{
    this->m_data.at(scope).erase(field);
}