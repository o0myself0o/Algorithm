/*
 * =====================================================================================
 *
 *       Filename:  ReverseTree.c
 *
 *    Description:  输入一颗二元查找树，
 *    将该数转换为它的镜像，
 *    即在转换后的二元查找树中，左子树的节点都大于
 *    右子树的节点
 *
 *        Version:  1.0
 *        Created:  10/24/2012 09:45:22 AM
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

struct BSTreeNode
{
	int m_nValue;
	struct BSTreeNode *m_Left;
	struct BSTreeNode *m_Right;
};

void ReverseTree(struct BSTreeNode *root)
{
	if(root == NULL)
		return;

	printf("%d\n", root->m_nValue);
	
	struct BSTreeNode *p;
	p = root->m_Left;
	root->m_Left = root->m_Right;
	root->m_Right = p;
	
	if(root->m_Left != NULL)
		ReverseTree(root->m_Left);
	if(root->m_Right != NULL)
		ReverseTree(root->m_Right);
}

void AddBSTreeNode(struct BSTreeNode *pNode, int value)
{
	if(pNode == NULL)
	{
		struct BSTreeNode *p = (struct BSTreeNode *) \
				malloc(sizeof(struct BSTreeNode));
		p->m_Left = NULL;
		p->m_Right = NULL;
		p->m_nValue = value;
		pNode = p;
	}
	else
	{
		if(pNode->m_nValue > value)
		{
			AddBSTreeNode(pNode->m_Left, value);
		}
		else if(pNode->m_nValue < value)
		{
			AddBSTreeNode(pNode->m_Right, value);
		}
	}
}

int main()
{
	struct BSTreeNode *pRoot = NULL;
	AddBSTreeNode(pRoot, 8);
	AddBSTreeNode(pRoot, 6);
	AddBSTreeNode(pRoot, 5);
	AddBSTreeNode(pRoot, 7);
	AddBSTreeNode(pRoot, 10);
	AddBSTreeNode(pRoot, 9);
	AddBSTreeNode(pRoot, 11);
	
	ReverseTree(pRoot);
	return 0;
}
