/*
 * =====================================================================================
 *
 *       Filename:  StrToInt.c
 *
 *    Description:  输入一个表示整数的字符串，
 *    把该字符串转换成整数并输出
 *
 *        Version:  1.0
 *        Created:  10/24/2012 03:07:42 PM
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

int str_to_int(const char *str)
{
	int minus = 0;
	int num = 0;

	if(str == NULL)
		return 0;

	const char *digit = str;
	if(*digit == '+')
		digit++;
	else if(*digit == '-')
	{
		digit++;
		minus = 1;
	}

	while(*digit != '\0')
	{
		if(*digit >= '0' && *digit <= '9')
		{
			num = 10 * num + (*digit - '0');
			digit++;
		}
		else
		{
			num = 0;
			break;
		}
	}

	if(minus)
	{
		num = 0 - num;
	}

	return num;
}

int main()
{
	char str[10];
	printf("input a number string:");
	scanf("%s", str);

	int num = str_to_int(str);
	printf("number is %d\n", num);
}
