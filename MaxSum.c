/

 * =====================================================================================
 *
 *       Filename:  MaxSum.c
 *
 *    Description:   求子数组的最大和
 *
 *        Version:  1.0
 *        Created:  10/19/2012 05:32:52 PM
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

int maxSum(int *a, int n)
{
	int sum = 0;
	int b = 0;
	int i = 0;

	for(i = 0; i < n; i++)
	{
		if(b < 0)
			b = a[i];
		else
			b += a[i];

		if(sum < b)
			sum = b;
	}

	return sum;
}

int main()
{
	int a[10] = {1, -8, 6, 3, -1, 5, 7, -2, 0, 1};
	printf("max sum is %d.\n", maxSum(a, 10));
	return 0;
}
