#ifndef DOUBLYLINKEDNODE_H
#define DOUBLYLINKEDNODE_H
#include <stdlib.h>

typedef struct DoublyLinkedNode
{
    struct DoublyLinkedNode *prev;
    struct DoublyLinkedNode *next;
    void *value;
} DoublyLinkedNode;

DoublyLinkedNode *createDoublyLinkedNode();

void dllInsertBetween(DoublyLinkedNode *left, DoublyLinkedNode *right, DoublyLinkedNode *newNode);
#endif
