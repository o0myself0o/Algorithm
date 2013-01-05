/*
 * =====================================================================================
 *
 *       Filename:  IsPostTraverse.c
 *
 *    Description:  判断整数序列是不是二元查找树的后续遍历结果
 *
 *        Version:  1.0
 *        Created:  10/22/2012 10:42:52 AM
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

int is_post_traverse(int *arr, int len)
{
	int *head, *pos, *p;
	
	if(arr == NULL || len <= 0)
	{
		return 0;
	}

	if(len == 1)
	{
		return 1;
	}

	head = arr + len - 1;
	p = arr;
	while(*p < *head)
	{
		p++;
	}

	pos = p;

	while(p < head)
	{
		if(*p < *head)
		{
			return 0;
		}
		p++;
	}

	if(!is_post_traverse(arr, pos - arr))
	{
		return 0;
	}

	return is_post_traverse(pos, head - pos);
}

int main()
{
	int tree[] = {5, 7, 6, 9, 11, 10, 8};
	int result = is_post_traverse(tree, 7);
	printf("is post traverse?%d\n", result);
}
