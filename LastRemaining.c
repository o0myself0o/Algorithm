/*
 * =====================================================================================
 *
 *       Filename:  LastRemaining.c
 *
 *    Description:  n个数围一圈，第m个出局，最后一个数
 *
 *        Version:  1.0
 *        Created:  10/24/2012 02:49:30 PM
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

int last_remaining(int n, unsigned int m)
{
	int i = 0;

	if(n <= 0 || m <= 0)
		return -1;

	int last = 0;

	for(i = 2; i <= n; i++)
	{
		last = (last + m) % i;
	}

	return last;
}

int main()
{
	int n, m;
	int last;
	printf("inupt number of person: n=");
	scanf("%d", &n);

	printf("input number of the quit:m=");
	scanf("%d", &m);

	last = last_remaining(n, m);
	printf("the last person is %d\n", last);
}
