#ifndef TAG_NOT_FOUND_EXCEPTION_H
#define TAG_NOT_FOUND_EXCEPTION_H

#include <exception>
#include <string>

namespace Ini_Parser
{
  //! \class Tag_Not_Found_Exception
  //!
  //! \brief Thrown when a tag is not found in an ini file
  class Tag_Not_Found_Exception : public std::exception
  {
  public:
    //! \brief Constructor
    //!
    //! \param tag_name the tag being searched for
    Tag_Not_Found_Exception(const std::string &tag_name);

    //! \brief Print error
    virtual const char* what() const throw();

  private:
    std::string name;
  };
}

#endif // TAG_NOT_FOUND_EXCEPTION_H
