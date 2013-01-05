/*
 * =====================================================================================
 *
 *       Filename:  ReverseList.c
 *
 *    Description:  反转链表
 *
 *        Version:  1.0
 *        Created:  10/25/2012 09:49:47 AM
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

typedef struct _ListNode
{
	int value;
	struct _ListNode *next;
} ListNode;

ListNode *ReverseList(ListNode *head)
{
	ListNode *pHead = NULL;
	ListNode *pNode = pHead;
	ListNode *pPrev = NULL;

	while(pNode != NULL)
	{
		ListNode *pNext = pNode->next;
		if(pNext == NULL)
		{
			pHead = pNode;
		}

		pNode->next = pPrev;
		pPrev = pNode;
		pNode = pNext;
	}

	return pHead;
}
