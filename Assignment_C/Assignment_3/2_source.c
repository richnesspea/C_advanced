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
bool AddElement(LinkedList *list, int value)
{
    if (list->size >= MAX)
    {
        printf("Array is full! Cannot add more elements.\n");
        return false;
    }

    Array[list->size] = value;

    Node *newNode = (Node *)malloc(sizeof(Node));
    if (!newNode)
    {
        printf("Memory allocation failed!\n");
        return false;
    }
    newNode->data = &Array[list->size];
    newNode->next = NULL;

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
bool DelElement(LinkedList *list, int value)
{
    if (list->head == NULL)
    {
        printf("List is empty!\n");
        return false;
    }

    Node *temp = list->head;
    Node *prev = NULL;

    if (*(temp->data) == value)
    {
        list->head = temp->next;
        free(temp);
        list->size--;
        return true;
    }

    while (temp != NULL && *(temp->data) != value)
    {
        prev = temp;
        temp = temp->next;
    }

    if (temp == NULL)
    {
        printf("Element not found!\n");
        return false;
    }

    prev->next = temp->next;
    free(temp);
    list->size--;
    return true;
}

// Sort array and update linked list accordingly
void Sort(LinkedList *list)
{
    if (list->size <= 1)
        return;
    
    for (int i = 0; i < list->size - 1; i++)
    {
        for (int j = 0; j < list->size - i - 1; j++)
        {
            if (Array[j] > Array[j + 1])
            {
                int temp = Array[j];
                Array[j] = Array[j + 1];
                Array[j + 1] = temp;
            }
        }
    }
    
    // Update linked list pointers
    Node *temp = list->head;
    for (int i = 0; i < list->size; i++)
    {
        temp->data = &Array[i];
        temp = temp->next;
    }
}

// Search for an element in the linked list
int Search(LinkedList *list, int value)
{
    Node *temp = list->head;
    int index = 0;
    while (temp != NULL)
    {
        if (*(temp->data) == value)
        {
            return index;
        }
        temp = temp->next;
        index++;
    }
    return -1; // Element not found
}
