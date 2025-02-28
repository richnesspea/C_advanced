#include "array_manager.h"
#include <stdio.h>

int main() {
    char command;
    int value, position, size;
    printf("CT Quan li day so cua mang\n");
    while (1) {
        printf("Nhap lenh \n");
        scanf(" %c", &command);
        switch (command) {
            case 'c':
                printf("Nhap kich thuoc cua mang: ");
                scanf("%d", &size);
                create_array(size);
                printf("In ra gia tri cua mang: \n");
                print_array();
                break;
            case 'p':
                printf("In ra gia tri cua mang: \n");
                print_array();
                break;
            case 'i':
                printf("Nhap vi tri can them: ");
                scanf("%d", &position);
                printf("Nhap gia tri can them: ");
                scanf("%d", &value);
                insert_element(value, position);
                break;
            case 'd':
                printf("Nhap vi tri can xoa: ");
                scanf("%d", &position);
                delete_element(position);
                break;
            case 's':
                sort_array(true);
                printf("Da sap xep tang dan.\n");
                break;
            case 'x':
                sort_array(false);
                printf("Da sap xep giam dan.\n");
                break;
            case 't':
                printf("Nhap so can tim: ");
                scanf("%d", &value);
                if (search_element(value)) {
                    printf("Tim thay so %d trong mang.\n", value);
                } else {
                    printf("Khong tim thay so %d.\n", value);
                }
                break;
            case 'e':
                clear_array();
                return 0;
            default:
                printf("Lenh khong hop le\n");
        }
    }
}
