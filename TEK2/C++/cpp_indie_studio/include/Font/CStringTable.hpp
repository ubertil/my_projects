#pragma once
# include "Font/irrUString.hpp"
# include "Irrlicht/irrlicht.h"
using namespace irr;

namespace irr
{
    namespace stringtable
    {

//! A string from the string table.
        class CStringTableUString
        {
        public:
            //! Constructor from a ustring.
            CStringTableUString(const core::ustring& s)
                    : wcs_index(0), ref(s), prefix("{{%"), postfix("}}"), pcount(0) {}

            //! Constructor from a ustring providing a prefix and postfix.
            CStringTableUString(const core::ustring& s, const core::ustring& prefix, const core::ustring& postfix)
                    : wcs_index(0), ref(s), prefix(prefix), postfix(postfix), pcount(0) {}

            //! Copy constructor.
            CStringTableUString(CStringTableUString& other)
                    : wcs_index(0)
            {
                ref = other.ref;
                prefix = other.prefix;
                postfix = other.postfix;
                pcount = other.pcount;
            }

            //! Destructor.
            ~CStringTableUString() {}

            //! Replace a string parameter.
            //! Will replace the next available parameter with the string specified by s.
            //! \param s The parameter we want to add.
            //! \return *this.
            CStringTableUString& param(const core::ustring& s)
            {
                // Increment our parameter number.
                ++pcount;
                core::ustring id(prefix);
                id += core::stringc(pcount);
                id += postfix;

                // Replace every instance with our parameter.
                ref.replace(id, s);

                // Return ourself to allow chaining.
                return *this;
            }

            //! Helper for chaining ustring methods.
            //! \return *this.
            core::ustring& str()
            {
                return ref;
            }

            //! Allows us to be represented as a string.
            //! \return *this.
            operator core::ustring&()
            {
                return ref;
            }

            //! Allows us to be represented as a string.
            //! \return *this.
            operator const core::ustring&() const
            {
                return ref;
            }

            //! Helper function to allow us to be represented as an array of wchar_t.
            //! Makes it easier to pass to Irrlicht functions.  Can be chained 8 times.
            const wchar_t* wcs() const
            {
                wcs_index = (wcs_index + 1) & 0x7;
                wcs_a[wcs_index] = ref.toWCHAR_s();
                return wcs_a[wcs_index].c_str();
            }

        private:
            u32 pcount;
            mutable u32 wcs_index;
            mutable core::stringw wcs_a[8];
            core::ustring ref;
            core::ustring prefix;
            core::ustring postfix;
        };

//! A string table.
        class CStringTable : public virtual irr::IReferenceCounted
        {
        public:
            CStringTable();
            ~CStringTable();

            //! Sets the parameter prefix and postfix.
            //! \param prefix The prefix.  It is, by default, {{#
            //! \param postfix The postfix.  It is, by default, }}
            void setParameterFormat(const core::ustring& prefix, const core::ustring& postfix)
            {
                param_prefix = prefix;
                param_postfix = postfix;
            }

            //! Sets the string table's language.
            //! \param language The new language of the string table.
            void setLanguage(const core::ustring& language)
            {
                this->language = language;
            }

            //! Gets the string table's language.
            //! \return The language of the string table.
            const core::ustring& getLanguage() const
            {
                return language;
            }

            //! Adds a new translation to the string table.
            //! \param id The string id to add the translation to.
            //! \param translation The translation to add to the table.
            //! \return False if the translation overwrote an existing translation, true otherwise.
            bool addTranslation(const core::ustring& id, const core::ustring& translation);

            //! Gets a translation from the string table.
            //! If the translation doesn't exist, the id will be returned.
            //! \param id The string id of the translation to get.
            //! \return The translation from the table or id if the translation was not found.
            CStringTableUString getTranslation(const core::ustring& id) const;

            //! Gets a translation from the string table.
            //! If the translation doesn't exist, the id will be returned.
            //! \param id The string id of the translation to get.
            //! \return The translation from the table or id if the translation was not found.
			CStringTableUString _TT(const core::ustring& id) const;

        private:
            core::ustring language;
            core::ustring param_prefix;
            core::ustring param_postfix;
            core::map<core::ustring, core::ustring> stringtable;
        };

//! A class for managing string tables.
        class CStringTableManager
        {
        public:
            CStringTableManager();
            ~CStringTableManager();

            //! Loads all the .irrst files from the given directory.
            //! \param directory The directory to search.
            //! \return The number of .irrst files loaded.
            u32 loadDirectory(const io::path& directory, io::IFileSystem* FileSystem);

            //! Adds a string table to the manager.
            //! \param stringtable The string table to add.
            //! \return False if the string table overwrote an existing string table, true otherwise.
            bool addStringTable(CStringTable* stringtable);

            //! Gets the string table for the specified language.
            //! \param language The language of the string table to get.
            //! \return Pointer to the string table, else 0 if not found.
            CStringTable* getStringTable(const core::ustring& language);

            //! Gets the map with all the string tables.
            //! \return The map with all the string tables.
            core::map<core::ustring, CStringTable*>& getMap()
            {
                return stringtables;
            }

            //! Sets the currently active string table.
            //! \param language The language of the string table to set as the currently active string table.
            //! \return True if it succeeded in setting the string table as active, false if not.
            bool setActiveStringTable(const core::ustring& language);

        private:
            core::map<core::ustring, CStringTable*> stringtables;
        };

//! Loads a string table from a file.
//! \param filename The file to load the string table from.
//! \param FileSystem An Irrlicht filesystem.
//! \return The string table, or 0 if it was not able to be loaded.
        CStringTable* loadStringTable(const io::path& filename, io::IFileSystem* FileSystem);

//! Loads a string table from a file.
//! \param file The file to load the string table from.
//! \param FileSystem An Irrlicht filesystem.
//! \return The string table, or 0 if it was not able to be loaded.
        CStringTable* loadStringTable(io::IReadFile* file, io::IFileSystem* FileSystem);

//! Sets the currently active string table.
//! \param stringtable The string table to set as the currently active string table.
        void setActiveStringTable(CStringTable* stringtable);

//! Gets the currently active string table.
//! \return The currently active string table.
        CStringTable* getActiveStringTable();

//! Translates a string using the currently active string table.
        CStringTableUString _TT(const core::ustring& id);

    } // end namespace stringtable

//! Helpful abbreviation.
    namespace st = stringtable;

}
