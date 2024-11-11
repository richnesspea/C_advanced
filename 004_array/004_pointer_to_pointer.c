#include <stdio.h>

//  modifyPointer changes ptr only within the function. Because ptr is a local copy, the original p in the main function
//does not change

//  modifyPointerToPointer takes a pointer to pointer, so when we update *ptr, we modify the original p in main.

void modifyPointer(int *ptr){
    int x = 10;
    ptr = &x;   //change the copy of ptr, not the original
}

void modifyPointerToPointer(int **ptr){
    int x = 20;
    *ptr = &x;  //change the original pointer in the calling function
}

int main(){
    int *p = NULL;
    modifyPointer(p); //will not change p in main
    printf("After modifyPointer function: %p\n", (void*)p);
    modifyPointerToPointer(&p); 
    printf("After modifyPointerToPointer function: %p\n", (void*)p);

    return 0;
}