#include <stdlib.h>
#include <stdio.h>

struct Node {
    int data;
    struct Node* next;
}*first = NULL;  
//First is the pointer that refers to the first node of the linked list. If the list is empty, first is NULL.
//When nodes are added to the list, first will point to the first node and subsequently nodes will be linked together through the next pointer


void create(int *arr, int n){
    struct Node *t, *last; //t is temporary pointer to allocate memory for a new node
    first = (struct Node*)malloc(sizeof(struct Node));
    first -> data = arr[0];
    first -> next = NULL;
    last = first;

    for(int i = 1; i < n; i++){
        t = (struct Node*)malloc(sizeof(struct Node));
        t -> data = arr[i];
        t -> next = NULL; //the next pointer of the new node is set to NULl, meaning this new node is the last node in the list for now
        last -> next = t; //the next pointer of the current last node is updated to point to the new node (t). This links the new node to the end of the list
        last = t; //making the new node be the last node of the list
    }
}

/*

    first --> [10 | next] --> [20 | next] --> [30 | NULL]
    last  --> [30 | NULL]

    first --> [10 | next] --> [20 | next] --> [30 | next] --> [40 | NULL]
    last  --> [40 | NULL]
*/


//Create function if you dont want to use first pointer
void create2(struct Node** head, int *arr, int n) {
    struct Node *t, *last;
    
    *head = (struct Node*)malloc(sizeof(struct Node)); // head points to the first node
    (*head) -> data = arr[0];  // Assign the first element to the first node
    (*head) -> next = NULL;
    last = *head;

    for (int i = 1; i < n; i++) {
        t = (struct Node*)malloc(sizeof(struct Node)); // create a new node
        t -> data = arr[i]; // set data for the new node
        t -> next = NULL;   // mark it as the last node for now

        last -> next = t;   // link last node's next to the new node
        last = t;           // update last to point to the new node
    }
}

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

    int array1[5] = {3, 5, 6, 7, 9};
    create(array1, 5);
    display(first);

    struct Node *head = NULL;
    create2(&head, array1, 5);
    display(head);

}