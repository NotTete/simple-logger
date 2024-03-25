# Simple logger
This a simple header-only console logger I made in C for my personal projects.



## Usage
In order to use just include `logger.h` in your header files. 

Before including you must define `LOGGER_LEVEL`, in order to select what messages do you want log.
```c
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
// example.c
``` 
Output:
```
[21:56:29][FATAL] example.c:15 This is a fatal error
[21:56:29][ERROR] example.c:16 This is an error
[21:56:29][WARNING] example.c:17 This is a warning
[21:56:29][INFO] example.c:18 This is information
[21:56:29][DEBUG] example.c:22 This is debug information

[21:56:29][FATAL] example.c:27 This is a fatal error
[21:56:29][ERROR] example.c:28 This is an error
[21:56:29][WARNING] example.c:29 This is a warning
[21:56:29][INFO] example.c:30 This is information
[21:56:29][DEBUG] example.c:31 This is debug information
```
## Test
```bash
git clone https://github.com/NotTete/simple-logger.git
cd ./simple-logger
make
```
