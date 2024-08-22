#include <stdio.h>
#include <stdlib.h>

typedef struct Node{
    int data;       //Data to store in the node
    struct Node* next; 
}Node;

//Fucntion to create a new node

//the function returns a pointer to a Node struct
Node* createNode(int data){
    Node* newNode = (Node*)malloc(sizeof(Node));
    if(newNode == NULL){
        printf("Memory allocation failed");
        exit(1);
    }
    newNode -> data = data;
    newNode -> next = NULL;
    return newNode;
}

void printList(Node* head){
    Node* temp = head;
    while(temp != NULL){
        printf("%d -> ", temp -> data);
        temp = temp -> next;
    }
    printf("NULL \n");
}

int main(){
    Node* head = createNode(1);
    head->next = createNode(2);
    head->next->next = createNode(3);
    //Printing the linked list
    printList(head);

    //Freeing the allocated memory
    Node* temp;
    while(head != NULL){
        temp = head;
        head = head -> next;
        free(temp);
    }
    return 0;
}
