#ifndef __PUB_H__
#define __PUB_H__

#include <stdio.h>
#include <stdarg.h>
#include <string>

#define _IN
#define _OUT
#define _INOUT

namespace PRDT 
{
    #define CHECK_POINTER_NULL_RETURN(pointer, ret) do { \
        if((pointer) == NULL) { \
            PRDT_Log("Pointer is NULL.\n"); \
            return (ret); \
        } \
    } while(0)

    #define CHECK_POINTER_NULL_RETURN_VOID(pointer) do { \
        if((pointer) == NULL) { \
            PRDT_Log("Pointer is NULL.\n"); \
            return ; \
        } \
    } while(0)

    #define CHECK_NE_RETURN_VOID(param1, param2) do { \
        if((param1) != (param2)) { \
            return ; \
        } \
    } while(0)

    #define CHECK_NE_RETURN(param1, param2, ret) do { \
        if((param1) != (param2)) { \
            return (ret); \
        } \
    } while(0)

    #define CHECK_EQ_RETURN_VOID(param1, param2) do { \
        if((param1) == (param2)) { \
            return ; \
        } \
    } while(0)

    #define CHECK_EQ_RETURN(param1, param2, ret) do { \
        if((param1) == (param2)) { \
            return (ret); \
        } \
    } while(0)

    #define CHECK_TRUE_RETURN(param, ret) do { \
        if((param) == true) { \
            return (ret); \
        } \
    } while(0)

    #define CHECK_FALSE_RETURN(param, ret) do { \
        if((param) == false) { \
            return (ret); \
        } \
    } while(0)

    #define CHECK_TRUE_RETURN_VOID(param) do { \
        if((param) == true) { \
            return; \
        } \
    } while(0)

    #define CHECK_FALSE_RETURN_VOID(param) do { \
        if((param) == false) { \
            return; \
        } \
    } while(0)

#define ANSI_COLOR_RED                  "\x1b[31m"
#define ANSI_COLOR_GREEN                "\x1b[32m"
#define ANSI_COLOR_LIGHT_GREEN          "\x1b[1;32m"
#define ANSI_COLOR_YELLOW               "\x1b[33m"
#define ANSI_COLOR_BLUE                 "\x1b[34m"
#define ANSI_COLOR_LIGHT_BLUE           "\x1b[1;34m"
#define ANSI_COLOR_MAGENTA              "\x1b[35m"
#define ANSI_COLOR_CYAN                 "\x1b[36m"
#define ANSI_COLOR_LIGHT_GRAY           "\x1b[0;37m"
#define ANSI_COLOR_DARY_GRAY            "\x1b[1;30m"
#define ANSI_COLOR_RESET                "\x1b[0m"

#define PRDT_Log(format, ...) PRDT_Log_Func("[PRDT_Debug]\t" \
                                            "[%s: %u]\t"     \
                                             format"\n"      \
                                            , __FUNCTION__, __LINE__, ##__VA_ARGS__)
    void PRDT_Log_Func(_IN const char *format, _IN ...);
}

#endif // !__PUB_H__
