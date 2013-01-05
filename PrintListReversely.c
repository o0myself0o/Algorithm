/*
 * =====================================================================================
 *
 *       Filename:  PrintListReversely.c
 *
 *    Description:  反向输出单向列表节点
 *
 *        Version:  1.0
 *        Created:  11/06/2012 10:28:40 AM
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

struct ListNode
{
	int key;
	struct ListNode *next;
};

void PrintListReversely(struct ListNode *list)
{
	if(!list)
		return;

	if(list->next)
	{
		PrintListReversely(list->next);
	}

	printf("%d  ", list->key);
}

void PrintStringReversely(char *pStr)
{
	if(*pStr != '\0')
	{
		if(*(pStr + 1) != '\0')
		{
			PrintStringReversely(pStr + 1);
		}
		printf("%c  ", *pStr);
	}
}

void main()
{
	char *str = "ABCDEFG";
	PrintStringReversely(str);
	printf("\n");
}
