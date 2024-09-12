/*
    1. Object Pattern
    2. Opaque Pattern
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Định nghĩa cấu trúc Student
typedef struct {
    char name[50];
    float grade;
} Student;

// Định nghĩa cấu trúc StudentList
typedef struct {
    Student* students;
    int size;
    int capacity;
} StudentList;

void studentList_init(StudentList* self, int capacity);
void studentList_add(StudentList* self, const char* name, float grade);
void studentList_display(const StudentList* self);
void studentList_deinit(StudentList* self);


// Hàm khởi tạo StudentList
void studentList_init(StudentList* self, int capacity) {
    self->students = (Student*)malloc(capacity * sizeof(Student)); // Cấp phát bộ nhớ cho mảng học sinh
    if (self->students == NULL) {
        printf("Memory allocation failed.\n");
        exit(EXIT_FAILURE); // Kết thúc chương trình nếu cấp phát bộ nhớ không thành công
    }
    self->size = 0; // Khởi tạo số lượng học sinh là 0
    self->capacity = capacity; // Đặt dung lượng tối đa cho danh sách
}

// Hàm thêm học sinh vào StudentList
void studentList_add(StudentList* self, const char* name, float grade) {
    // Kiểm tra nếu danh sách đầy
    if (self->size >= self->capacity) {
        printf("Student list is full.\n");
        return;
    }
    // Thêm học sinh vào danh sách
    strncpy(self->students[self->size].name, name, sizeof(self->students[self->size].name) - 1);
    self->students[self->size].name[sizeof(self->students[self->size].name) - 1] = '\0'; // Đảm bảo chuỗi kết thúc bằng ký tự null
    self->students[self->size].grade = grade;
    self->size++;
}

// Hàm hiển thị danh sách học sinh
void studentList_display(const StudentList* self) {
    for (int i = 0; i < self->size; i++) {
        printf("Name: %s, Grade: %.2f\n", self->students[i].name, self->students[i].grade);
    }
}

// Hàm giải phóng bộ nhớ cho StudentList
void studentList_deinit(StudentList* self) {
    free(self->students); // Giải phóng bộ nhớ đã cấp phát cho danh sách học sinh
    self->students = NULL; // Đặt con trỏ về NULL để tránh việc sử dụng con trỏ không hợp lệ
    self->size = 0; // Đặt kích thước danh sách về 0
    self->capacity = 0; // Đặt dung lượng danh sách về 0
}

int main() {
    StudentList list;
    studentList_init(&list, 5);
    studentList_add(&list, "Alice", 8.5);
    studentList_add(&list, "Bob", 7.0);
    studentList_display(&list);
    studentList_deinit(&list);
    return 0;
}