#include "2_header.h"

extern int Array[MAX];

int main()
{
    LinkedList list;
    InitArray(&list);

    AddElement(&list, 5);
    AddElement(&list, 2);
    AddElement(&list, 8);
    AddElement(&list, 1);

    printf("Array values before sorting:\n");
    for (int i = 0; i < list.size; i++)
    {
        printf("%d ", Array[i]);
    }
    printf("\n");

    Sort(&list);
    printf("Array values after sorting:\n");
    for (int i = 0; i < list.size; i++)
    {
        printf("%d ", Array[i]);
    }
    printf("\n");

    int searchVal = 2;
    int pos = Search(&list, searchVal);
    if (pos != -1)
        printf("Element %d found at position %d\n", searchVal, pos);
    else
        printf("Element %d not found!\n", searchVal);

    DelElement(&list, 8);

    printf("Array values after deleting 8:\n");
    for (int i = 0; i < list.size; i++)
    {
        printf("%d ", Array[i]);
    }
    printf("\n");

    return 0;
}
