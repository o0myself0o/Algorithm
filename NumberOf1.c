/*
 * =====================================================================================
 *
 *       Filename:  NumberOf1.c
 *
 *    Description:  判断一个整数的二进制表示有几个1
 *
 *        Version:  1.0
 *        Created:  10/25/2012 02:18:33 PM
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

int NumberOf1(int i)
{
	int count = 0;
	unsigned int flag = 1;
	while(flag)
	{
		if(flag & i)
		{
			count++;
		}

		flag <<= 1;
	}

	return count;
}

int main()
{
	int n;
	printf("input a number: n=");
	scanf("%d", &n);

	printf("the number of 1 is: %d\n", NumberOf1(n));
}
