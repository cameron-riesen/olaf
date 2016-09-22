#ifndef TIMESTAMP_H
#define TIMESTAMP_H

#include <ctime>
#include <ostream>

namespace Ini_Parser
{
  //! \class Timestamp
  //!
  //! \brief Used to retrieve hour, minute and second information
  //! from an std::tm structure
  struct Timestamp
  {
  public:
    //! \brief Constructs a Timestamp from std::tm structure
    Timestamp(const std::tm &time);
    //! \brief Copy constructor
    Timestamp(const Timestamp &other);
    //! \brief Move constructor
    Timestamp(Timestamp &&other);

    //! \brief Copy assignment operator    
    Timestamp &operator=(const Timestamp &other);
    //! \brief Move assignment operator    
    Timestamp &operator=(Timestamp &&other);
    //! \brief Eqaulity operator
    bool operator==(const Timestamp &other);
    //! \brief Inequality operator    
    bool operator!=(const Timestamp &other);
    //! \brief Greater than operator    
    bool operator>(const Timestamp &other);
    //! \brief Less than than operator    
    bool operator<(const Timestamp &other);
    //! \brief Greater than or equal to than operator    
    bool operator>=(const Timestamp &other);
    //! \brief Less than or equal to than operator
    bool operator<=(const Timestamp &other);

    //! \brief Defaulted destructor
    ~Timestamp() = default;

    //! \brief The hour of the day (0 - 23)
    int &hour;
    //! \brief The minute of the hour (0 - 59)
    int &minute;
    //! \brief The second of the minute (0 - 59)
    int &second;
    
  private:
    friend std::ostream &operator<<(std::ostream &os, const Timestamp &time);
    std::tm tm;
  };

  //! \brief Print the time in the format "HH:MM:SS" (i.e. 10:03:23)
  std::ostream &operator<<(std::ostream &os, const Timestamp &time);
}

#endif // TIMESTAMP_H

