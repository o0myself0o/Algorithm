/*
 * =====================================================================================
 *
 *       Filename:  CheckLoopList.c
 *
 *    Description:  given a linked list, detect the loop
 *
 *        Version:  1.0
 *        Created:  09/27/2012 02:03:13 PM
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  HEQINGMING 
 *   Organization:  
 *
 * =====================================================================================
 */
#include <stdlib.h>
#include <stdio.h>

typedef struct Node_s Node_t;
struct Node_s {
	void *data;
	Node_t *next;
};

int hasLoop(Node_t *startNode)
{
	Node_t *slowNode = startNode;
	Node_t *fastNode1 = startNode;
	Node_t *fastNode2 = startNode;

	while(slowNode != NULL && 
			(fastNode1 = fastNode2->next) != NULL && 
			(fastNode2 = fastNode1->next) != NULL)	{
		if(slowNode == fastNode1 || slowNode == fastNode2)
			return 1;
		slowNode = slowNode->next;
	}
	return 0;
}

int main(int argc, char **argv)
{
	printf("check loop begins.\n");

	Node_t *node1 = malloc(sizeof(Node_t));
	node1->data = (void *)"a";
	
	Node_t *node2 = malloc(sizeof(Node_t));
	node2->data = (void *)"b";

	Node_t *node3 = malloc(sizeof(Node_t));
	node3->data = (void *)"c";

	Node_t *node4 = malloc(sizeof(Node_t));
	node4->data = (void *)"d";

	node1->next = node2;
	node2->next = node3;
	node3->next = node4;
	node4->next = node2;

	int result = hasLoop(node1);
	printf("check loop ends. has loop? %s\n", result?"true":"false");
	getchar();
}
