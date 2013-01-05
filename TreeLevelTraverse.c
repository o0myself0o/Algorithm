/*
 * =====================================================================================
 *
 *       Filename:  TreeLevelTraverse.c
 *
 *    Description:  输入一颗二元树，从上往下按层
 *    打印树的每个节点，同一层中按照从左往右的顺序打印
 *
 *        Version:  1.0
 *        Created:  10/24/2012 04:30:00 PM
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  HQM, 
 *   Organization:  
 *
 * =====================================================================================
 */
#include <stdlib.h>
#include <stdio.h>

#define QUEUE_LEN	128

typedef struct _tree
{
	int key;
	struct _tree *left;
	struct _tree *right;
} tree;

void tree_level_traverse(tree *head)
{
	tree *queue[QUEUE_LEN];
	int front, rear;

	if(head == NULL)
		return;

	front = 0;
	rear = 0;
	queue[rear++] = head;
	while(front != rear)
	{
		head = queue[front];
		front = (front + 1) % QUEUE_LEN;
		printf("%d, ", head->key);

		if(head->left != NULL)
		{
			queue[rear] = head->left;
			rear = (rear + 1) % QUEUE_LEN;
		}

		if(head->right != NULL)
		{
			queue[rear] = head->right;
			rear = (rear + 1) % QUEUE_LEN;
		}
	}
}
