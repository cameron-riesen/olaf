#ifndef DATESTAMP_H
#define DATESTAMP_H

#include <ctime>
#include <ostream>

namespace Ini_Parser
{
  //! \class Datestamp
  //!
  //! \brief Used for retrieving month, day of month, day of week, and
  //! year information from an std::tm structure.
  struct Datestamp
  {
  public:
    //! \brief Constructs Datestamp from std::tm structure
    Datestamp(const std::tm &date);
    //! \brief Copy constructor
    Datestamp(const Datestamp &other);
    //! \brief Move constructor
    Datestamp(Datestamp &&other);

    //! \brief Copy assignment operator
    Datestamp &operator=(const Datestamp &other);
    //! \brief Move assignment operator
    Datestamp &operator=(Datestamp &&other);
    //! \brief Eqaulity operator
    bool operator==(const Datestamp &other);
    //! \brief Inequality operator
    bool operator!=(const Datestamp &other);
    //! \brief Greater than operator
    bool operator>(const Datestamp &other);
    //! \brief Less than than operator
    bool operator<(const Datestamp &other);
    //! \brief Greater than or equal to than operator
    bool operator>=(const Datestamp &other);
    //! \brief Less than or equal to than operator
    bool operator<=(const Datestamp &other);

    //! \brief Defaulted destructor
    ~Datestamp() = default;

    //! \brief The month (0 - 11)
    int &month;
    //! \brief The day of the month (1 - 31)
    int &day_of_month;
    //! \brief The day of the week (1 - 6)
    int &day_of_week;
    //! \brief the year (1970+)
    int &year;
    
  private:
    friend std::ostream &operator<<(std::ostream &os, const Datestamp &date);
    std::tm tm;
  };

  //! \brief Print the date in the format "DOW, DOM FULLMONTH FULLYEAR".
  //  (i.e. Thursday, 22 September 2016)
  std::ostream &operator<<(std::ostream &os, const Datestamp &date);
}


#endif // DATESTAMP_H
