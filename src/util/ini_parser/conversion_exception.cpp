#include "conversion_exception.h"

namespace Ini_Parser
{
  Conversion_Exception::Conversion_Exception(const std::string &value, const std::string &to_type) :
    v(value),
    tt(to_type)
  {
  }

  const char *Conversion_Exception::what() const throw()
  {
    std::string ret = "Cannot convert " + this->v + " to type '" + this->tt + "'";
    return (ret.c_str());
  }
}
