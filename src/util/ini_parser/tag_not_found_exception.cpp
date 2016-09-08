#include "tag_not_found_exception.h"

namespace Ini_Parser
{
  Tag_Not_Found_Exception::Tag_Not_Found_Exception(const std::string &tag_name) :
    name(tag_name)
  {
  
  }

  const char* Tag_Not_Found_Exception::what() const throw()
  {
    return ("Tag not found exception");
  }
}
