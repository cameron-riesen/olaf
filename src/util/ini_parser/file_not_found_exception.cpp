#include "file_not_found_exception.h"

namespace Ini_Parser
{
  File_Not_Found_Exception::File_Not_Found_Exception(std::string &file_name) :
    fname(file_name)
  {
  
  }

  const char* File_Not_Found_Exception::what() const throw()
  {
    std::string ret = "File " + this->fname + " could not be found.";
    return (ret.c_str());
  }
}


