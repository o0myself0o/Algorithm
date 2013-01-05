/*
 * =====================================================================================
 *
 *       Filename:  StringReverse.c
 *
 *    Description:  翻转句子中单词的顺序
 *
 *        Version:  1.0
 *        Created:  10/22/2012 02:05:31 PM
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

void reverse(char *sentence, int begin, int end);

void reverse_words(char *sentence)
{
	int length;
	int begin = -1;
	int end = -1;
	int i = 0;

	length = strlen(sentence);

	for(; i < length; i++)
	{
		if(begin == -1 && *(sentence + i) == ' ')
			continue;

		if(begin == -1)
		{
			begin = i;
			continue;
		}

		if(*(sentence + i) == ' ')
			end = i - 1;
		else if(i == length - 1)
			end = i;
		else
			continue;

		reverse(sentence, begin, end);//按字母单独翻转
		begin = -1;
		end = -1;
	}

	reverse(sentence, 0, length - 1);//再整个句子翻转
}

void reverse(char *sentence, int begin, int end)
{
	while(begin < end)
	{
		char c = *(sentence + begin);
		*(sentence + begin) = *(sentence + end);
		*(sentence + end) = c;
		begin++;
		end--;
	}
}

int main()
{
	char sentence[100];
    strcpy(sentence, "I am a student.");
	reverse_words(sentence);
	printf("%s\n", sentence);
}
