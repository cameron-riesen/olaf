#include <log4cplus/logger.h>
#include <log4cplus/loggingmacros.h>
#include <log4cplus/configurator.h>
#include <log4cplus/initializer.h>

int main(int argc, char **argv)
{
  log4cplus::Initializer init;
  log4cplus::BasicConfigurator config;
  config.configure();
  log4cplus::Logger logger = log4cplus::Logger::getInstance(LOG4CPLUS_TEXT("TEST"));

  LOG4CPLUS_INFO(logger, "Initializer main started");

  // Expecting a file path to the configuration file for the project.
  if (argc != 2)
  {
    LOG4CPLUS_FATAL(logger, "Initializer process expects the init .ini file and only the init .ini file. Cannot continue.");
  }
}
