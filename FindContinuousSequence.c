/*
 * =====================================================================================
 *
 *       Filename:  FindContinuousSequence.c
 *
 *    Description:  输出所有和为n连续整数序列
 *
 *        Version:  1.0
 *        Created:  11/01/2012 05:16:11 PM
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

void PrintContinuousSequence(int small, int big)
{
	int i = small;
	for(; i <= big; i++)
	{
		printf("%d  ", i);
	}
	printf("\n");
}

void FindContinuousSequence(int n)
{
	if(n < 3) return;
	int small = 1;
	int big = 2;
	int middle = (1 + n) / 2;
	int sum = small + big;

	while(small < middle)
	{
		if(sum == n)
		{
			PrintContinuousSequence(small, big);
		}

		while(sum > n)
		{
			sum -= small;
			small++;
			if(sum == n)
			{
				PrintContinuousSequence(small, big);
			}
		}

		big++;
		sum += big;
	}
}

void main()
{
	int n;
	printf("input a integer:");
	scanf("%d", &n);

	FindContinuousSequence(n);
}
