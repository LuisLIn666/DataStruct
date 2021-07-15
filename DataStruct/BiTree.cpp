/*************************************************************************************
 *
 * 文 件 名:   BiTree.cpp
 * 描    述: 
 * 
 * 版    本：  V1.0
 * 创 建 者：  01
 * 创建时间：  2021/7/11 17:07
 * ======================================
 * 历史更新记录
 * 版本：V          修改时间：         修改人：
 * 修改内容：
 * ======================================
*************************************************************************************/
// Copyright (c) 2011 rubicon IT GmbH
#include "BiTree.h"
#include "BitNode.h"



BiTree::BiTree()
{
	root = nullptr;
	high = 0;
}

void BiTree::visit(BitNode* T)
{
	cout << " " << T->data << " ";
}

void BiTree::createBiTree(ElemType e)
{

}

void BiTree::inOrder(BitNode* T)
{
	if (T)
	{
		inOrder(T->lchild);
		BiTree::visit(T);
		
		inOrder(T->rchild);
	}
}

void BiTree::preOrder(BitNode*T)
{
	if (T)
	{
		BiTree::visit(T);
		preOrder(T->lchild);
		preOrder(T->rchild);
	}
}

void BiTree::postOrder(BitNode* T)
{

	if (T)
	{
		postOrder(T->lchild);
		postOrder(T->rchild);
		BiTree::visit(T);
		
	}
}
