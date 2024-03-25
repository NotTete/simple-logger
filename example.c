// You must define LOGGER_LEVEL before including 'logger.h'

//#define LOGGER_LEVEL LOGGER_LEVEL_FATAL
//#define LOGGER_LEVEL LOGGER_LEVEL_ERROR
//#define LOGGER_LEVEL LOGGER_LEVEL_WARNING
//#define LOGGER_LEVEL LOGGER_LEVEL_INFO
#define LOGGER_LEVEL LOGGER_LEVEL_DEBUG
//#define LOGGER_LEVEL LOGGER_LEVEL_DISABLE

#include "logger.h"

int main() {
    // Single argument logs
    logger_fatal("This is a fatal error");
    logger_error("This is an error");
    logger_warning("This is a warning");
    logger_info("This is information");
    
    // If 'NDEBUG' is defined this won't show up
    //#define NDEBUG
    logger_debug("This is debug information");

    printf("\n");

    // Multiple argument logs
    logger_fatal_va("This is a %s", "fatal error");
    logger_error_va("This is an %s", "error");
    logger_warning_va("This is a %s", "warning");
    logger_info_va("This is %s", "information");
    logger_debug_va("This is %s", "debug information");
}