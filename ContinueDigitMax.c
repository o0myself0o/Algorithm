/*
 * =====================================================================================
 *
 *       Filename:  ContinueDigitMax.c
 *
 *    Description:  在字符串中找出连续最长的数字串
 *
 *        Version:  1.0
 *        Created:  10/25/2012 10:02:58 AM
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

int continue_max(char *input, char *output)
{
	int i;
	int maxlen = 0;
	char *maxstr = 0;

	while(1)
	{
		while(input != NULL && (*input < '0' || *input > '9'))
		{
			input++;
		}

		if(input == NULL) break;

		int count = 0;
		char *tmpstr = input;

		while(input != NULL && (*input >= '0' && *input <= '9'))
		{
			count++;
			input++;
		}

		if(count > maxlen)
		{
			maxlen = count;
			maxstr = tmpstr;
		}
	}

	for(i = 0; i < maxlen; i++)
	{
		output[i] = maxstr[i];
	}

	output[i] = '\0';
	return maxlen;
}

int main()
{
	char output[100];
	char source[] = "abc12345ed123ss1234567890s";
	int len = continue_max(source, output);
	printf("digits len: %d\n", len);
	printf("is: %s\n", output);
}
