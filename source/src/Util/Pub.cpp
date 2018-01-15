#include <Pub.h>
#include <stdarg.h>
#include <stdio.h>
#include <string.h>
using namespace PRDT;

void PRDT::PRDT_Log(const char *format, ...)
{
    char log[1024] = {0};
    va_list args;
    va_start(args, format);
    std::string formatStr = format;
    formatStr = "[PRDT Debug]\t" + formatStr + "\n";
    vsnprintf(log, sizeof(log), formatStr.c_str(), args);
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