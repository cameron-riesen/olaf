#include "ini_section.h"
#include "key_not_found_exception.h"

namespace Ini_Parser
{
  Ini_Section::Ini_Section(const std::string &section_name, const std::map<std::string, std::string> &key_value_map) :
    name(section_name),
    k_v_map(key_value_map)
  {
  
  }
 
  const std::string Ini_Section::operator[](const std::string &key)
  {
    const auto k = k_v_map.find(key);
    if (k == k_v_map.end())
    {
      return (k->second);
    }
    else
    {
      throw (Key_Not_Found_Exception(key));
    }
  }

  const std::string Ini_Section::get_tag_name() const
  {
    return (this->name);
  }
}
