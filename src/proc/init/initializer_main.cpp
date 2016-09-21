#include <log4cplus/logger.h>
#include <log4cplus/loggingmacros.h>
#include <log4cplus/configurator.h>
#include <log4cplus/initializer.h>

#include <cstdlib>

#include "ini_parser.h"

int main(int argc, char **argv)
{
  log4cplus::Initializer init;
  // TODO: Need to figure out how to use environment variables
  log4cplus::PropertyConfigurator config("/home/pi/Documents/olaf/config/log4cplus.properties");
  config.configure();
  
  log4cplus::Logger file_logger = log4cplus::Logger::getInstance(LOG4CPLUS_TEXT("Olaf_File_Logger"));
  log4cplus::Logger console_logger = log4cplus::Logger::getInstance(LOG4CPLUS_TEXT("Olaf_Console_Logger"));

  LOG4CPLUS_INFO(console_logger, "Initializer main started");

  if (argc < 2)
  {
    LOG4CPLUS_FATAL(console_logger, "Initializer expects exactly 1 config file as argument. Initialization failed.");
    std::exit(EXIT_FAILURE);
  }

  if (argc > 2)
  {
    LOG4CPLUS_WARN(console_logger, "Initializer expects exactly 1 config file as argument but multiple given. Using " << argv[1]);
  }

  try
  {
    Ini_Parser::Ini_Parser parser(argv[1]);
    parser.parse_file();

    bool value = parser.get_as<bool>("some_tag", "some_key");

    // TODO: Fill out message
  }
  catch (const Ini_Parser::File_Not_Found_Exception  &e)
  {
    LOG4CPLUS_FATAL(console_logger, "Config file " << argv[1] << " not found. Initializating failed.");
    std::exit(EXIT_FAILURE);
  }
  catch (const Ini_Parser::File_Not_Open_Exception &e)
  {
    LOG4CPLUS_FATAL(console_logger, "Tried to parse file without opening first. Initializating failed.");
    std::exit(EXIT_FAILURE);
  }
  catch (const Ini_Parser::Ini_Format_Exception &e)
  {
    LOG4CPLUS_FATAL(console_logger, "Error in config file " << argv[1] << ": " << e.what());
    std::exit(EXIT_FAILURE);
  }
  catch (const Ini_Parser::Conversion_Exception &e)
  {
    LOG4CPLUS_FATAL(console_logger, "Error in config file " << argv[1] << ": " << e.what());
    std::exit(EXIT_FAILURE);
  }
  catch (const Ini_Parser::Tag_Not_Found_Exception &e)
  {
    LOG4CPLUS_WARN(console_logger, "Error in config file " << argv[1] << ": " << e.what());
    std::exit(EXIT_FAILURE);
  }
  catch (const Ini_Parser::Key_Not_Found_Exception &e)
  {
    LOG4CPLUS_WARN(console_logger, "Error in config file " << argv[1] << ": " << e.what());
    std::exit(EXIT_FAILURE);
  }
}
