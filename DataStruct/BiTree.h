/*************************************************************************************
 *
 * 文 件 名:   BiTree.h
 * 描    述:   二叉树
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
#pragma once
#include "BitNode.h"
class BiTree
{

public:
	BiTree();
	//访问当前节点
	void visit(BitNode* T);

	void createBiTree(ElemType e);
	//前序遍历
	void preOrder(BitNode*T);

	//中序遍历

	void inOrder(BitNode* T);

	//后序遍历
	void postOrder(BitNode* T);


private:
	BitNode* root;
	int high;
};

