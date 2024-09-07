//Hệ thống quản lí cơ sở dữ liệu cơ bản 
/*
Các kiến thức ôn tập gồm:
    * linked list
    * bảng băm
    * struct
    * dynamic memory allocation
*/

#include <stdio.h>
#include <stdint.h>
#include <string.h>

#define TABLE_SIZE 100

typedef struct Record{
    int id;
    char name[100];
    char address[200];
    struct Record* next;
} Record;

Record* hashTable[TABLE_SIZE];// Hash table là mảng chứa các con trỏ đến bản ghi

unsigned int hash(int id){
    return id % TABLE_SIZE;
}

void insert(int id, char *name, char *address){

}

int main(){
    memset(hashTable, 0, sizeof(hashTable));
    insert(1, "Alice", "so 3, ngo 12, Phan Dinh Giot");
    insert(2, "Bob", "67, Quan Toan 1, Quan Toan");

}