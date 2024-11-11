//Leet code #23

#include <stdio.h>
#include <stdlib.h>

//Defintion for singly-linked lists
struct ListNode{
    int val;
    struct ListNode *next;
};

//Helper function to create a new node
void createNode(struct ListNode **head, int *arr, int n){
    //Using pointer to pointer (struct ListNode **head) allows to function to modify the original pointer itself, not just 
    //the the data it points to.

    struct ListNode *t, *last;

    *head = (struct ListNode *)malloc(sizeof(struct ListNode));
    (*head)->val = arr[0];
    (*head)->next = NULL;
    last = *head;

    for(int i = 1; i < n; i++) {
        t = (struct ListNode *)malloc(sizeof(struct ListNode));
        t->val = arr[i];
        t->next = NULL;

        last->next = t;
        last = t;
    }
}

void display(struct ListNode *p){
    while(p != NULL){
        printf("%d\n", p->val);
        p = p -> next;
    }
}

struct ListNode* mergeKLists(struct ListNode** lists, int listsSize) {
    
}

int main(){
    struct ListNode *head = NULL;
    int array1[5] = {3, 5, 6, 7, 9};

    createNode(&head, array1, 5);
    display(head);
}