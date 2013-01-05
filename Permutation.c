/*
 * =====================================================================================
 *
 *       Filename:  Permutation.c
 *
 *    Description:  输入一个字符串，打印出该字符串中字符的所有排列
 *
 *        Version:  1.0
 *        Created:  11/01/2012 06:22:30 PM
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

void Permutation(char *pStr, char *pBegin)
{
	if(!pStr || !pBegin)
	{
		return;
	}

	if(*pBegin == '\0')
	{
		printf("%s\n", pStr);
	}
	else
	{
		char *pCh = pBegin;
		for(; *pCh != '\0'; pCh++)
		{
			char temp = *pCh;
			*pCh = *pBegin;
			*pBegin = temp;

			Permutation(pStr, pBegin + 1);

			temp = *pCh;
			*pCh = *pBegin;
			*pBegin = temp;
		}
	}
}
