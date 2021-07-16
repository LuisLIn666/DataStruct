/*************************************************************************************
 *
 * 文 件 名:   AVLTreeNode.h
 * 描    述: 二叉平衡树
 * 
 * 版    本：  V1.0
 * 创 建 者：  01
 * 创建时间：  2021/7/16 10:19
 * ======================================
 * 历史更新记录
 * 版本：V          修改时间：         修改人：
 * 修改内容：
 * ======================================
*************************************************************************************/
// Copyright (c) 2011 rubicon IT GmbH
#pragma once
template <class T>
class AVLTreeNode
{
public:
	AVLTreeNode(T key, AVLTreeNode* l, AVLTreeNode* r);
private:
	T key;//关键字
	AVLTreeNode* lchild, * rchild;
	int heigh;

template <class T>
friend class AVLTree;
};


