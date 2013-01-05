/*
 * =====================================================================================
 *
 *       Filename:  FindLastKthNode.c
 *
 *    Description:  输入一个单向链表，输出该链表中倒数第K个节点
 *
 *        Version:  1.0
 *        Created:  10/23/2012 09:12:22 AM
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  HQM 
 *   Organization:  
 *
 * =====================================================================================
 */
#include <stdlib.h>
#include <stdio.h>

struct ListNode
{
	char data;
	struct ListNode *next;
};

struct ListNode *FindLastKthNode(struct ListNode *head, int k)
{
	int i = 0;
	struct ListNode *pone, *ptwo;
	pone = ptwo = head;
	for(i = 0; i <= k-1; i++)
	{
		ptwo = ptwo->next;
	}

	while(ptwo != NULL)
	{
		pone = pone->next;
		ptwo = ptwo->next;
	}

	return pone;
}

int main()
{
	char c;
	struct ListNode *head, *p, *q;
	head = (struct ListNode *)malloc(sizeof(struct ListNode));
	head->next = NULL;
	p = head;
	while(c != '0')
	{
		q = (struct ListNode *)malloc(sizeof(struct ListNode));
		q->data = c;
		q->next = NULL;
		p->next = q;
		p = p->next;
		c = getchar();
	}

	printf("%c\n", FindLastKthNode(head, 2)->data);
}
