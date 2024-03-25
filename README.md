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
    logger_fatal("This is a fatal error");
    logger_error("This is an error");
    logger_warning("This is a warning");
    logger_info("This is information");
    
    // If 'NDEBUG' is defined this won't show up
    //#define NDEBUG
    logger_debug("This is debug information");
}
// example.c
``` 
Output:
$${\color{red}Welcome \space \color{lightblue}To \space \color{orange}Stackoverflow}$$
```

[17:35:13][FATAL] example.c:13 This is a fatal error
[17:35:13][ERROR] example.c:14 This is an error
[17:35:13][WARNING] example.c:15 This is a warning
[17:35:13][INFO] example.c:16 This is information
[17:35:13][DEBUG] example.c:20 This is debug information
```
### Test
If you want to test it:
```bash
git clone https://github.com/NotTete/simple-logger.git
cd ./simple-logger
make
```