#ifndef __4_2_HEADER_H__
#define __4_2_HEADER_H__

#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <string.h>

#define MAX_LENGTH 10

typedef enum _statetype
{
    CORRECT,
    CHAR_INVALID,
    LENGHT_INVALID
} status_enum_t;

void RegisterCallback(int ErrorCode, void(*printError)(int));
void Check_Account(char* ptr, uint8_t lenght);

#endif