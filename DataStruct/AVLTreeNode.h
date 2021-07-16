/*************************************************************************************
 *
 * �� �� ��:   AVLTreeNode.h
 * ��    ��: ����ƽ����
 * 
 * ��    ����  V1.0
 * �� �� �ߣ�  01
 * ����ʱ�䣺  2021/7/16 10:19
 * ======================================
 * ��ʷ���¼�¼
 * �汾��V          �޸�ʱ�䣺         �޸��ˣ�
 * �޸����ݣ�
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
	T key;//�ؼ���
	AVLTreeNode* lchild, * rchild;
	int heigh;

template <class T>
friend class AVLTree;
};


