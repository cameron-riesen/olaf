#include "runtime_logger.h"

int main()
{
  Runtime_Logger runtime_logger;

  runtime_logger.log_debug("this is some debug");
  runtime_logger.log_info("this is some info");
  runtime_logger.log_warning("this is some warning");
  runtime_logger.log_error("this is some error", 5);
  runtime_logger.log_fatal("this is some fatal");
}
