#ifndef DOUBLYLINKEDLIST_H
#define DOUBLYLINKEDLIST_H
#include "DoublyLinkedNode.h"

typedef struct
{
    DoublyLinkedNode *head;
    size_t size;
} DoublyLinkedList;

DoublyLinkedList *dllCreate();

void dllErase(DoublyLinkedList *l);

void dllDestroy(DoublyLinkedList *l);

DoublyLinkedNode *dllGetNode(DoublyLinkedList *l, size_t position);

DoublyLinkedNode *dllLastNode(DoublyLinkedList *l);

void dllPrepend(DoublyLinkedList *l, DoublyLinkedNode *newNode);

void dllAppend(DoublyLinkedList *l, DoublyLinkedNode *newNode);

void dllInsertBetween(DoublyLinkedNode *left, DoublyLinkedNode *right, DoublyLinkedNode *newNode);

void dllInsertBefore(DoublyLinkedList *l, DoublyLinkedNode *node, DoublyLinkedNode *newNode);

void dllInsertAfter(DoublyLinkedList *l, DoublyLinkedNode *node, DoublyLinkedNode *newNode);

void dllRemove(DoublyLinkedList *l, DoublyLinkedNode *node);
#endif
