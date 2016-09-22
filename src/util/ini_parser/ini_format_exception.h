#ifndef INI_FORMAT_EXCEPTION_H
#define INI_FORMAT_EXCEPTION_H

#include <exception>
#include <string>

namespace Ini_Parser
{
  //! \class Ini_Format_Exception
  //!
  //! \brief Thrown when a format error in the ini file is
  //! encountered.
  class Ini_Format_Exception : public std::exception
  {
  public:
    //! \brief Constructor
    //!
    //! \param file_name the file that the error occured in
    //! \param error_line the line that the error occured in
    //! \param line_num the line number where the error occured
    Ini_Format_Exception(const std::string &file_name, const std::string &error_line, int line_num);

    //! \brief Print error
    virtual const char* what() const throw();

  private:
    std::string fname;
    std::string line;
    int num;
  };
}

#endif // INI_FORMAT_EXCEPTION_H
