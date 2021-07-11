/*************************************************************************************
 *
 * �� �� ��:   BTree.cpp
 * ��    ��: 
 * 
 * ��    ����  V1.0
 * �� �� �ߣ�  01
 * ����ʱ�䣺  2021/7/11 11:26
 * ======================================
 * ��ʷ���¼�¼
 * �汾��V          �޸�ʱ�䣺         �޸��ˣ�
 * �޸����ݣ�
 * ======================================
*************************************************************************************/
// Copyright (c) 2011 rubicon IT GmbH
#pragma once
#include "BTree.h"

BTree::BTree(int t)
{
	root = nullptr;  
	this->t = t;
}

void BTree::traverse()
{
	if (root != NULL) root->traverse();
}

BTreeNode* BTree::search(int k)
{
	return (root == nullptr) ? nullptr : root->search(k);
}
