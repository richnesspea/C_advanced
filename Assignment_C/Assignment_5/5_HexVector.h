#ifndef __5_HEXVECTOR_H__
#define __5_HEXVECTOR_H__

#include <stdio.h>
#include <stdint.h>
#include <string.h>
#include <stdlib.h>

#define INITIAL_CAPACITY 10

typedef struct {
    char *line;
} HexRecord;

typedef struct {
    HexRecord *records;
    size_t size;
    size_t capacity;
} HexVector;

void initVector(HexVector *vec);
void addRecord(HexVector *vec, const char *line);
void freeVector(HexVector *vec);
void readHexFile(const char *filename, HexVector *vec);
void printRecords(const HexVector *vec);




#endif
