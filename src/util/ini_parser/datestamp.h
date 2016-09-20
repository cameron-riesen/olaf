#ifndef DATESTAMP_H
#define DATESTAMP_H

#include <ctime>
#include <ostream>

namespace Ini_Parser
{
  struct Datestamp
  {
  public:
    Datestamp(const std::tm &date);
    Datestamp(const Datestamp &other);
    Datestamp(Datestamp &&other);
    
    Datestamp &operator=(const Datestamp &other);
    Datestamp &operator=(Datestamp &&other);
    bool operator==(const Datestamp &other);
    bool operator!=(const Datestamp &other);
    bool operator>(const Datestamp &other);
    bool operator<(const Datestamp &other);
    bool operator>=(const Datestamp &other);
    bool operator<=(const Datestamp &other);
    
    ~Datestamp() = default;

    int &month;
    int &day_of_month;
    int &day_of_week;
    int &year;
    
  private:
    friend std::ostream &operator<<(std::ostream &os, const Datestamp &date);
    std::tm tm;
  };

  std::ostream &operator<<(std::ostream &os, const Datestamp &date);
}


#endif // DATESTAMP_H
