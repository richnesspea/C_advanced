#include <stdio.h>
#include <string.h>
#include <stdlib.h>

// Định nghĩa cấu trúc sinh viên
typedef struct {
    char name[50];
    int score;
} Student;

// Hàm so sánh sinh viên theo điểm số
int compareByScore(const void *a, const void *b) {
    Student *studentA = (Student *)a;
    Student *studentB = (Student *)b;
    return studentB->score - studentA->score; // Sắp xếp giảm dần
}

// Hàm so sánh sinh viên theo tên
int compareByName(const void *a, const void *b) {
    Student *studentA = (Student *)a;
    Student *studentB = (Student *)b;
    return strcmp(studentA->name, studentB->name);
}

// Hàm sắp xếp sử dụng con trỏ hàm
void sortStudents(Student *students, int size, int (*compare)(const void *, const void *)) {
    qsort(students, size, sizeof(Student), compare);
}

int main() {
    Student students[] = {
        {"Alice", 88},
        {"Bob", 95},
        {"Charlie", 85}
    };
    int size = sizeof(students) / sizeof(students[0]);

    printf("Sorted by score:\n");
    sortStudents(students, size, compareByScore);
    for (int i = 0; i < size; i++) {
        printf("%s: %d\n", students[i].name, students[i].score);
    }

    printf("\nSorted by name:\n");
    sortStudents(students, size, compareByName);
    for (int i = 0; i < size; i++) {
        printf("%s: %d\n", students[i].name, students[i].score);
    }

    return 0;
}
