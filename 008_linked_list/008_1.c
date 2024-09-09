#include <stdlib.h>
#include <stdio.h>

struct Node {
    int data;
    struct Node* next;
};

void display(struct Node *p){
    while(p != NULL){
        printf("%d\n", p->data);
        p = p -> next;
    }
}

int main(){
    struct Node* p;
    p = (struct Node*)malloc(sizeof(struct Node));
    p -> data = 10;
    p -> next = NULL;

    display(p);
}