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
	// Ignore empty lines, no operations can be performed on them.
	if (current_line.empty()) { continue; }

        // Trim excess whitespace before and after actual text.
        int first = current_line.find_first_not_of(whitespace);
        int second = current_line.find_last_not_of(whitespace);

	// Ignore lines composed of only whitespace characters.
	if (first == std::string::npos || second == std::string::npos) { continue; }

        std::string trimmed_current_line(current_line.substr(first, (second-first)+1));
      
        if (this->is_ignorable(trimmed_current_line))
        {
          //std::cout << "Read an ignorable line, skipping...\n";
          continue;
        }
        else if (this->is_tag(trimmed_current_line, tag_name))
        {
          //std::cout << "Read tag \"" << tag_name << "\", adding to map...\n";
          in_tag = true;
        }
        else if (this->is_key_value(trimmed_current_line, key, value))
        {
          //std::cout << "Read a key-value pair \"(" << key << "," << value << ")\", adding to map...\n";
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

  // const Ini_Section Ini_Parser::operator[](const std::string &tag) const
  // {
  //   const auto kvm = value_map.find(tag);
  //   if (kvm != value_map.end())
  //   {
  //     return (Ini_Section(tag, kvm->second));
  //   }
  //   else
  //   {
  //     throw (Tag_Not_Found_Exception(tag));
  //   }
  // }

  std::string Ini_Parser::get(const std::string &tag, const std::string &key) const
  {
    std::string ret = "";
    
    const auto &kvm = value_map.find(tag);
    if (kvm != value_map.end())
    {
      const auto &value = kvm->second.find(key);
      if (value != kvm->second.end())
      {
	ret = value->second;
      }
      else
      {
	throw (Key_Not_Found_Exception(key));
      }
    }
    else
    {
      throw (Tag_Not_Found_Exception(tag));
    }

    return (ret);
  }

  template <>
  bool Ini_Parser::get_as<bool>(const std::string &tag, const std::string &key) const
  {
    std::string value = this->get(tag, key);

    if (value == "true")
    {
      return (true);
    }
    if (value == "false")
    {
      return (false);
    }
    else
    {
      throw (Conversion_Exception(value, "bool"));
    }
  }

  template <>
  std::string Ini_Parser::get_as<std::string>(const std::string &tag, const std::string &key) const
  {
    return (this->get(tag, key));
  }





















  template <>
  int Ini_Parser::get_as<int>(const std::string &tag, const std::string &key) const
  {
    std::string value = this->get(tag, key);

    try
    {
      int int_value = std::stoi(value);
      return (int_value);
    }
    catch (const std::invalid_argument &e)
    {
      throw (Conversion_Exception(value, "int"));
    }
    catch (const std::out_of_range &e)
    {
      throw (Conversion_Exception(value, "int"));
    }
  }

  template <>
  long Ini_Parser::get_as<long>(const std::string &tag, const std::string &key) const
  {
    std::string value = this->get(tag, key);

    try
    {
      int long_value = std::stol(value);
      return (long_value);
    }
    catch (const std::invalid_argument &e)
    {
      throw (Conversion_Exception(value, "long"));
    }
    catch (const std::out_of_range &e)
    {
      throw (Conversion_Exception(value, "long"));
    }
  }

  template <>
  long long Ini_Parser::get_as<long long>(const std::string &tag, const std::string &key) const
  {
    std::string value = this->get(tag, key);

    try
    {
      long long long_long_value = std::stoll(value);
      return (long_long_value);
    }
    catch (const std::invalid_argument &e)
    {
      throw (Conversion_Exception(value, "long long"));
    }
    catch (const std::out_of_range &e)
    {
      throw (Conversion_Exception(value, "long long"));
    }
  }

  template <>
  float Ini_Parser::get_as<float>(const std::string &tag, const std::string &key) const
  {
    std::string value = this->get(tag, key);

    try
    {
      float float_value = std::stof(value);
      return (float_value);
    }
    catch (const std::invalid_argument &e)
    {
      throw (Conversion_Exception(value, "float"));
    }
    catch (const std::out_of_range &e)
    {
      throw (Conversion_Exception(value, "float"));
    }
  }

  template <>
  double Ini_Parser::get_as<double>(const std::string &tag, const std::string &key) const
  {
    std::string value = this->get(tag, key);

    try
    {
      double double_value = std::stod(value);
      return (double_value);
    }
    catch (const std::invalid_argument &e)
    {
      throw (Conversion_Exception(value, "double"));
    }
    catch (const std::out_of_range &e)
    {
      throw (Conversion_Exception(value, "double"));
    }
  }

  template <>
  Datestamp Ini_Parser::get_as<Datestamp>(const std::string &tag, const std::string &key) const
  {
    std::string value = this->get(tag, key);

    std::tm date;
    if (strptime(value.c_str(), "%x", &date) != 0)
    {
      return (Datestamp(date));
    }
    else
    {
      throw (Conversion_Exception(value, "date"));
    }
  }

  template <>
  Timestamp Ini_Parser::get_as<Timestamp>(const std::string &tag, const std::string &key) const
  {
    std::string value = this->get(tag, key);

    std::tm time;
    if (strptime(value.c_str(), "%T", &time) != 0)
    {
      return (Timestamp(time));
    }
    else
    {
      throw (Conversion_Exception(value, "time"));
    }
  }

  bool Ini_Parser::is_ignorable(const std::string &line) const
  {
    // We can ignore the line if it begins with a comment mark or it is
    // just a new line
    if (!line.empty())
    {
      return ( line.front() == '#' || line.front() == '\n' || line.length() == 0);
    }
    else
    {
      return (false);
    }
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

    return (true);
  }
}



