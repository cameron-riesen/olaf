#ifndef FILE_NOT_OPEN_EXCEPTION_H
#define FILE_NOT_OPEN_EXCEPTION_H

#include <exception>

namespace Ini_Parser
{
  class File_Not_Open_Exception : public std::exception
  {
  public:
    
    virtual const char* what() const throw();

  private:
  };
}


#endif // FILE_NOT_OPEN_EXCEPTION_H
