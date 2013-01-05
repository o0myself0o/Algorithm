/*
 * =====================================================================================
 *
 *       Filename:  FindTwoNumbersWithSum.c
 *
 *    Description:  输入一个已经按升序排序过的数组和
 *    一个数字，在数组中查找两个数，使得它们的和正好
 *    是输入的那个数字。
 *
 *        Version:  1.0
 *        Created:  10/23/2012 02:36:57 PM
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

int FindTwoNumbersWithSum(
		int data[],
		unsigned int length,
		int sum,
		int *num1,
		int *num2)
{
	int result = 0;
	if(length < 1)
		return result;

	int begin = 0;
	int end = length - 1;

	while(end > begin)
	{
		int curSum = data[begin] + data[end];

		if(curSum == sum)
		{
			*num1 = data[begin];
			*num2 = data[end];
			result = 1;
			break;
		}
		else if(curSum > sum)
		{
			end--;
		}
		else
		{
			begin++;
		}
	}

	return result;
}

int main()
{
	int x;
	int y;
	int a[6] = {1, 2, 4, 7, 11, 15};
	if(FindTwoNumbersWithSum(a, 6, 15, &x, &y))
	{
		printf("%d, %d\n", x, y);
	}

	return 0;
}
