#include "key_not_found_exception.h"

namespace Ini_Parser
{
  Key_Not_Found_Exception::Key_Not_Found_Exception(const std::string &key_name) :
    name(key_name)
  {
  
  }

  const char* Key_Not_Found_Exception::what() const throw()
  {
    return ("Tag not found exception");
  }
}
