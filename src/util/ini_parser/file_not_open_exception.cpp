#include "file_not_open_exception.h"

namespace Ini_Parser
{
  const char* File_Not_Open_Exception::what() const throw()
  {
    return ("No file open for parsing.");
  }
}


