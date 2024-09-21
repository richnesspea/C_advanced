#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Định nghĩa Person
typedef struct {
    int id;
    char name[50];
} Person;

// Định nghĩa Group với danh sách Person nhúng trực tiếp
typedef struct {
    int groupId;
    Person members[2];  // Mỗi nhóm có 2 người
} Group;

int main() {
    // Tạo Group và thêm thành viên trực tiếp
    Group group1;
    group1.groupId = 1;
    
    // Thêm thành viên đầu tiên
    group1.members[0].id = 1;
    strcpy(group1.members[0].name, "Alice");
    
    // Thêm thành viên thứ hai
    group1.members[1].id = 2;
    strcpy(group1.members[1].name, "Bob");
    
    // In thông tin nhóm
    printf("Group ID: %d\n", group1.groupId);
    for (int i = 0; i < 2; i++) {
        printf("Member %d: %s (ID: %d)\n", i+1, group1.members[i].name, group1.members[i].id);
    }

    return 0;
}
