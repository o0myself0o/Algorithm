/*
 * =====================================================================================
 *
 *       Filename:  ConvertToDoubleList.c
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  10/19/2012 04:19:59 PM
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

typedef struct BSTreeNode
{
	int m_nValue; //value of node
	struct BSTreeNode *m_pLeft; //left child of node
	struct BSTreeNode *m_pRight; //right child of node
} BSTreeNode;

typedef BSTreeNode DoubleList;
DoubleList *pHead;
DoubleList *pListIndex;

void convertToDoubleList(BSTreeNode *pCurrent);

// 创建二元查找树
void addBSTreeNode(BSTreeNode *pCurrent, int value)
{
	if(pCurrent == NULL)
	{
		BSTreeNode *pBSTree = malloc(sizeof(BSTreeNode));
		pBSTree->m_pLeft = NULL;
		pBSTree->m_pRight = NULL;
		pBSTree->m_nValue = value;

		pCurrent = pBSTree;
	}
	else
	{
		if(pCurrent->m_nValue > value)
		{
			addBSTreeNode(pCurrent->m_pLeft, value);
		}
		else if(pCurrent->m_nValue < value)
		{
			addBSTreeNode(pCurrent->m_pRight, value);
		}
		else
		{
			printf("node exist.\n");
		}
	}
}

//中序遍历二元查找树
void ergodicBSTree(BSTreeNode *pCurrent)
{
	if(!pCurrent) return;

	if(pCurrent->m_pLeft)
		ergodicBSTree(pCurrent->m_pLeft);
	
	convertToDoubleList(pCurrent);

	if(pCurrent->m_pRight)
		ergodicBSTree(pCurrent->m_pRight);
}

//二叉树转成list
void convertToDoubleList(BSTreeNode *pCurrent)
{
	pCurrent->m_pLeft = pListIndex;
	if(pListIndex)
	{
		pListIndex->m_pRight = pCurrent;
	}
	else
	{
		pHead = pCurrent;
	}
	pListIndex = pCurrent;
	printf("%d\n", pCurrent->m_nValue);
}

int main()
{
	BSTreeNode *pRoot = NULL;
	pListIndex = NULL;
	pHead = NULL;
	addBSTreeNode(pRoot, 10);
	addBSTreeNode(pRoot, 4);
	addBSTreeNode(pRoot, 6);
	addBSTreeNode(pRoot, 8);
	addBSTreeNode(pRoot, 12);
	addBSTreeNode(pRoot, 14);
	addBSTreeNode(pRoot, 15);
	addBSTreeNode(pRoot, 16);
	ergodicBSTree(pRoot);
	return 0;
}
