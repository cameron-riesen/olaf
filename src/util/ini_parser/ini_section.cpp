#include "ini_section.h"
#include "key_not_found_exception.h"
#include "conversion_exception.h"
#include "datestamp.h"
#include "timestamp.h"

#include <algorithm>
#include <cctype>

namespace Ini_Parser
{
  Ini_Section::Ini_Section(const std::string &section_name, const std::map<std::string, std::string> &key_value_map) :
    name(section_name),
    k_v_map(key_value_map)
  {
  
  }
 
  template <>
  const bool Ini_Section::get_as<bool>(const std::string &key) const
  {
    std::string value = this->get_value(key);

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
  const std::string Ini_Section::get_as<std::string>(const std::string &key) const
  {
    return (this->get_value(key));
  }

  template <>
  const int Ini_Section::get_as<int>(const std::string &key) const
  {
    std::string value = this->get_value(key);

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
  const long Ini_Section::get_as<long>(const std::string &key) const
  {
    std::string value = this->get_value(key);

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
  const long long Ini_Section::get_as<long long>(const std::string &key) const
  {
    std::string value = this->get_value(key);

    try
    {
      int long_long_value = std::stoll(value);
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
  const float Ini_Section::get_as<float>(const std::string &key) const
  {
    std::string value = this->get_value(key);

    try
    {
      int float_value = std::stof(value);
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
  const double Ini_Section::get_as<double>(const std::string &key) const
  {
    std::string value = this->get_value(key);

    try
    {
      int double_value = std::stod(value);
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
  const Datestamp Ini_Section::get_as<Datestamp>(const std::string &key) const
  {
    std::string value = this->get_value(key);

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
  const Timestamp Ini_Section::get_as<Timestamp>(const std::string &key) const
  {
    std::string value = this->get_value(key);

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

  const std::string Ini_Section::get_tag_name() const
  {
    return (this->name);
  }

  std::string Ini_Section::get_value(const std::string &key) const
  {
    const auto k = k_v_map.find(key);
    if (k != k_v_map.end())
    {
      std::string lower_value(k->second);
      std::transform(lower_value.begin(), lower_value.end(), lower_value.begin(), ::tolower);
      return (lower_value);
    }
    else
    {
      throw (Key_Not_Found_Exception(key));
    }
  }
}
