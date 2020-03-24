#include "DoublyLinkedNode.h"

DoublyLinkedNode *createDoublyLinkedNode()
{
    DoublyLinkedNode *node = malloc(sizeof(DoublyLinkedNode));
    node->prev = NULL;
    node->next = NULL;
    return node;
}

void dllInsertBetween(DoublyLinkedNode *left, DoublyLinkedNode *right, DoublyLinkedNode *newNode)
{
    if ((left == NULL && right == NULL) ||
	(left != NULL && left->next != right) ||
	(right != NULL && right->prev != left))
    {
	return;
    }

    if (left != NULL)
    {
	left->next = newNode;
	newNode->prev = left;
    }

    if (right != NULL)
    {
	right->prev = newNode;
	newNode->next = right;
    }
}
