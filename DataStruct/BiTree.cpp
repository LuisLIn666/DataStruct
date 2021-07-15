/*************************************************************************************
 *
 * �� �� ��:   BiTree.cpp
 * ��    ��: 
 * 
 * ��    ����  V1.0
 * �� �� �ߣ�  01
 * ����ʱ�䣺  2021/7/11 17:07
 * ======================================
 * ��ʷ���¼�¼
 * �汾��V          �޸�ʱ�䣺         �޸��ˣ�
 * �޸����ݣ�
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
