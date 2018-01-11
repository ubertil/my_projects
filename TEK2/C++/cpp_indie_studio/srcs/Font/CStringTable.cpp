# include "Irrlicht/irrlicht.h"
# include "Font/CStringTable.hpp"

using namespace irr;

namespace irr
{
    namespace stringtable
    {

// Function prototypes.
        static void loadXML_entry(io::IXMLReaderUTF8* reader, CStringTable* stringtable);
        static core::ustring loadXML_data(const core::ustring& node, io::IXMLReaderUTF8* reader);


// Current string table.
        CStringTable* current_stringtable = 0;

// XML helpers.
        const core::ustring IRR_XML_FORMAT_STRINGTABLE("irr_stringtable");
        const core::ustring IRR_XML_FORMAT_STRINGTABLE_LANGUAGE("language");
        const core::ustring IRR_XML_FORMAT_STRINGTABLE_ENTRY("entry");
        const core::ustring IRR_XML_FORMAT_STRINGTABLE_ENTRY2("s");
        const core::ustring IRR_XML_FORMAT_STRINGTABLE_ID("id");
        const core::ustring IRR_XML_FORMAT_STRINGTABLE_TRANSLATION("translation");


        CStringTable::CStringTable()
                : language("default"), param_prefix("{{%"), param_postfix("}}")
        {
        }

        CStringTable::~CStringTable()
        {
        }

        bool CStringTable::addTranslation(const core::ustring& id, const core::ustring& translation)
        {
            core::map<core::ustring, core::ustring>::Node *n = stringtable.find(id);
            if (n == 0)
            {
                stringtable.set(id, translation);
                return true;
            }

            n->setValue(translation);
            return false;
        }

        CStringTableUString CStringTable::getTranslation(const core::ustring& id) const
        {
            core::map<core::ustring, core::ustring>::Node *n = stringtable.find(id);
            if (n == 0)
                return CStringTableUString(id, param_prefix, param_postfix);
            else return CStringTableUString(n->getValue(), param_prefix, param_postfix);
        }

        CStringTableUString CStringTable::_TT(const core::ustring& id) const
        {
            core::map<core::ustring, core::ustring>::Node *n = stringtable.find(id);
            if (n == 0)
                return CStringTableUString(id, param_prefix, param_postfix);
            else return CStringTableUString(n->getValue(), param_prefix, param_postfix);
        }

////////////////////////////////////

        CStringTableManager::CStringTableManager()
        {
        }

        CStringTableManager::~CStringTableManager()
        {
            core::map<core::ustring, CStringTable*>::ParentLastIterator i = stringtables.getParentLastIterator();
            while (!i.atEnd())
            {
                core::map<core::ustring, CStringTable*>::Node* n = i.getNode();
                if (n == 0 || n->getValue() == 0)
                {
                    i++;
                    continue;
                }

                // Drop the string table.
                n->getValue()->drop();
                i++;
            }
            stringtables.clear();
        }

        u32 CStringTableManager::loadDirectory(const io::path& directory, io::IFileSystem* FileSystem)
        {
            io::path previous_directory = FileSystem->getWorkingDirectory();
            FileSystem->changeWorkingDirectoryTo(directory);

            u32 count = 0;
            io::IFileList* file_list = FileSystem->createFileList();
            for (u32 i = 0; i < file_list->getFileCount(); ++i)
            {
                // Only load .irrst files.
                if (file_list->isDirectory(i)) continue;
                const io::path& filename = file_list->getFileName(i);
                io::path ext;
                core::getFileNameExtension(ext, filename);
                if (ext != ".irrst") continue;

                // Load the string table.
                CStringTable* st = loadStringTable(file_list->getFullFileName(i), FileSystem);
                if (st == 0) continue;

                // Add it to our map.
                addStringTable(st);
                ++count;
            }
            file_list->drop();

            FileSystem->changeWorkingDirectoryTo(previous_directory);
            return count;
        }

        bool CStringTableManager::addStringTable(CStringTable* stringtable)
        {
            if (stringtable == 0) return false;
            core::map<core::ustring, CStringTable*>::Node* n = stringtables.find(stringtable->getLanguage());
            if (n == 0)
            {
                stringtables.set(stringtable->getLanguage(), stringtable);
                return true;
            }

            n->getValue()->drop();
            n->setValue(stringtable);
            return false;
        }

        CStringTable* CStringTableManager::getStringTable(const core::ustring& language)
        {
            core::map<core::ustring, CStringTable*>::Node* n = stringtables.find(language);
            if (n == 0) return 0;
            return n->getValue();
        }

