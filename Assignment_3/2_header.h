#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

#define MAX 100  // Maximum array size


// Linked list node structure
typedef struct Node {
    int *data;  // Pointer to an element in Array[MAX]
    struct Node *next;
} Node;

// Linked list structure
typedef struct {
    Node *head;
    int size;  // Number of elements in the list
} LinkedList;

void InitArray(LinkedList *list);

bool AddElement(LinkedList *list, int value);

