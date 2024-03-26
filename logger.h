#ifndef __LOGGER_H
#define __LOGGER_H

#include <stdio.h>
#include <stdarg.h>
#include <time.h>

#define LOGGER_LEVEL_DISABLE 1
#define LOGGER_LEVEL_FATAL 2
#define LOGGER_LEVEL_ERROR 3
#define LOGGER_LEVEL_WARNING 4
#define LOGGER_LEVEL_INFO 5
#define LOGGER_LEVEL_DEBUG 6


#if defined(LOGGER_LEVEL) && 1 <= LOGGER_LEVEL && LOGGER_LEVEL <= 6
    #define __LOGGER_LEVEL LOGGER_LEVEL
#else
    #error LOGGER_LEVEL must be define before including 'logger.h'
#endif

#define __LOGGER_ENABLED(level) ((level) <= __LOGGER_LEVEL)
#define __LOGGER_ENABLED_FATAL __LOGGER_ENABLED(LOGGER_LEVEL_FATAL)
#define __LOGGER_ENABLED_ERROR __LOGGER_ENABLED(LOGGER_LEVEL_ERROR)
#define __LOGGER_ENABLED_WARNING __LOGGER_ENABLED(LOGGER_LEVEL_WARNING)
#define __LOGGER_ENABLED_INFO __LOGGER_ENABLED(LOGGER_LEVEL_INFO)
#define __LOGGER_ENABLED_DEBUG __LOGGER_ENABLED(LOGGER_LEVEL_DEBUG) && !NDEBUG

#if __LOGGER_ENABLED_FATAL
    #define logger_fatal(msg) __LOGGER_INNER_FATAL_PRINT(msg)
    #define logger_fatal_va(msg, ...) __LOGGER_INNER_FATAL_PRINT_VA(msg, __VA_ARGS__)
#else
    #define logger_fatal(msg)
    #define logger_fatal_va(msg, ...)
#endif

#if __LOGGER_ENABLED_ERROR
    #define logger_error(msg) __LOGGER_INNER_ERROR_PRINT(msg)
    #define logger_error_va(msg, ...) __LOGGER_INNER_ERROR_PRINT_VA(msg, __VA_ARGS__)
#else
    #define logger_error(msg)
    #define logger_error_va(msg, ...)
#endif

#if __LOGGER_ENABLED_WARNING
    #define logger_warning(msg) __LOGGER_INNER_WARNING_PRINT(msg)
    #define logger_warning_va(msg, ...) __LOGGER_INNER_WARNING_PRINT_VA(msg, __VA_ARGS__)
#else
    #define logger_warning(msg)
    #define logger_warning_va(msg, ...)
#endif

#if __LOGGER_ENABLED_INFO
    #define logger_info(msg) __LOGGER_INNER_INFO_PRINT(msg)
    #define logger_info_va(msg, ...) __LOGGER_INNER_INFO_PRINT_VA(msg, __VA_ARGS__)
#else
    #define logger_info(msg)
    #define logger_info_va(msg, ...)
#endif

#if __LOGGER_ENABLED_DEBUG
    #define logger_debug(msg) __LOGGER_INNER_DEBUG_PRINT(msg)
    #define logger_debug_va(msg, ...) __LOGGER_INNER_DEBUG_PRINT_VA(msg, __VA_ARGS__)
#else
    #define logger_debug(msg)
    #define logger_debug_va(msg, ...)
#endif

// Multiple argument print

#define __LOGGER_INNER_PRINT_VA(destination, type, color, ...) {                 \
    time_t t = time(NULL);                                                       \
    struct tm* time = localtime(&t);                                             \
    fprintf(destination, "\e[1m%s[%02d:%02d:%02d][%s] \e[34m%s:%d \e[0m",        \
    color, time->tm_hour, time->tm_min, time->tm_sec, type, __FILE__, __LINE__); \
    fprintf(destination, __VA_ARGS__);                                           \
    fprintf(destination, "\n");                                                  \
}

// Single argument print

#define __LOGGER_INNER_PRINT(destination, type, color, msg) {                    \
    time_t t = time(NULL);                                                       \
    struct tm* time = localtime(&t);                                             \
    fprintf(destination, "\e[1m%s[%02d:%02d:%02d][%s] \e[34m%s:%d \e[0m",        \
    color, time->tm_hour, time->tm_min, time->tm_sec, type, __FILE__, __LINE__); \
    fprintf(destination, msg);                                                   \
    fprintf(destination, "\n");                                                  \
}

// Single argument macros

#define __LOGGER_INNER_FATAL_PRINT(msg) \
    __LOGGER_INNER_PRINT(stderr, "FATAL", "\e[38:5:88m", msg) \

#define __LOGGER_INNER_ERROR_PRINT(msg) \
    __LOGGER_INNER_PRINT(stderr, "ERROR", "\e[91m", msg)

#define __LOGGER_INNER_WARNING_PRINT(msg) \
    __LOGGER_INNER_PRINT(stdout, "WARNING", "\e[33m", msg)

#define __LOGGER_INNER_INFO_PRINT(msg) \
    __LOGGER_INNER_PRINT(stdout, "INFO", "\e[36m", msg)

#define __LOGGER_INNER_DEBUG_PRINT(msg) \
    __LOGGER_INNER_PRINT(stdout, "DEBUG", "\e[32m", msg)

// Multiple argument macros

#define __LOGGER_INNER_FATAL_PRINT_VA(msg, ...) \
    __LOGGER_INNER_PRINT_VA(stderr, "FATAL", "\e[38:5:88m", msg, __VA_ARGS__)

#define __LOGGER_INNER_ERROR_PRINT_VA(msg, ...) \
    __LOGGER_INNER_PRINT_VA(stderr, "ERROR", "\e[91m", msg, __VA_ARGS__)

#define __LOGGER_INNER_WARNING_PRINT_VA(msg, ...) \
    __LOGGER_INNER_PRINT_VA(stdout, "WARNING", "\e[33m", msg, __VA_ARGS__)

#define __LOGGER_INNER_INFO_PRINT_VA(msg, ...) \
    __LOGGER_INNER_PRINT_VA(stdout, "INFO", "\e[36m", msg, __VA_ARGS__)

#define __LOGGER_INNER_DEBUG_PRINT_VA(msg, ...) \
    __LOGGER_INNER_PRINT_VA(stdout, "DEBUG", "\e[32m", msg, __VA_ARGS__)

#endif