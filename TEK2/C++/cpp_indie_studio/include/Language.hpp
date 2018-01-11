//
// Created by uberti_l on 5/26/17.
//

#pragma once
# include <algorithm>
# include <string>
# include <memory>
# include <vector>
# include "Utils/Dir.hpp"
# include "Font/CStringTable.hpp"

namespace Sprint
{
    class Language
    {
    public:
        Language(irr::IrrlichtDevice &device, const std::string &id)
        {
            this->manager = std::make_unique<st::CStringTableManager>();
            this->manager->loadDirectory("../resources/languages", device.getFileSystem());
            // Available languages
            this->languages.emplace_back("Francais");
            this->languages.emplace_back("English");
            this->setCurrentLanguage(id);
        }
        Language(const Language &cpy) = delete;
        Language  operator&(const Language &cpy) = delete;
        ~Language() = default;

        const irr::core::ustring            getTranslation(const std::string &id)
        {
            return (st::_TT(id.c_str()).str());
        }

        const std::vector<std::string>      &getAvailableLanguages() const
        {
            return (this->languages);
        }

        const std::string                   &getCurrentLanguage() const
        {
            return (this->languages.at(this->curr_lang));
        }

        void                                setCurrentLanguage(const std::string &lang)
        {
            unsigned int                i = 0;

            for (const std::string &language : this->languages)
            {
                if (language.compare(lang) == 0)
                {
                    this->curr_lang = i;
                    const core::ustring new_lang = this->languages.at(i).c_str();
                    this->manager->setActiveStringTable(new_lang);
                    break;
                }
                i++;
            }
        }

    private:
        std::unique_ptr<st::CStringTableManager>    manager;
        unsigned int                                curr_lang;
        std::vector<std::string>                    languages;
    };
};