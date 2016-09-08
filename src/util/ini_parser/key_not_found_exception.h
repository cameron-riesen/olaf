#ifndef KEY_NOT_FOUND_EXCEPTION_H
#define KEY_NOT_FOUND_EXCEPTION_H

#include <exception>
#include <string>

namespace Ini_Parser
{
  class Key_Not_Found_Exception : public std::exception
  {
  public:
    Key_Not_Found_Exception(const std::string &key_name);
  
    virtual const char* what() const throw();

  private:
    std::string name;
  };
}


#endif // KEY_NOT_FOUND_EXCEPTION_H
