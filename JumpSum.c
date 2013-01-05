/*
 * =====================================================================================
 *
 *       Filename:  JumpSum.c
 *
 *    Description:  跳台阶问题
 *    一个台阶总共有n级，如果一次可以跳一级或两级
 *    共有多少种跳法
 *    分析：我们把n级台阶时的跳法看成是n的函数，f(n)
 *    当n>2时，第一次跳的时候就有两种不同的选择：
 *    一是第一次只跳一级，此时跳法数目等于后面剩下的n-1
 *    级台阶的跳法，即f(n-1)
 *    另一种选择是第一次跳2级，此时跳法数目等于后面剩下的
 *    n-2级台阶的跳法，即f(n-2)
 *    得到：
 *    f(1) = 1
 *    f(2) = 2
 *    f(n) = f(n-1) + f(n-2)
 *
 *        Version:  1.0
 *        Created:  10/25/2012 01:57:40 PM
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

int jump_sum(int n)
{
	if(n == 1 || n == 2) return n;
	return jump_sum(n - 1) + jump_sum(n - 2);
}

int main()
{
	int n;
	printf("input the number of steps:n=");
	scanf("%d", &n);

	printf("the total count: %d\n", jump_sum(n));
}
