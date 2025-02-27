#include "4_2_header.h"

// size_t strlen(const char* str);

static void Char_Invalid_Callback(int ErrorCode)
{
    printf("Char invalid!!, with error code is %d \n", ErrorCode);
}

static void Lenght_Invalid_Callback(int ErrorCode)
{
    printf("Lenght invalid!!, with error code is %d \n", ErrorCode);
}


void RegisterCallback(int ErrorCode, void (*printError)(int))
{
    printError(ErrorCode);
}

void Check_Account(char *ptr, uint8_t lenght)
{
    status_enum_t ErrorCode;

    if (lenght > MAX_LENGTH)
    {
        ErrorCode = LENGHT_INVALID;
        //printf("error code of length is: %d \n", ErrorCode);
        RegisterCallback(ErrorCode, Lenght_Invalid_Callback);
        return;
    }
    for (int i = 0; i < lenght; i++)
    {
        if (!(ptr[i] >= 'A' && ptr[i] <= 'Z' ||
            ptr[i] >= 'a' && ptr[i] <= 'z' ||
            ptr[i] >= '0' && ptr[i] <= '9'))
        {
            ErrorCode = CHAR_INVALID;
            //printf("error code of char is: %d \n", ErrorCode);
            RegisterCallback(ErrorCode, Char_Invalid_Callback);
            return;
        }
    }

}