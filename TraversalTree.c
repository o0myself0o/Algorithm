/*
 * =====================================================================================
 *
 *       Filename:  TraversalTree.c
 *
 *    Description:  树的遍历，递归和非递归实现
 *
 *        Version:  1.0
 *        Created:  11/01/2012 02:20:27 PM
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

typedef char datatype;
typedef struct node
{
	datatype data;
	struct node *lchild;
	struct node *rchild;
} bintnode;

typedef bintnode *bintree;
bintree root;

typedef struct stack
{
	bintree data[100];
	int tag[100];
	int top;
} seqstack;

void preorder(bintree t)
{
	if(t)
	{
		printf("%c", t->data);
		preorder(t->lchild);
		preorder(t->rchild);
	}
}

void inorder(bintree t)
{
	if(t)
	{
		inorder(t->lchild);
		printf("%c", t->data);
		inorder(t->rchild);
	}
}

void postorder(bintree t)
{
	if(t)
	{
		postorder(t->lchild);
		printf("%c", t->data);
		postorder(t->rchild);
	}
}

void createbintree(bintree *t)
{
	char ch;
	if((ch = getchar()) == ' ')
	{
		*t = NULL;
	}
	else
	{
		*t = (binnode *)malloc(sizeof(bintnode));
		(*t)->data = ch;
		createbintree(&(*t)->lchild);
		createbintree(&(*t)->rchild);
	}
}

void push(seqstack *s, bintree t)
{
	s->data[s->top] = t;
	s->top++;
}

bintree pop(seqstack *s)
{
	if(s->top != 0)
	{
		s->top--;
		return s->data[s->top];
	}
	else
	{
		return NULL;
	}
}

void preorderT(bintree t)
{
	seqstack s;
	s.top = 0;
	while(t || s.top > 0)
	{
		while(t)
		{
			printf("%c", t->data);
			push(&s, t);
			t = t->lchild;
		}

		if(s.top > 0)
		{
			t = pop(&s);
			t = t->rchild;
		}
	}
}

void inorderT(bintree t)
{
	seqstack s;
	s.top = 0;
	while(t || s.top > 0)
	{
		while(t)
		{
			push(&s, t);
			t = t->lchild;
		}

		if(s.top > 0)
		{
			t = pop(&s);
			printf("%c", t->data);
			t = t->rchild;
		}
	}
}

void postorderT(bintree t)
{
	seqstack s;
	s.top = 0;
	while(t || s.top > 0)
	{
		while(t)
		{
			s.data[s.top] = t;
			s.tag[s.top] = 0;
			s.top++;
			t = t->lchild;
		}

		while(s.top > 0 && (s.tag[s.top - 1] == 1))
		{
			s.top--;
			t = s.data[s.top];
			printf("%c", t->data);
		}

		if(s.top > 0)
		{
			t = s.data[s.top - 1];
			s.tags[s.top - 1] = 1;
			t = t->rchild;
		}
	}
}
