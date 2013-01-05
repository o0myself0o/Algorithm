/*
 * =====================================================================================
 *
 *       Filename:  FindMaxLen.c
 *
 *    Description:  求二叉树中节点的最大距离
 *
 *        Version:  1.0
 *        Created:  10/22/2012 04:35:26 PM
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

typedef struct Node
{
	struct Node *pLeft;
	struct Node *pRight;
	int nMaxLeft; //左子树中的最长距离
	int nMaxRight;//右子树中的最长距离
	char chValue;
} Node;

int FindMaxLen(Node *pRoot)
{
	int nMaxLen = 0;

	if(pRoot == NULL) return;

	if(pRoot->pLeft == NULL) pRoot->nMaxLeft = 0;

	if(pRoot->pRight == NULL) pRoot->nMaxRight = 0;

	if(pRoot->pLeft != NULL) FindMaxLen(pRoot->pLeft);

	if(pRoot->pRight != NULL) FindMaxLen(pRoot->pRight);

	if(pRoot->pLeft != NULL)
	{
		int nTempMax = 0;
		if(pRoot->pLeft->nMaxLeft > pRoot->pLeft->nMaxRight)
			nTempMax = pRoot->pLeft->nMaxLeft;
		else
			nTempMax = pRoot->pLeft->nMaxRight;

		pRoot->nMaxLeft = nTempMax + 1;
	}

	if(pRoot->pRight != NULL)
	{
		int nTempMax = 0;
		if(pRoot->pRight->nMaxLeft > pRoot->pRight->nMaxRight)
			nTempMax = pRoot->pRight->nMaxLeft;
		else
			nTempMax = pRoot->pRight->nMaxRight;

		pRoot->nMaxRight = nTempMax + 1;
	}

	nMaxLen = pRoot->nMaxLeft + pRoot->nMaxRight;
	return nMaxLen;
}
