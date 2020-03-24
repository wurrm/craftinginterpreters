#include <stdio.h>

#include "DoublyLinkedList.h"

void dllCharPrettyPrint(DoublyLinkedList *l)
{
    DoublyLinkedNode *node = l->head;

    printf("%c", *(char*)node->value);
    node = node->next;
    while (node != NULL)
    {
	printf("->%c", *(char*)node->value);
	node = node->next;
    }
    printf("\n");
}

DoublyLinkedNode *createDoublyLinkedNodeChar(char value)
{
    DoublyLinkedNode *node = createDoublyLinkedNode();
    node->value = malloc(sizeof(char));
    *(char*)node->value = value;
    return node;
}

int main()
{
    DoublyLinkedList *list = dllCreate();
    DoublyLinkedNode *node = NULL;

    node = createDoublyLinkedNodeChar('a'); dllAppend(list, node);
    node = createDoublyLinkedNodeChar('b'); dllAppend(list, node);
    node = createDoublyLinkedNodeChar('c'); dllPrepend(list, node);
    node = createDoublyLinkedNodeChar('d'); dllPrepend(list, node);

    dllRemove(list, node);
    node = createDoublyLinkedNodeChar('r'); dllInsertAfter(list, dllGetNode(list, 1), node);

    dllCharPrettyPrint(list);
    printf("size %li\n", list->size);

    dllDestroy(list);
}
