#include "DoublyLinkedList.h"

DoublyLinkedList *dllCreate()
{
    DoublyLinkedList *list = malloc(sizeof(DoublyLinkedList));
    list->size = 0;

    return list;
}

void dllErase(DoublyLinkedList *l)
{
    DoublyLinkedNode *node = l->head;
    while (node != NULL)
    {
	DoublyLinkedNode *next = node->next;
	free(node->value);
	free(node);
	node = next;
    }

    l->size = 0;
}

void dllDestroy(DoublyLinkedList *l)
{
    dllErase(l);
    free(l);
}

DoublyLinkedNode *dllGetNode(DoublyLinkedList *l, size_t position)
{
    if (position > l->size) { return NULL; }

    DoublyLinkedNode *node = l->head;
    for (size_t i; i < position; ++i)
    {
	node = node->next;
	if (node == NULL) break;
    }

    return node;
}

DoublyLinkedNode *dllLastNode(DoublyLinkedList *l)
{
    DoublyLinkedNode *node = l->head;
    while (node->next != NULL) { node = node->next; }

    return node;
}

void dllPrepend(DoublyLinkedList *l, DoublyLinkedNode *newNode)
{
    if (l->head == NULL)
    {
	l->head = newNode;
    }
    else
    {
	l->head->prev = newNode;
	newNode->next = l->head;
	l->head = newNode;
    }

    ++l->size;
}

void dllAppend(DoublyLinkedList *l, DoublyLinkedNode *newNode)
{
    if (l->head == NULL)
    {
	l->head = newNode;
    }
    else
    {
	DoublyLinkedNode *node = l->head;
	while (node->next != NULL) { node = node->next; }

	node->next = newNode;
	newNode->prev = node;
    }

    ++l->size;
}

void dllInsertBefore(DoublyLinkedList *l, DoublyLinkedNode *node, DoublyLinkedNode *newNode)
{
    if (node == NULL || newNode == NULL) return;

    dllInsertBetween(node->prev, node, newNode);
    if (node == l->head) { l->head = newNode; }
    ++l->size;
}

void dllInsertAfter(DoublyLinkedList *l, DoublyLinkedNode *node, DoublyLinkedNode *newNode)
{
    if (node == NULL || newNode == NULL) return;

    dllInsertBetween(node, node->next, newNode);
    ++l->size;
}

void dllRemove(DoublyLinkedList *l, DoublyLinkedNode *node)
{
    if (node == NULL) return;

    if (node->prev != NULL) { node->prev->next = node->next; }
    if (node->next != NULL) { node->next->prev = node->prev; }

    if (node == l->head) l->head = node->next;

    free(node->value);
    free(node);

    --l->size;
}
