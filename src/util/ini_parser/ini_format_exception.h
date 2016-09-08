#ifndef INI_FORMAT_EXCEPTION_H
#define INI_FORMAT_EXCEPTION_H

#include <exception>
#include <string>

namespace Ini_Parser
{
  class Ini_Format_Exception : public std::exception
  {
  public:
    Ini_Format_Exception(const std::string &file_name, const std::string &error_line, int line_num);
    ~Ini_Format_Exception();
  
    virtual const char* what() const throw();

  private:
    std::string fname;
    std::string line;
    int num;
  };
}

#endif // INI_FORMAT_EXCEPTION_H
