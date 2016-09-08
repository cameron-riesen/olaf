#ifndef TAG_NOT_FOUND_EXCEPTION_H
#define TAG_NOT_FOUND_EXCEPTION_H

#include <exception>
#include <string>

namespace Ini_Parser
{
  class Tag_Not_Found_Exception : public std::exception
  {
  public:
    Tag_Not_Found_Exception(const std::string &tag_name);
  
    virtual const char* what() const throw();

  private:
    std::string name;
  };
}

#endif // TAG_NOT_FOUND_EXCEPTION_H
