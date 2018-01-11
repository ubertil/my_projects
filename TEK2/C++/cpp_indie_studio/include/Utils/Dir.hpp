//
// Created by uberti_l on 5/22/17.
//

#pragma once
#ifdef _WIN32
# include <windows.h>
# include <tchar.h>
# include <stdlib.h>
# define BUFFSIZE 4096
#endif
# include <iostream>
# include <string>
# include <vector>
# include <dirent.h>
# include <stdlib.h>
# include "Error.hpp"
# include <algorithm>

namespace Sprint
{
    namespace Utils
    {
        class Dir
        {
        public:
            Dir(const std::string &dirname) :
                    dirname(dirname) {};

            Dir&    operator=(const Dir &dir) = delete;
            Dir(const Dir &dir) = delete;
            ~Dir() = default;

            std::vector<std::string>        getFiles(const int depth = -1, const char *filter = nullptr)
            {
                std::vector<std::string>    match;
                #ifdef _WIN32
                TCHAR                       buffer[BUFFSIZE] = TEXT("");
                char                        str[BUFFSIZE];
                std::wstring                tmp;

                std::replace(this->dirname.begin(), this->dirname.end(), '/', '\\');
                tmp = std::wstring(this->dirname.begin(), this->dirname.end());
                GetFullPathName(tmp.c_str(), BUFFSIZE, buffer, NULL);
                tmp = buffer;
                wcstombs(str, tmp.c_str(), sizeof(str));
				this->readDir(str, depth);
                #else
                char                        str[PATH_MAX];
                realpath(this->dirname.c_str(), str);
                this->readDir(str, depth);
                #endif
                if (filter == nullptr)
                    return (this->files);
                else
                {
					for (const std::string &file : files)
						if (this->matchPatern(filter, file.c_str()))
							match.emplace_back(file);
                    return (match);
                }
            }

        private:
            void                readDir(const char *dirname, const int depth)
            {
                DIR             *dir;
                struct dirent   *pdir;
                std::string     path;

				if (dirname == NULL || (dir = opendir(dirname)) == NULL)
				{
					std::cerr << dirname << std::endl;
					throw Error::UtilError("Could not open dir");
				}
                while ((pdir = readdir(dir)) != NULL)
                {
                    if (pdir->d_type == DT_DIR && pdir->d_name[0] != '.' && (depth == -1 || depth > 0))
                    {
                        path.clear();
                        path.append(dirname);
                        #ifdef _WIN32
                        path.append("\\");
                        #else
                        path.append("/");
                        #endif
                        path.append(pdir->d_name);
                        this->readDir(path.c_str(), (depth - 1 < 0) ? (depth) : (depth - 1));
                    }
                    else if (pdir->d_type == DT_REG)
                    {
                        path.clear();
                        path.append(dirname);
                        #ifdef _WIN32
                        path.append("\\");
                        #else
                        path.append("/");
                        #endif
                        path.append(pdir->d_name);
                        this->files.emplace_back(path);
                    }
                }
                closedir(dir);
            }

            bool    matchPatern(char const *needle, char const *haystack)
            {
                for (; *needle != '\0'; ++needle)
                {
                    switch (*needle)
                    {
                        case '*':
                        {
                            size_t max = static_cast<std::string>(haystack).size();
                            if (needle[1] == '\0' || max == 0)
                                return (true);
                            for (size_t i = 0; i < max; i++)
                                if (this->matchPatern(needle + 1, haystack + i))
                                    return (true);
                            return (false);
                        }
                        default:
                            if (*haystack != *needle)
                                return (false);
                            ++haystack;
                    }
                }
                return (*haystack == '\0');
            }
            std::string                 dirname;
            std::vector<std::string>    files;
        };
    }
};