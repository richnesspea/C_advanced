#include "2_header.h"

int Array[MAX];

// Initialize the static array and linked list
void InitArray(LinkedList *list)
{
    list->head = NULL;
    list->size = 0;
    for (int i = 0; i < MAX; i++)
    {
        Array[i] = 0; // Initialize array elements to 0
    }
}

// Add an element to the linked list (using available array space)
// Add value to the static array
// The new node points to that value
// Add new node to linked lists
bool AddElement(LinkedList *list, int value)
{
    if (list->size >= MAX)
    {
        printf("Array is full! Cannot add more elements.\n");
        return false;
    }

    // Assign the value to an available position in the static array
    Array[list->size] = value;

    // Create a new node pointing to that array element
    Node *newNode = (Node *)malloc(sizeof(Node));
    if (!newNode)
    {
        printf("Memory allocation failed!\n");
        return false;
    }
    newNode->data = &Array[list->size];
    newNode->next = NULL;

    // Insert node into the linked list
    if (list->head == NULL)
    {
        list->head = newNode;
    }
    else
    {
        Node *temp = list->head;
        while (temp->next != NULL)
        {
            temp = temp->next;
        }
        temp->next = newNode;
    }

    list->size++;
    return true;
}

// Add an element to the linked list (using available array space)
    // Add value to the static array
    // The new node points to that value
    // Add new node to linked lists
bool AddElement(LinkedList *list, int value)
{
    if (list->size >= MAX)
    {
        printf("Array is full! Cannot add more elements.\n");
        return false;
    }

    // Assign the value to an available position in the static array
    Array[list->size] = value;

    // Create a new node pointing to that array element
    Node *newNode = (Node *)malloc(sizeof(Node));
    if (!newNode)
    {
        printf("Memory allocation failed!\n");
        return false;
    }
    newNode->data = &Array[list->size];
    newNode->next = NULL;

    // Insert node into the linked list
    if (list->head == NULL)
    {
        list->head = newNode;
    }
    else
    {
        Node *temp = list->head;
        while (temp->next != NULL)
        {
            temp = temp->next;
        }
        temp->next = newNode;
    }

    list->size++;
    return true;
}

// Delete an element from the linked list
bool DelElement(LinkedList *list, int value) {
    if (list->head == NULL) {
        printf("List is empty!\n");
        return false;
    }

    Node *temp = list->head;
    Node *prev = NULL;

    // If head node itself holds the value
    if (*(temp->data) == value) {
        list->head = temp->next;
        free(temp);
        list->size--;
        return true;
    }

    // Search for the node to be deleted
    while (temp != NULL && *(temp->data) != value) {
        prev = temp;
        temp = temp->next;
    }

    // If value was not found
    if (temp == NULL) {
        printf("Element not found!\n");
        return false;
    }

    // Unlink the node
    prev->next = temp->next;
    free(temp);
    list->size--;
    return true;
}

