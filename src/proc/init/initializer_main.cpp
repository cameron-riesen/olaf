#include <log4cplus/logger.h>
#include <log4cplus/loggingmacros.h>
#include <log4cplus/configurator.h>
#include <log4cplus/initializer.h>

#include <cstdlib>

#include "ini_parser.h"

#include "init_config_msg_DCPS.hpp"

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

    Init_Messages::Config_Message config_msg;

    Ini_Parser::Datestamp mission_start_date = parser.get_as<Ini_Parser::Datestamp>("global", "mission_start_date");
    Ini_Parser::Timestamp mission_start_time = parser.get_as<Ini_Parser::Timestamp>("global", "mission_start_time");
    
    config_msg.global_config().mission_start_time().hour() = mission_start_time.hour;
    config_msg.global_config().mission_start_time().minute() = mission_start_time.minute;
    config_msg.global_config().mission_start_time().second() = mission_start_time.second;

    config_msg.global_config().mission_start_date().year() = mission_start_date.year;
    config_msg.global_config().mission_start_date().month() = mission_start_date.month;
    config_msg.global_config().mission_start_date().day() = mission_start_date.day_of_month;

    config_msg.global_config().daily_window_enabled() = parser.get_as<bool>("global", "enable_daily_window");

    if (config_msg.global_config().daily_window_enabled())
    {
      int num_daily_windows = parser.get_as<int>("global", "num_daily_windows");

      for (int i = 0; i < num_daily_windows; i++)
      {
	// std::string tag("daily_window_");
	// tag += std::to_string(i);
	
        // Ini_Parser::Timestamp start_time = parser.get_as<Ini_Parser::Timestamp>(tag, "start_time");
        // Ini_Parser::Timestamp end_time = parser.get_as<Ini_Parser::Timestamp>(tag, "end_time");
	// bool record_on_interval = parser.get_as<bool>(tag, "record_on_interval");
	// int interval_on = parser.get_as<int>(tag, "interval_on");
	// int interval_off = parser.get_as<int>(tag, "interval_off");
      }
    }

  }
  catch (const Ini_Parser::File_Not_Found_Exception &e)
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
