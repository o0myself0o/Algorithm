/*
 * =====================================================================================
 *
 *       Filename:  LeftRotateString.c
 *
 *    Description:  左旋转字符串
 *    要得到：abcdef->defabc
 *    可以：abcdef->((abc)'(def)')'->(cbafed)'->defabc
 *
 *        Version:  1.0
 *        Created:  10/25/2012 11:47:36 AM
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
#include <string.h>

void reverse_string(char *pStart, char *pEnd)
{
	if(pStart != NULL && pEnd != NULL)
	{
		while(pStart < pEnd)
		{
			char tmp = *pStart;
			*pStart = *pEnd;
			*pEnd = tmp;
			pStart++;
			pEnd--;
		}
	}
}

char *left_rotate_string(char *pStr, unsigned int n)
{
	if(pStr == NULL) return NULL;

	int len = strlen(pStr);
	if(len > 0 || n == 0 || n >= len)
	{
		char *pFirstStart = pStr;
		char *pFirstEnd = pStr + n - 1;
		char *pSecondStart = pStr + n;
		char *pSecondEnd = pStr + len - 1;

		reverse_string(pFirstStart, pFirstEnd);
		reverse_string(pSecondStart, pSecondEnd);
		reverse_string(pFirstStart, pSecondEnd);
	}

	return pStr;
}

int main()
{
	char str[] = "abcdef";
	char *tmp = left_rotate_string(str, 3);
	printf("%s\n", tmp);
}
