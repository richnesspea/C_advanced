#include <stdio.h>

typedef struct {
    char name[50];
    int studentID;
    float GPA;
} SinhVien;


void capNhatGPA(SinhVien sv, float newGPA) {
    sv.GPA = newGPA;  // Thay đổi chỉ xảy ra trên bản sao của struct
}

void capNhatGPA_pointer(SinhVien *sv, float newGPA) {
    sv->GPA = newGPA;  // Thay đổi chỉ xảy ra trên bản sao của struct
}


int main() {
    SinhVien sv = {"Nguyen Van A", 123, 3.5};
    printf("GPA truoc khi cap nhat: %.2f\n", sv.GPA);

    capNhatGPA(sv, 4.0);
    printf("GPA sau khi cap nhat: %.2f\n", sv.GPA);  // Giá trị GPA không thay đổi

    capNhatGPA_pointer(&sv, 4.0);
    printf("GPA sau khi cap nhat su dung pointer: %.2f\n", sv.GPA);  // Giá trị GPA không thay đổi

    return 0;
}

