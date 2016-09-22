#ifndef CONVERSION_EXCEPTION_H
#define CONVERSION_EXCEPTION_H

#include <exception>
#include <string>

namespace Ini_Parser
{
  //! \class Conversion_Exception
  //!
  //! \brief Thrown when a value cannot be converted to a certain type.
  class Conversion_Exception : public std::exception
  {
  public:
    //! \brief Constructor
    //!
    //! \param value the original value
    //! \param to_type the type triying to convert to
    Conversion_Exception(const std::string &value, const std::string &to_type);

    //! \brief Print error
    virtual const char *what() const throw();

  private:
    std::string v;
    std::string tt;
  };
}

#endif // CONVERSION_EXCEPTION_H
