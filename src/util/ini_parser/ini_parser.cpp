#include "ini_parser.h"

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
      std::string exception_message = "could not find file " + this->fname;
      throw (Ini_Parser_Exception(exception_message));
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

      int line_num = 0;
    
      while (std::getline(file, current_line))
      {
        line_num++;
        
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
          continue;
        }
        else if (this->is_tag(trimmed_current_line, tag_name))
        {
          in_tag = true;
        }
        else if (this->is_key_value(trimmed_current_line, key, value))
        {
          if (in_tag)
          {
            // Parse key/value and add to map
            // Add key/value to map
            value_map[tag_name][key] = value;
          }
        }
        else
        {
          std::string exception_message(std::to_string(line_num));
          exception_message += ": ";
          exception_message += current_line;
          throw (Ini_Parser_Exception(exception_message));
        }
      }
    }
    else
    {
      throw (Ini_Parser_Exception("no file open to parse"));
    }
  }

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
        std::string exception_message = "could not find key in key-value pair (";
        exception_message += tag;
        exception_message += ",";
        exception_message += key;
        exception_message += ")";
        throw (Ini_Parser_Exception(exception_message));
      }
    }
    else
    {
      std::string exception_message = "could not find tag '";
      exception_message += tag;
      exception_message += "'";
      throw (Ini_Parser_Exception(exception_message));
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
      std::string exception_message = "cannot convert from ";
      exception_message += value;
      exception_message += " to bool";
      throw (Ini_Parser_Exception(exception_message));
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
      return (std::stoi(value));
    }
    catch (const std::invalid_argument &e)
    {
      std::string exception_message = "cannot convert from ";
      exception_message += value;
      exception_message += " to int";
      throw (Ini_Parser_Exception(exception_message));
    }
    catch (const std::out_of_range &e)
    {
      std::string exception_message = "cannot convert from ";
      exception_message += value;
      exception_message += " to int";
      throw (Ini_Parser_Exception(exception_message));
    }
  }

  template <>
  long Ini_Parser::get_as<long>(const std::string &tag, const std::string &key) const
  {
    std::string value = this->get(tag, key);

    try
    {
      return (std::stol(value));
    }
    catch (const std::invalid_argument &e)
    {
      std::string exception_message = "cannot convert from ";
      exception_message += value;
      exception_message += " to long";
      throw (Ini_Parser_Exception(exception_message));
    }
    catch (const std::out_of_range &e)
    {
      std::string exception_message = "cannot convert from ";
      exception_message += value;
      exception_message += " to long";
      throw (Ini_Parser_Exception(exception_message));
    }
  }

  template <>
  long long Ini_Parser::get_as<long long>(const std::string &tag, const std::string &key) const
  {
    std::string value = this->get(tag, key);

    try
    {
      return (std::stoll(value));
    }
    catch (const std::invalid_argument &e)
    {
      std::string exception_message = "cannot convert from ";
      exception_message += value;
      exception_message += " to long long";
      throw (Ini_Parser_Exception(exception_message));
    }
    catch (const std::out_of_range &e)
    {
      std::string exception_message = "cannot convert from ";
      exception_message += value;
      exception_message += " to long long";
      throw (Ini_Parser_Exception(exception_message));
    }
  }

  template <>
  float Ini_Parser::get_as<float>(const std::string &tag, const std::string &key) const
  {
    std::string value = this->get(tag, key);

    try
    {
      return (std::stof(value));
    }
    catch (const std::invalid_argument &e)
    {
      std::string exception_message = "cannot convert from ";
      exception_message += value;
      exception_message += " to float";
      throw (Ini_Parser_Exception(exception_message));
    }
    catch (const std::out_of_range &e)
    {
      std::string exception_message = "cannot convert from ";
      exception_message += value;
      exception_message += " to float";
      throw (Ini_Parser_Exception(exception_message));
    }
  }

  template <>
  double Ini_Parser::get_as<double>(const std::string &tag, const std::string &key) const
  {
    std::string value = this->get(tag, key);

    try
    {
      return (std::stod(value));
    }
    catch (const std::invalid_argument &e)
    {
      std::string exception_message = "cannot convert from ";
      exception_message += value;
      exception_message += " to double";
      throw (Ini_Parser_Exception(exception_message));
    }
    catch (const std::out_of_range &e)
    {
      std::string exception_message = "cannot convert from ";
      exception_message += value;
      exception_message += " to double";
      throw (Ini_Parser_Exception(exception_message));
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
      std::string exception_message = "cannot convert from ";
      exception_message += value;
      exception_message += " to Date";
      throw (Ini_Parser_Exception(exception_message));
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
      std::string exception_message = "cannot convert from ";
      exception_message += value;
      exception_message += " to Time";
      throw (Ini_Parser_Exception(exception_message));
    }
  }

  bool Ini_Parser::is_ignorable(const std::string &line) const
  {
    // We can ignore the line if it begins with a comment mark or it is
    // just a new line
    if (!line.empty())
    {
      return (line.front() == '#' || line.front() == '\n' || line.length() == 0);
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



