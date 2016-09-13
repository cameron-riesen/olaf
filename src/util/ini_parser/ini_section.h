#ifndef INI_SECTION_H
#define INI_SECTION_H

#include <string>
#include <map>

namespace Ini_Parser
{
  class Ini_Section
  {
  public:
    Ini_Section(const std::string &section_name, const std::map<std::string, std::string> &key_value_map);

    Ini_Section() = delete;
    Ini_Section(const Ini_Section &other) = default;
    Ini_Section(Ini_Section &&other) = default;
    Ini_Section &operator=(const Ini_Section &other) = default;
    Ini_Section &operator=(Ini_Section &other) = default;

    //const std::string operator[](const std::string &key);
    template <typename T>
    const T get_as(const std::string &key) const;

    const std::string get_tag_name() const;
    
  private:
    std::string name;
    const std::map<std::string, std::string> &k_v_map;
    std::string get_value(const std::string &key) const;
  };
}

#endif // INI_SECTION_H
