#include "util/pub.h"
#include <stdio.h>
#include <stdarg.h>
#include <string.h>

namespace prdt
{

void PRDT_Log_Func(const char *format, ...)
{
    char log[1024] = {0};
    va_list args;
    va_start(args, format);
    vsnprintf(log, sizeof(log), format, args);
    va_end(args);

    #ifdef _WINDOWS
    printf("%s", log);

    #else // DEBUG
    FILE *outFile;
    outFile = fopen("./prdt.log", "a+");
    CHECK_POINTER_NULL_RETURN_VOID(outFile);
    fwrite(log, strlen(log), 1, outFile);
    fclose(outFile);
    #endif
}

} // namespace prdt
