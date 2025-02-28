#include <stdio.h>
#include <stdlib.h>

typedef struct Node{
    int data;       //Data to store in the node
    struct Node* next; //Con trỏ, trỏ tới node kế tiếp trong danh sách liên kết
                       //Cỏn trỏ này có kiểu struct Node: có nghĩa là: nó trỏ đến một cấu trúc khác cùng kiểu với Node.
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
    printf("the size of Node including int and next: %ld \n", sizeof(Node)); //size of int = 4, size of  struct Node* = 8
    //Freeing the allocated memory
    Node* temp;
    while(head != NULL){
        temp = head;
        head = head -> next;
        free(temp);
    }
    return 0;
}
