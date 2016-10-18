#ifndef INI_PARSER_EXCEPTION_H
#define INI_PARSER_EXCEPTION_H

#include <exception>
#include <string>

namespace Ini_Parser
{
  class Ini_Parser_Exception
  {
  public:
    Ini_Parser_Exception(const std::string &m);
    virtual const char *what() const throw();

  private:
    std::string message;
  };
}

#endif // INI_PARSER_EXCEPTION_H
