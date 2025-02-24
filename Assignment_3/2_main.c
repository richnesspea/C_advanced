#include "2_header.h"

// Static array to store elements
extern int Array[MAX];





// Search for an element in the linked list
bool Search(LinkedList *list, int value) {
    Node *temp = list->head;
    while (temp != NULL) {
        if (*(temp->data) == value) {
            return true;
        }
        temp = temp->next;
    }
    return false;
}

// Sort the linked list using bubble sort
void Sort(LinkedList *list) {
    if (list->head == NULL || list->head->next == NULL) return;

    Node *i, *j;
    int temp;
    
    for (i = list->head; i != NULL; i = i->next) {
        for (j = i->next; j != NULL; j = j->next) {
            if (*(i->data) > *(j->data)) {
                // Swap values in the static array
                temp = *(i->data);
                *(i->data) = *(j->data);
                *(j->data) = temp;
            }
        }
    }
}

// Print the linked list elements and their addresses
void PrintList(LinkedList *list) {
    Node *temp = list->head;
    while (temp != NULL) {
        printf("Address: %p, Value: %d\n", (void*)temp->data, *(temp->data));
        temp = temp->next;
    }
    printf("\n");
}

// Main function for testing
int main() {
    LinkedList list;
    InitArray(&list);

    AddElement(&list, 50);
    AddElement(&list, 20);
    AddElement(&list, 30);
    AddElement(&list, 10);
    AddElement(&list, 40);

    printf("Original List:\n");
    PrintList(&list);

    printf("After Sorting:\n");
    Sort(&list);
    PrintList(&list);

    printf("Deleting 30...\n");
    DelElement(&list, 30);
    PrintList(&list);

    printf("Searching for 20: %s\n", Search(&list, 20) ? "Found" : "Not Found");
    printf("Searching for 100: %s\n", Search(&list, 100) ? "Found" : "Not Found");

    return 0;
}
