/*************************************************************************************
 *
 * �� �� ��:   AVLTreeNode.cpp
 * ��    ��: 
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
#include "AVLTreeNode.h"

template<class T>
inline AVLTreeNode<T>::AVLTreeNode(T key, AVLTreeNode* lchild, AVLTreeNode* rchild)
{
	this->key = key;
	this->heigh = 0;
	this->lchild = lchild;
	this->rchild = rchild;
}