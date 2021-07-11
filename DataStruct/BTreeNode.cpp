/*************************************************************************************
 *
 * 文 件 名:   BTreeNode.cpp
 * 描    述:  B树节点方法实现
 * 
 * 版    本：  V1.0
 * 创 建 者：  01
 * 创建时间：  2021/7/11 10:44
 * ======================================
 * 历史更新记录
 * 版本：V          修改时间：         修改人：
 * 修改内容：
 * ======================================
*************************************************************************************/
// Copyright (c) 2011 rubicon IT GmbH
#pragma once
#include "BTreeNode.h"

BTreeNode::BTreeNode(int t, bool leaf)
{
	this->t = t;
	this->leaf = leaf;

	// 分配节点可以存放关键字的最大内存，以及孩子指针
	this->key = new int[2 * t - 1];
	this->c = new BTreeNode * [2 * t];

	// 初始化节点内部的孩子数目
	this->n = 0;
}

void BTreeNode::traverse()
{
    // 节点内共计n个关键字,n+1个孩子
    int i;
    for (i = 0; i < n; i++)
    {
        // 如果该节点不是叶子节点，在打印关键字之前，遍历子节点
        if (leaf == false)
            c[i]->traverse();
        cout << " " << key[i];
    }

    // 打印最后一棵子树上的所有节点
    if (leaf == false)
        c[i]->traverse();
}

BTreeNode* BTreeNode::search(int k)
{
    // 找到节点上第一个不比k大的关键字
        int i = 0;
    while (i < n && k > key[i])
        i++;

    // 如果找到的关键字等于k,返回
    if (key[i] == k)
        return this;

    // 如果没有找到k且本节点是叶子节点，则返回NULL
    if (leaf == true)
        return NULL;

    // 从相应指针对应的子树上搜寻
    return c[i]->search(k);
}
