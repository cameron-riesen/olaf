#ifndef FILE_NOT_FOUND_EXCEPTION_H
#define FILE_NOT_FOUND_EXCEPTION_H

#include <exception>
#include <string>

namespace Ini_Parser
{
  class File_Not_Found_Exception : public std::exception
  {
  public:
    File_Not_Found_Exception(std::string &file_name);

    virtual const char* what() const throw();

  private:
    std::string fname;
  };
}

#endif // FILE_NOT_FOUND_EXCEPTION_H

