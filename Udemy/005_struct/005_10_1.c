#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Định nghĩa Person
typedef struct {
    int id;
    char name[50];
} Person;

// Định nghĩa Group với con trỏ tới các thành viên
typedef struct {
    int groupId;
    Person* members[2];  // Mỗi nhóm có 2 người, nhưng tham chiếu tới đối tượng Person
} Group;

int main() {
    // Tạo các Person
    Person person1 = {1, "Alice"};
    Person person2 = {2, "Bob"};
    
    // Tạo Group và tham chiếu đến các Person
    Group group1;
    group1.groupId = 1;
    group1.members[0] = &person1;
    group1.members[1] = &person2;
    
    // In thông tin nhóm
    printf("Group ID: %d\n", group1.groupId);
    for (int i = 0; i < 2; i++) {
        printf("Member %d: %s (ID: %d)\n", i+1, group1.members[i]->name, group1.members[i]->id);
    }

    return 0;
}
