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

	//ǰ�����
	void preOrder(BitNode*T);

	//�������

	void inOrder(BitNode* T);

	//�������
	void postOrder(BitNode* T);

	//���ø��ڵ�
	BitNode* setRoot(ElemType e);

	//��ȡ��
	BitNode* getRoot();

	//��ȡ��
	BiTree& getTree();

	//�����½ڵ�
	void insertNewNode(ElemType e);

	//��ȡ����
	int getHigh(BitNode *T);

	//ǰ������ǵݹ�
	void preOrdernorecursion(BitNode* T);

	//��������ǵݹ�
	void inOrdernorecursion(BitNode* T);

	//��������ǵݹ�
	void postOrdernorecursion(BitNode* T);
private:
	BitNode* root;
	int high;
};

