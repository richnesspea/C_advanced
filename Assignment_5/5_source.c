#include "5_header.h"

// Convert a hex character (0-9, A-F, a-f) to its integer value
int hexCharToInt(char c) {
    if (c >= '0' && c <= '9') return c - '0';
    if (c >= 'A' && c <= 'F') return c - 'A' + 10;
    if (c >= 'a' && c <= 'f') return c - 'a' + 10;
    return -1;  // Invalid hex character
}

// Convert two hex characters to a single byte
int hexToByte(const char *hex, uint8_t *result) {
    int high = hexCharToInt(hex[0]);
    int low = hexCharToInt(hex[1]);
    
    if (high == -1 || low == -1) return -1; // Invalid hex characters

    *result = (uint8_t)((high << 4) | low);
    return 0;
}

// Convert four hex characters to a 16-bit integer
int hexToWord(const char *hex, uint16_t *result) {
    uint8_t high, low;
    if (hexToByte(hex, &high) == -1 || hexToByte(hex + 2, &low) == -1) return -1;
    
    *result = (uint16_t)((high << 8) | low);
    return 0;
}



Record_status parseHexRecord(const char *hexLine, Record *record) {
    uint8_t calculatedChecksum = 0;

    // Check for start code
    if (hexLine[0] != ':') {
        printf("Invalid HEX record: %s\n", hexLine);
        return START_CODE_ERROR;
    }
    record->start_code = hexLine[0]; // Store ':'

    // Parse Byte Count
    if (hexToByte(hexLine + 1, &record->byte_count) == -1) return FORMAT_ERROR;
    calculatedChecksum += record->byte_count;

    // Validate byte count
    if (record->byte_count > 255) {
        printf("Invalid byte count: %d\n", record->byte_count);
        return FORMAT_ERROR;
    }

    // Parse Address
    if (hexToWord(hexLine + 3, &record->address) == -1) return FORMAT_ERROR;
    calculatedChecksum += (record->address & 0xFF) + ((record->address >> 8) & 0xFF);

    // Parse Record Type
    if (hexToByte(hexLine + 7, &record->record_type) == -1) return FORMAT_ERROR;
    calculatedChecksum += record->record_type;

    // Stop processing if EOF record (01)
    if (record->record_type == 1) return EOF_ERROR;

    // Parse Data
    for (int i = 0; i < record->byte_count; i++) {
        if (hexToByte(hexLine + 9 + (i * 2), &record->data[i]) == -1) return FORMAT_ERROR;
        calculatedChecksum += record->data[i];
    }

    // Parse Checksum
    if (hexToByte(hexLine + 9 + (record->byte_count * 2), &record->checksum) == -1) return FORMAT_ERROR;

    // Verify checksum
    calculatedChecksum = (~calculatedChecksum + 1) & 0xFF;
    if (calculatedChecksum != record->checksum) {
        printf("Checksum error in record: %s\n", hexLine);
        return CHECKSUM_ERROR;
    }

    return CORRECT;
}



void printHexRecordDetails(const Record *record) {
    printf("\n-------------------------------\n");
    printf("Start Code   : %c\n", record->start_code);
    printf("Byte Count   : %02X (%d)\n", record->byte_count, record->byte_count);
    printf("Address      : %04X\n", record->address);
    printf("Record Type  : %02X\n", record->record_type);
    
    printf("Data         : ");
    for (int i = 0; i < record->byte_count; i++) {
        printf("%02X ", record->data[i]);
    }
    printf("\n");

    printf("Checksum     : %02X\n", record->checksum);
}

void processHexRecords(HexVector *vec) {
    Record record;
    Record_status status;
    uint16_t absoluteAddress = 0;
    size_t i;

    for (i = 0; i < (vec->size-1); i++) {
        printf("\nRecord %zu: %s", i + 1, vec->records[i].line);
        
        status = parseHexRecord(vec->records[i].line, &record);
        //printHexRecordDetails(&record);
        if (status != CORRECT) {
            printf("Error in record %zu: %s\n", i + 1, vec->records[i].line);
            printHexRecordDetails(&record);
            return;
        }

        if (record.record_type == 4) {
            absoluteAddress = (record.data[0] << 8) | record.data[1];
            printf("Extended Linear Address: %04X\n", absoluteAddress);
        } else if (record.record_type == 0) {
            uint16_t finalAddress = (absoluteAddress << 16) | record.address;
            printf("Absolute Address: %08X\n", finalAddress);
        }
    }
    if(i == (vec->size - 1)){
        status = parseHexRecord(vec->records[i].line, &record);
        //printHexRecordDetails(&record);
        if (status != EOF_ERROR) {
            printf("\nFile error: No End Of File record found.\n");
            printf("Error in record %zu: %s\n", i + 1, vec->records[i].line);
            //printHexRecordDetails(&record);
            return;
        }
    }
}
