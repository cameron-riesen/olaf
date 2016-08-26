#ifndef RUNTIME_LOGGER_H
#define RUNTIME_LOGGER_H

#include "logger.h"

class Runtime_Logger : public Logger
{
public:
  Runtime_Logger();
  ~Runtime_Logger();

  virtual void log_debug(const std::string &msg);
  virtual void log_info(const std::string &msg);
  virtual void log_warning(const std::string &msg);
  virtual void log_error(const std::string &msg, const int level);
  virtual void log_fatal(const std::string &msg);

private:

};

#endif // RUNTIME_LOGGER_H
