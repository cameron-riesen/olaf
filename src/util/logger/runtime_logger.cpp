#include "runtime_logger.h"

#include <dds/DdsDcpsInfrastructureC.h>
#include <dds/DdsDcpsPublicationC.h>
#include <dds/DCPS/Marked_Default_Qos.h>
#include <dds/DCPS/Service_Participant.h>
#include <dds/DCPS/WaitSet.h>
#include <dds/DCPS/StaticIncludes.h>

#include "InfoMessageTypeSupportImpl.h"

#include <iostream>

Runtime_Logger::Runtime_Logger()
{
  // create message writers
}

Runtime_Logger::~Runtime_Logger()
{
}

void Runtime_Logger::log_debug(const std::string &msg)
{
  std::lock_guard<std::mutex> lock(write_mutex);
  std::cout << "DEBUG: " << msg << "\n";
  //Debug_Log_Msg msg;
  //msg.output = console;
  //msg.text = msg;
  //debug_msg_writer->write(msg, 0);
}

void Runtime_Logger::log_info(const std::string &msg)
{
  std::lock_guard<std::mutex> lock(write_mutex);
  std::cout << "INFO: " << msg << "\n";  
  //Info_Log_Msg msg;
  //msg.output = console;
  //msg.text = msg;
  //debug_msg_writer->write(msg, 0);
}

void Runtime_Logger::log_warning(const std::string &msg)
{
  std::lock_guard<std::mutex> lock(write_mutex);
  std::cout << "WARN: " << msg << "\n";
  //Warning_Log_Msg msg;
  //msg.output = console;
  //msg.text = msg;
  //debug_msg_writer->write(msg, 0);
}

void Runtime_Logger::log_error(const std::string &msg, const int level)
{
  std::lock_guard<std::mutex> lock(write_mutex);
  std::cout << "ERROR: " << msg << "\n";
  //Error_Log_Msg msg;
  //msg.output = console;
  //msg.text = msg;
  //debug_msg_writer->write(msg, 0);
}

void Runtime_Logger::log_fatal(const std::string &msg)
{
  std::lock_guard<std::mutex> lock(write_mutex);
  std::cout << "FATAL: " << msg << "\n";
  //Fatal_Log_Msg msg;
  //msg.output = console;
  //msg.text = msg;
  //debug_msg_writer->write(msg, 0);
}
