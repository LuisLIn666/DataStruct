/*************************************************************************************
 *
 * �� �� ��:   BiTree.h
 * ��    ��:   ������
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
#pragma once
#include "BitNode.h"
class BiTree
{

public:
	BiTree();
	//���ʵ�ǰ�ڵ�
	void visit(BitNode* T);

	void createBiTree(ElemType e);
	//ǰ�����
	void preOrder(BitNode*T);

	//�������

	void inOrder(BitNode* T);

	//�������
	void postOrder(BitNode* T);


private:
	BitNode* root;
	int high;
};

