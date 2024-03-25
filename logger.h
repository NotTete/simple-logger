#ifndef __SIMPLE_LOGGER_H
#define __SIMPLE_LOGGER_H

#include <stdio.h>
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
    #define logger_fatal(msg) __logger_inner_fatal(__LINE__, __FILE__, msg)
#else
    #define logger_fatal(msg)
#endif

#if __LOGGER_ENABLED_ERROR
    #define logger_error(msg) __logger_inner_error(__LINE__, __FILE__, msg)
#else
    #define logger_error(msg)
#endif

#if __LOGGER_ENABLED_WARNING
    #define logger_warning(msg) __logger_inner_warning(__LINE__, __FILE__, msg)
#else
    #define logger_warning(msg)
#endif

#if __LOGGER_ENABLED_INFO
    #define logger_info(msg) __logger_inner_info(__LINE__, __FILE__, msg)
#else
    #define logger_info(msg)
#endif

#if __LOGGER_ENABLED_DEBUG
    #define logger_debug(msg) __logger_inner_debug(__LINE__, __FILE__, msg)
#else
    #define logger_debug(msg)
#endif 

extern inline void __logger_inner_fatal(const int line, const char* file, const char* msg) {
    time_t t = time(NULL);
    struct tm* ts = localtime(&t);
    printf(
        "\e[1m\e[38:5:88m[%02d:%02d:%02d][FATAL]\e[34m %s:%d\e[0m %s\n", 
        ts->tm_hour,
        ts->tm_min, 
        ts->tm_sec, 
        file,
        line,
        msg
    );
}

extern inline void __logger_inner_error(const int line, const char* file, const char* msg) {
    time_t t = time(NULL);
    struct tm* ts = localtime(&t);
    printf(
        "\e[1m\e[91m[%02d:%02d:%02d][ERROR]\e[34m %s:%d\e[0m %s\n", 
        ts->tm_hour,
        ts->tm_min, 
        ts->tm_sec, 
        file,
        line,
        msg
    );
}

extern inline void __logger_inner_warning(const int line, const char* file, const char* msg) {
    time_t t = time(NULL);
    struct tm* ts = localtime(&t);
    printf(
        "\e[1m\e[33m[%02d:%02d:%02d][WARNING]\e[34m %s:%d\e[0m %s\n", 
        ts->tm_hour,
        ts->tm_min, 
        ts->tm_sec, 
        file,
        line,
        msg
    );
}

extern inline void __logger_inner_info(const int line, const char* file, const char* msg) {
    time_t t = time(NULL);
    struct tm* ts = localtime(&t);
    printf(
        "\e[1m\e[36m[%02d:%02d:%02d][INFO]\e[34m %s:%d\e[0m %s\n", 
        ts->tm_hour,
        ts->tm_min, 
        ts->tm_sec, 
        file,
        line,
        msg
    );
}

extern inline void __logger_inner_debug(const int line, const char* file, const char* msg) {
    time_t t = time(NULL);
    struct tm* ts = localtime(&t);
    printf(
        "\e[1m\e[32m[%02d:%02d:%02d][DEBUG]\e[34m %s:%d\e[0m %s\n", 
        ts->tm_hour,
        ts->tm_min, 
        ts->tm_sec, 
        file,
        line,
        msg
    );
}

#endif