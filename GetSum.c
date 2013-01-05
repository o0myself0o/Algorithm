/*
 * =====================================================================================
 *
 *       Filename:  GetSum.c
 *
 *    Description:  不能使用乘除，for,while,if,else,swich,
 *	  case等关键字以及条件判断语句求1+2+...+n
 *
 *        Version:  1.0
 *        Created:  10/24/2012 03:21:08 PM
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

int sum(int n)
{
	int val = 0;
	int tmp = (n > 0 && (val = n + sum(n - 1)));
	return val;
}

int main()
{
	int n;
	printf("input a number:n=");
	scanf("%d", &n);

	printf("sum is %d\n", sum(n));
}
