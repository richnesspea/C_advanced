#include "5_header.h"

int main() {
    HexVector hexData;
    initVector(&hexData);

    readHexFile("5_test.hex", &hexData);
    printRecords(&hexData);
    processHexRecords(&hexData);

    freeVector(&hexData);
    return 0;
}
