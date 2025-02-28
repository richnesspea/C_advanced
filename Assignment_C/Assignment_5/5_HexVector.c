#include "5_HexVector.h"

void initVector(HexVector *vec) {
    vec->size = 0;
    vec->capacity = INITIAL_CAPACITY;
    vec->records = (HexRecord *)malloc(vec->capacity * sizeof(HexRecord));
    if (!vec->records) {
        printf("Memory allocation failed.\n");
        exit(1);
    }
}

void addRecord(HexVector *vec, const char *line) {
    if (vec->size >= vec->capacity) {
        vec->capacity *= 2;
        vec->records = (HexRecord *)realloc(vec->records, vec->capacity * sizeof(HexRecord));
        if (!vec->records) {
            printf("Memory reallocation failed.\n");
            exit(1);
        }
    }

    vec->records[vec->size].line = strdup(line);
    if (!vec->records[vec->size].line) {
        printf("Memory allocation failed for line.\n");
        exit(1);
    }
    
    vec->size++;
}

void freeVector(HexVector *vec) {
    for (size_t i = 0; i < vec->size; i++) {
        free(vec->records[i].line);
    }
    free(vec->records);
}

void readHexFile(const char *filename, HexVector *vec) {
    FILE *file = fopen(filename, "r");
    if (!file) {
        printf("Error opening file: %s\n", filename);
        return;
    }

    char *buffer = NULL;
    size_t len = 0;
    size_t read;

    while ((read = getline(&buffer, &len, file)) != -1) {
        if (buffer[0] == ':') {
            addRecord(vec, buffer);
        }
    }

    free(buffer);
    fclose(file);
}

void printRecords(const HexVector *vec) {
    printf("Intel HEX File Contents:\n");
    for (size_t i = 0; i < vec->size; i++) {
        printf("%s", vec->records[i].line);
    }
}
