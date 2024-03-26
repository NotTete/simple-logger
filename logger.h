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
    #define _LOGGER_LEVEL LOGGER_LEVEL
#else
    #error LOGGER_LEVEL must be define before including 'logger.h'
#endif

#define _LOGGER_ENABLED(level) ((level) <= _LOGGER_LEVEL)
#define LOGGER_ENABLED_FATAL _LOGGER_ENABLED(LOGGER_LEVEL_FATAL)
#define LOGGER_ENABLED_ERROR _LOGGER_ENABLED(LOGGER_LEVEL_ERROR)
#define LOGGER_ENABLED_WARNING _LOGGER_ENABLED(LOGGER_LEVEL_WARNING)
#define LOGGER_ENABLED_INFO _LOGGER_ENABLED(LOGGER_LEVEL_INFO)
#define LOGGER_ENABLED_DEBUG _LOGGER_ENABLED(LOGGER_LEVEL_DEBUG) && !NDEBUG

#if LOGGER_ENABLED_FATAL
    #define logger_fatal(msg) _LOGGER_INNER_FATAL_PRINT(msg)
    #define logger_fatal_va(msg, ...) _LOGGER_INNER_FATAL_PRINT_VA(msg, __VA_ARGS__)
#else
    #define logger_fatal(msg)
    #define logger_fatal_va(msg, ...)
#endif

#if LOGGER_ENABLED_ERROR
    #define logger_error(msg) _LOGGER_INNER_ERROR_PRINT(msg)
    #define logger_error_va(msg, ...) _LOGGER_INNER_ERROR_PRINT_VA(msg, __VA_ARGS__)
#else
    #define logger_error(msg)
    #define logger_error_va(msg, ...)
#endif

#if LOGGER_ENABLED_WARNING
    #define logger_warning(msg) _LOGGER_INNER_WARNING_PRINT(msg)
    #define logger_warning_va(msg, ...) _LOGGER_INNER_WARNING_PRINT_VA(msg, __VA_ARGS__)
#else
    #define logger_warning(msg)
    #define logger_warning_va(msg, ...)
#endif

#if LOGGER_ENABLED_INFO
    #define logger_info(msg) _LOGGER_INNER_INFO_PRINT(msg)
    #define logger_info_va(msg, ...) _LOGGER_INNER_INFO_PRINT_VA(msg, __VA_ARGS__)
#else
    #define logger_info(msg)
    #define logger_info_va(msg, ...)
#endif

#if LOGGER_ENABLED_DEBUG
    #define logger_debug(msg) _LOGGER_INNER_DEBUG_PRINT(msg)
    #define logger_debug_va(msg, ...) _LOGGER_INNER_DEBUG_PRINT_VA(msg, __VA_ARGS__)
#else
    #define logger_debug(msg)
    #define logger_debug_va(msg, ...)
#endif

// Multiple argument print

#define _LOGGER_INNER_PRINT_VA(destination, type, color, ...) {                 \
    time_t t = time(NULL);                                                       \
    struct tm* time = localtime(&t);                                             \
    fprintf(destination, "\e[1m%s[%02d:%02d:%02d][%s] \e[34m%s:%d \e[0m",        \
    color, time->tm_hour, time->tm_min, time->tm_sec, type, __FILE__, __LINE__); \
    fprintf(destination, __VA_ARGS__);                                           \
    fprintf(destination, "\n");                                                  \
}

// Single argument print

#define _LOGGER_INNER_PRINT(destination, type, color, msg) {                    \
    time_t t = time(NULL);                                                       \
    struct tm* time = localtime(&t);                                             \
    fprintf(destination, "\e[1m%s[%02d:%02d:%02d][%s] \e[34m%s:%d \e[0m",        \
    color, time->tm_hour, time->tm_min, time->tm_sec, type, __FILE__, __LINE__); \
    fprintf(destination, msg);                                                   \
    fprintf(destination, "\n");                                                  \
}

// Single argument macros

#define _LOGGER_INNER_FATAL_PRINT(msg) \
    _LOGGER_INNER_PRINT(stderr, "FATAL", "\e[38:5:88m", msg) \

#define _LOGGER_INNER_ERROR_PRINT(msg) \
    _LOGGER_INNER_PRINT(stderr, "ERROR", "\e[91m", msg)

#define _LOGGER_INNER_WARNING_PRINT(msg) \
    _LOGGER_INNER_PRINT(stdout, "WARNING", "\e[33m", msg)

#define _LOGGER_INNER_INFO_PRINT(msg) \
    _LOGGER_INNER_PRINT(stdout, "INFO", "\e[36m", msg)

#define _LOGGER_INNER_DEBUG_PRINT(msg) \
    _LOGGER_INNER_PRINT(stdout, "DEBUG", "\e[32m", msg)

// Multiple argument macros

#define _LOGGER_INNER_FATAL_PRINT_VA(msg, ...) \
    _LOGGER_INNER_PRINT_VA(stderr, "FATAL", "\e[38:5:88m", msg, __VA_ARGS__)

#define _LOGGER_INNER_ERROR_PRINT_VA(msg, ...) \
    _LOGGER_INNER_PRINT_VA(stderr, "ERROR", "\e[91m", msg, __VA_ARGS__)

#define _LOGGER_INNER_WARNING_PRINT_VA(msg, ...) \
    _LOGGER_INNER_PRINT_VA(stdout, "WARNING", "\e[33m", msg, __VA_ARGS__)

#define _LOGGER_INNER_INFO_PRINT_VA(msg, ...) \
    _LOGGER_INNER_PRINT_VA(stdout, "INFO", "\e[36m", msg, __VA_ARGS__)

#define _LOGGER_INNER_DEBUG_PRINT_VA(msg, ...) \
    _LOGGER_INNER_PRINT_VA(stdout, "DEBUG", "\e[32m", msg, __VA_ARGS__)

#endif