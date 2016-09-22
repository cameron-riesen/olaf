#include "key_not_found_exception.h"

namespace Ini_Parser
{
  Key_Not_Found_Exception::Key_Not_Found_Exception(const std::string &key_name) :
    name(key_name)
  {
  
  }

  const char* Key_Not_Found_Exception::what() const throw()
  {
    std::string ret = "Could not find key by the name '" + this->name + "'";
    return (ret.c_str());
  }
}