        bool CStringTableManager::setActiveStringTable(const core::ustring& language)
        {
            core::map<core::ustring, CStringTable*>::Node* n = stringtables.find(language);
            if (n == 0) return false;

            st::setActiveStringTable(n->getValue());
            return true;
        }

////////////////////////////////////

        CStringTable* loadStringTable(const io::path& filename, io::IFileSystem* FileSystem)
        {
            CStringTable* ret = 0;
            io::IReadFile* read = FileSystem->createAndOpenFile(filename);
            if (!read) return 0;
            else
            {
                ret = loadStringTable(read, FileSystem);
                read->drop();
            }
            return ret;
        }

        CStringTable* loadStringTable(io::IReadFile* file, io::IFileSystem* FileSystem)
        {
            if (file == 0) return 0;

            io::IXMLReaderUTF8* reader = FileSystem->createXMLReaderUTF8(file);
            if (reader == 0) return 0;

            CStringTable* st = new CStringTable();
            while (reader->read())
            {
                bool ended = false;
                switch (reader->getNodeType())
                {
                    case io::EXN_ELEMENT_END:
                        if (IRR_XML_FORMAT_STRINGTABLE == reader->getNodeName())
                            ended = true;
                        break;

                    case io::EXN_ELEMENT:
                        if (IRR_XML_FORMAT_STRINGTABLE_ENTRY == reader->getNodeName() ||
                            IRR_XML_FORMAT_STRINGTABLE_ENTRY2 == reader->getNodeName())
                            loadXML_entry(reader, st);
                        else if (IRR_XML_FORMAT_STRINGTABLE_LANGUAGE == reader->getNodeName())
                        {
                            const c8* language = reader->getAttributeValue("value");
                            if (language) st->setLanguage(language);
                        }
                        break;
                }

                if (ended)
                    break;
            }
            reader->drop();

            return st;
        }

        void loadXML_entry(io::IXMLReaderUTF8* reader, CStringTable* stringtable)
        {
            core::ustring id;
            core::ustring translation;

            // They may be using a condensed mode.  See if the id was specified as an attribute.
            bool condensed = false;
            if (reader->getAttributeCount() != 0)
            {
                const c8* cid = reader->getAttributeValue("id");
                if (cid != 0)
                    id = core::ustring(cid);
                condensed = true;
            }

            while (reader->read())
            {
                bool ended = false;
                switch (reader->getNodeType())
                {
                    case io::EXN_ELEMENT_END:
                        if (IRR_XML_FORMAT_STRINGTABLE_ENTRY == reader->getNodeName() ||
                            IRR_XML_FORMAT_STRINGTABLE_ENTRY2 == reader->getNodeName())
                            ended = true;
                        break;

                    case io::EXN_ELEMENT:
                        if (IRR_XML_FORMAT_STRINGTABLE_ID == reader->getNodeName())
                            id = loadXML_data(IRR_XML_FORMAT_STRINGTABLE_ID, reader);
                        else if (IRR_XML_FORMAT_STRINGTABLE_TRANSLATION == reader->getNodeName())
                            translation = loadXML_data(IRR_XML_FORMAT_STRINGTABLE_TRANSLATION, reader);
                        break;

                    case io::EXN_CDATA:
                    case io::EXN_TEXT:
                        if (condensed) translation = reader->getNodeData();
                        condensed = false;
                        break;
                }

                if (ended)
                    break;
            }

            // If we don't have a valid id, just return.
            if (id.empty())
                return;

            // Add the translation.
            stringtable->addTranslation(id, translation);
        }

        core::ustring loadXML_data(const core::ustring& node, io::IXMLReaderUTF8* reader)
        {
            core::ustring ret;
            while (reader->read())
            {
                bool ended = false;
                switch (reader->getNodeType())
                {
                    case io::EXN_ELEMENT_END:
                        if (node == reader->getNodeName())
                            ended = true;
                        break;

                    case io::EXN_TEXT:
                    case io::EXN_CDATA:
                        ret = reader->getNodeData();
                        break;
                }

                if (ended)
                    break;
            }
            return ret;
        }

////////////////////////////////////

        void setActiveStringTable(CStringTable* stringtable)
        {
            current_stringtable = stringtable;
        }

        CStringTable* getActiveStringTable()
        {
            return current_stringtable;
        }

        CStringTableUString _TT(const core::ustring& id)
        {
            if (current_stringtable == 0)
                return CStringTableUString(id);

            return current_stringtable->_TT(id);
        }

    } // end namespace stringtable
} // end namespace irr
