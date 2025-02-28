#ifndef __5_HEADER_H__
#define __5_HEADER_H__

#include <stdio.h>
#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
#include "5_HexVector.h"

typedef struct {
    uint8_t start_code;
    uint8_t byte_count;
    uint16_t address;
    uint8_t record_type;
    uint8_t data[512];
    uint8_t checksum;
} Record;

typedef enum {
    CORRECT,
    START_CODE_ERROR,
    FORMAT_ERROR,
    BYTE_COUNT_ERROR,
    EOF_ERROR,
    CHECKSUM_ERROR,
    MISSING_EOF_ERROR
} Record_status;

Record_status parseHexRecord(const char *hexLine, Record *record);
void processHexRecords(HexVector *vec);
void printHexRecordDetails(const Record *record);


#endif
