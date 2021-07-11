/*************************************************************************************
 *
 * 文 件 名:   BTree.cpp
 * 描    述: 
 * 
 * 版    本：  V1.0
 * 创 建 者：  01
 * 创建时间：  2021/7/11 11:26
 * ======================================
 * 历史更新记录
 * 版本：V          修改时间：         修改人：
 * 修改内容：
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
