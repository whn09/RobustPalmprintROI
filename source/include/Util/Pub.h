#ifndef __PUB_H__
#define __PUB_H__

#include <string>

namespace PRDT 
{
    #define CHECK_POINTER_NULL_RETURN(pointer, ret) do { \
        if((pointer) == NULL) { \
            EDCC_Log("File: %s\tFunc: %s\tLine: %lu\tPointer is NULL.\n", __FILE__, __FUNCTION__, __LINE__); \
            return (ret); \
        } \
    } while(0)

    #define CHECK_POINTER_NULL_RETURN_VOID(pointer) do { \
        if((pointer) == NULL) { \
            EDCC_Log("File: %s\tFunc: %s\tLine: %lu\tPointer is NULL.\n", __FILE__, __FUNCTION__, __LINE__); \
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

    void PRDT_Log(const char *format, ...);
}

#endif // !__PUB_H__
