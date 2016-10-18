#include "ini_parser_exception.h"

namespace Ini_Parser
{
  Ini_Parser_Exception::Ini_Parser_Exception(const std::string &m) :
    message("Ini Parser Error: ")
  {
    this->message += m;
  }

  const char *Ini_Parser_Exception::what() const throw()
  {
    return (this->message.c_str());
  }
}
