#ifndef INI_PARSER_H
#define INI_PARSER_H

//#include "ini_section.h"
#include "datestamp.h"
#include "timestamp.h"
#include "conversion_exception.h"
#include "file_not_found_exception.h"
#include "file_not_open_exception.h"
#include "ini_format_exception.h"
#include "key_not_found_exception.h"
#include "tag_not_found_exception.h"

#include <map>
#include <fstream>

namespace Ini_Parser
{
  //! \class Ini_Parser
  //!
  //! \brief Parse standard .ini formatted files
  class Ini_Parser
  {
  public:
    //! \brief Constructs Ini_Parser with no file.
    Ini_Parser();

    //! \brief Constructs Ini_Parser and attempts to open file "file_name".
    //!
    //! \param[in] file_name The name of the file to open.
    //!
    //! \throws File_Not_Found_Exception
    Ini_Parser(const std::string &file_name);

    //! \brief Defaulted copy constructor
    Ini_Parser(const Ini_Parser &other) = delete;

    //! \brief Defaulted move constructor
    Ini_Parser(Ini_Parser &&other) = delete;

    //! \brief Defaulted copy assignment operator  constructor
    Ini_Parser &operator=(const Ini_Parser &other) = delete;

    //! \brief Defaulted move assignment operator  constructor
    Ini_Parser &operator=(Ini_Parser &&other) = delete;

    //! \brief Destructor
    ~Ini_Parser() = default;

    //! \brief Attempt to open file "file_name".
    //!
    //! \param[in] file_name The name of the file to open.
    //!
    //! \throws File_Not_Found_Exception
    void open_file(const std::string &file_name);

    //! \brief Attempt to parse the the the file if it is open.
    //!
    //! \throws File_Not_Open_Exception
    //! \throws Ini_Format_Exception
    void parse_file();

    //! \brief Return a file is currently open for parsing.
    //!
    //! \return Flag indicating if a file is open.
    bool is_file_open() const;

    //! \brief Overloaded [] operator that returns a section from the .ini file.
    //!
    //! \param[in] tag The tag to search for.
    //!
    //! \return Ini_Section with the section keys and values.
    //!
    //! \throws Tag_Not_Found_Exception
    //const Ini_Section operator[](const std::string &tag) const;

    std::string get(const std::string &tag, const std::string &key) const;

    template <typename T>
    T get_as(const std::string &tag, const std::string &key) const;

  private:
    std::string fname;
    std::ifstream file;
    // Maps a tag to a map of key-value pairs
    std::map<std::string, std::map<std::string, std::string>> value_map;

    bool is_ignorable(const std::string &line) const;
    bool is_tag(const std::string &line, std::string &name) const;
    bool is_key_value(const std::string &line, std::string &key, std::string &value) const;
  };
}

#endif // INI_PARSER_H
