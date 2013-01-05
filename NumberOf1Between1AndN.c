/*
 * =====================================================================================
 *
 *       Filename:  NumberOf1Between1ANDN.c
 *
 *    Description:  输入一个整数n，求从1到n个整数中1出现的次数
 *
 *        Version:  1.0
 *        Created:  10/25/2012 02:31:58 PM
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

int NumberOf1(unsigned int n)
{
	int number = 0;
	while(n)
	{
		if(n % 10 == 1)
			number++;
		n = n / 10;
	}

	return number;
}

int NumberOf1Between1AndN(unsigned int n)
{
	int number = 0;
	int i = 1;
	for(; i <= n; i++)
	{
		number += NumberOf1(i);
	}

	return number;
}

int main()
{
	int n;
	printf("input a number: n=");
	scanf("%d", &n);

	printf("the count of 1 is: %d\n", NumberOf1Between1AndN(n));
}
