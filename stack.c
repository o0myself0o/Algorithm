/*
 * =====================================================================================
 *
 *       Filename:  stack.c
 *
 *    Description:  a stack which can find the min value in o(1).
 *
 *        Version:  1.0
 *        Created:  10/19/2012 05:40:21 PM
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

#define STACK_LEN	50

typedef struct
{
	int val;
	int min;
} stack_item;

typedef struct
{
	stack_item	data[STACK_LEN];
	int			top;
} stack;

void push(stack *stk, int val)
{
	stk->data[++stk->top].val = val;
	if(stk->top > 0)
	{
		if(val < stk->data[stk->top - 1].min)
			stk->data[stk->top].min = val;
		else
			stk->data[stk->top].min = stk->data[stk->top - 1].min;
	}
	else
		stk->data[stk->top].min = val;
}

int pop(stack *stk)
{
	return stk->data[stk->top--].val;
}

int min(stack *stk)
{
	return stk->data[stk->top].min;
}
