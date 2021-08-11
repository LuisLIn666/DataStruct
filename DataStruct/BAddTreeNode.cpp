/*************************************************************************************
 *
 * �� �� ��:   BAddTreeNode.cpp
 * ��    ��: 
 * 
 * ��    ����  V1.0
 * �� �� �ߣ�  01
 * ����ʱ�䣺  2021/8/11 23:02
 * ======================================
 * ��ʷ���¼�¼
 * �汾��V          �޸�ʱ�䣺         �޸��ˣ�
 * �޸����ݣ�
 * ======================================
*************************************************************************************/
// Copyright (c) 2011 rubicon IT GmbH
#include "BAddTreeNode.h"
//�ڲ��ڵ�
template<typename K, typename E>
inline BATN::BAddTreeNode<K, E>::BAddTreeNode()
{
	parent = nullptr;
	child.insert(child.end(), nullptr);//Ĭ�Ϻ���Ϊ��
}

template<typename K, typename E>
BATN::BAddTreeNode<K, E>::~BAddTreeNode()
{
}

template<typename K, typename E>
inline bool BATN::BAddTreeNode<K, E>::isLeaf() const
{
	return !child[0];
}


template<typename K, typename E>
inline BATN::BAddTreeLeafNode<K, E>::BAddTreeLeafNode()
{
	last = nullptr; next = nullptr;
}
template<typename K, typename E>
inline BATN::BAddTreeLeafNode<K, E>::~BAddTreeLeafNode()
{
	int _s = e.size();
	for (int i = 0; i < _s; ++i) {
		delete e[i], e[i] = nullptr;
	}
	e.resize(0);
}