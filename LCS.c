/*
 * =====================================================================================
 *
 *       Filename:  LCS.c
 *
 *    Description:  求两个字符串的最长公共子串长度
 *
 *        Version:  1.0
 *        Created:  11/05/2012 03:40:17 PM
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

enum decreaseDir
{
	kInit = 0,
	kLeft,
	kUp,
	kLeftUp
};

void LCS_Print(int **LCS_direction,
			   char *pStr1, char *pStr2,
			   size_t row, size_t col);

int LCS(char *pStr1, char *pStr2)
{
	if(!pStr1 || !pStr2)
		return 0;
	
	size_t length1 = strlen(pStr1);
	size_t length2 = strlen(pStr2);

	if(!length1 || !length2)
		return 0;

	size_t i, j;
	int **LCS_length;

	LCS_length = (int **)malloc(sizeof(int *) * length1);

	for(i = 0; i < length1; i++)
	{
		LCS_length[i] = (int *)malloc(sizeof(int) * length2);
	}

	for(i = 0; i < length1; i++)
	{
		for(j = 0; j < length2; j++)
		{
			LCS_length[i][j] = 0;
		}
	}

	int **LCS_direction;
	
	LCS_direction = (int **)malloc(sizeof(int *) * length1);
	
	for(i = 0; i < length1; i++)
	{
		LCS_direction[i] = (int *)malloc(sizeof(int) * length2);
	}

	for(i = 0; i < length1; i++)
	{
		for(j = 0; j < length2; j++)
		{
			LCS_direction[i][j] = kInit;
		}
	}

	for(i = 0; i < length1; i++)
	{
		for(j = 0; j < length2; j++)
		{
			if(i == 0 || j == 0)
			{
				if(pStr1[i] == pStr2[j])
				{
					LCS_length[i][j] = 1;
					LCS_direction[i][j] = kLeftUp;
				}
				else
				{
					LCS_length[i][j] = 0;
				}
			}
			else if(pStr1[i] == pStr2[j])
			{
				LCS_length[i][j] = LCS_length[i-1][j-1] + 1;
			}
			else if(LCS_length[i-1][j] > LCS_length[i][j-1])
			{
				LCS_length[i][j] = LCS_length[i-1][j];
				LCS_direction[i][j] = kUp;
			}
			else
			{
				LCS_length[i][j] = LCS_length[i][j-1];
				LCS_direction[i][j] = kLeft;
			}
		}
	}

	LCS_Print(LCS_direction, pStr1, pStr2, 
					length1-1, length2-1);
	return LCS_length[length1-1][length2-1];
}

void LCS_Print(int **LCS_direction,
			   char *pStr1, char *pStr2,
			   size_t row, size_t col)
{
	if(!pStr1 || !pStr2)
		return;

	size_t length1 = strlen(pStr1);
	size_t length2 = strlen(pStr2);

	if(length1 == 0 || length2 == 0 ||
		!(row < length1 && col < length2))
		return;

	if(LCS_direction[row][col] == kLeftUp)
	{
		if(row > 0 && col > 0)
		{
			LCS_Print(LCS_direction, pStr1, pStr2,
						row - 1, col - 1);
		}
		printf("%c", pStr1[row]);
	}
	else if(LCS_direction[row][col] == kLeft)
	{
		if(col > 0)
		{
			LCS_Print(LCS_direction, pStr1, pStr2,
						row, col - 1);
		}
	}
	else if(LCS_direction[row][col] == kUp)
	{
		if(row > 0)
		{
			LCS_Print(LCS_direction, pStr1, pStr2,
						row - 1, col);
		}
	}
}

void main()
{
	char *str1 = "BDCABA";
	char *str2 = "ABCBDAB";
	LCS(str1, str2);
}

