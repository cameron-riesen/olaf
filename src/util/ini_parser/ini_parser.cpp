#include "ini_parser.h"
#include "file_not_found_exception.h"
#include "file_not_open_exception.h"
#include "ini_format_exception.h"
#include "key_not_found_exception.h"
#include "tag_not_found_exception.h"

#include <iostream>

namespace Ini_Parser
{
  Ini_Parser::Ini_Parser() :
    fname()
  {
  
  }

  Ini_Parser::Ini_Parser(const std::string &file_name)
  {
    this->open_file(file_name);
  }

  void Ini_Parser::open_file(const std::string &file_name)
  {
    this->file.open(file_name);

    if (file.good())
    {
      this->fname = file_name;
      value_map.clear();
    }
    else
    {
      throw (File_Not_Found_Exception(this->fname));
    }
  }

  bool Ini_Parser::is_file_open() const
  {
    return (this->file.is_open());
  }

  void Ini_Parser::parse_file()
  {
    if (this->is_file_open())
    {
      std::string current_line;
      std::string key;
      std::string value;
      std::string tag_name;
      std::string whitespace(" \t\f\v\r");

      // Bool indicating if at least one tag has been
      // defined. Key/value pairs that are not inside a tag are
      // ignored.
      bool in_tag = false;
    
      while (std::getline(file, current_line))
      {
        // Trim excess whitespace before and after actual text
        int first = current_line.find_first_not_of(whitespace);
        int second = current_line.find_last_not_of(whitespace);

        std::string trimmed_current_line(current_line.substr(first, (second-first)+1));
      
        if (this->is_ignorable(trimmed_current_line))
        {
          std::cout << "Read an ignorable line, skipping...\n";
          continue;
        }
        else if (this->is_tag(trimmed_current_line, tag_name))
        {
          std::cout << "Read tag \"" << tag_name << "\", adding to map...\n";
          in_tag = true;
        }
        else if (this->is_key_value(trimmed_current_line, key, value))
        {
          std::cout << "Read a key-value pair \"(" << key << "," << value << ")\", adding to map...\n";
          if (in_tag)
          {
            // Parse key/value and add to map
            // Add key/value to map
	    value_map[tag_name][key] = value;
          }
        }
        else
        {
          throw (Ini_Format_Exception(this->fname, current_line, 26));
        }
      }
    }
    else
    {
      throw (File_Not_Open_Exception());
    }
  }

  const Ini_Section Ini_Parser::operator[](const std::string &tag) const
  {
    const auto kvm = value_map.find(tag);
    if (kvm != value_map.end())
    {
      return (Ini_Section(tag, kvm->second));
    }
    else
    {
      throw (Tag_Not_Found_Exception(tag));
    }
  }

  bool Ini_Parser::is_ignorable(const std::string &line) const
  {
    // We can ignore the line if it begins with a comment mark or it is
    // just a new line
    return ( line.front() == '#' || line.front() == '\n' || line.length() == 0);
  }

  bool Ini_Parser::is_tag(const std::string &line, std::string &name) const
  {
    if (line.front() != '[' || line.back() != ']')
    {
      return (false);
    }

    // This is supposed to be a tag, make sure the name is valid
    std::string tag_name = line.substr(1, line.size()-2);

    int first = tag_name.find_first_not_of(" \t");
    int second = tag_name.find_last_not_of(" \t");
    
    std::string trimmed_tag_name = tag_name.substr(first, (second-first)+1);

    name = trimmed_tag_name;

    return (true);
  }

  bool Ini_Parser::is_key_value(const std::string &line, std::string &key, std::string &value) const
  {
    if (line.size() == 0)
    {
      return (false);
    }
    
    int pos = line.find_first_of('=');
    if (pos == std::string::npos)
    {
      return (false);
    }

    // Found an equal sign, make sure the key values are not blank or
    // spaces
    std::string k(line.substr(0, pos));
    std::string v(line.substr(pos+1, line.length()-pos));

    key = k;
    value = v;
  }
}



