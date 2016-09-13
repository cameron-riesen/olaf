#ifndef CONVERSION_EXCEPTION_H
#define CONVERSION_EXCEPTION_H

#include <exception>
#include <string>

namespace Ini_Parser
{
  class Conversion_Exception : public std::exception
  {
  public:
    Conversion_Exception(const std::string &value, const std::string &to_type);

    virtual const char *what() const throw();

  private:
    std::string v;
    std::string tt;
  };
}

#endif // CONVERSION_EXCEPTION_H
