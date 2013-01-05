/*
 * =====================================================================================
 *
 *       Filename:  TreeDepth.c
 *
 *    Description:  输入一颗二元树的根节点，求该树的深度
 *
 *        Version:  1.0
 *        Created:  11/01/2012 05:38:11 PM
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

struct BinaryTreeNode
{
	int value;
	struct BinaryTreeNode *left;
	struct BinaryTreeNode *right;
};

int TreeDepth(struct BinaryTreeNode *pTreeNode)
{
	if(!pTreeNode)
	{
		return 0;
	}

	int nLeft = TreeDepth(pTreeNode->left);
	int nRight = TreeDepth(pTreeNode->right);
	return nLeft > nRight ? (nLeft + 1) : (nRight + 1);
}
