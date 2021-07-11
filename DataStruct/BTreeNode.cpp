/*************************************************************************************
 *
 * �� �� ��:   BTreeNode.cpp
 * ��    ��:  B���ڵ㷽��ʵ��
 * 
 * ��    ����  V1.0
 * �� �� �ߣ�  01
 * ����ʱ�䣺  2021/7/11 10:44
 * ======================================
 * ��ʷ���¼�¼
 * �汾��V          �޸�ʱ�䣺         �޸��ˣ�
 * �޸����ݣ�
 * ======================================
*************************************************************************************/
// Copyright (c) 2011 rubicon IT GmbH
#pragma once
#include "BTreeNode.h"

BTreeNode::BTreeNode(int t, bool leaf)
{
	this->t = t;
	this->leaf = leaf;

	// ����ڵ���Դ�Źؼ��ֵ�����ڴ棬�Լ�����ָ��
	this->key = new int[2 * t - 1];
	this->c = new BTreeNode * [2 * t];

	// ��ʼ���ڵ��ڲ��ĺ�����Ŀ
	this->n = 0;
}

void BTreeNode::traverse()
{
    // �ڵ��ڹ���n���ؼ���,n+1������
    int i;
    for (i = 0; i < n; i++)
    {
        // ����ýڵ㲻��Ҷ�ӽڵ㣬�ڴ�ӡ�ؼ���֮ǰ�������ӽڵ�
        if (leaf == false)
            c[i]->traverse();
        cout << " " << key[i];
    }

    // ��ӡ���һ�������ϵ����нڵ�
    if (leaf == false)
        c[i]->traverse();
}

BTreeNode* BTreeNode::search(int k)
{
    // �ҵ��ڵ��ϵ�һ������k��Ĺؼ���
        int i = 0;
    while (i < n && k > key[i])
        i++;

    // ����ҵ��Ĺؼ��ֵ���k,����
    if (key[i] == k)
        return this;

    // ���û���ҵ�k�ұ��ڵ���Ҷ�ӽڵ㣬�򷵻�NULL
    if (leaf == true)
        return NULL;

    // ����Ӧָ���Ӧ����������Ѱ
    return c[i]->search(k);
}
