/*************************************************************************************
 *
 * �� �� ��:   BAddTree.cpp
 * ��    ��: 
 * 
 * ��    ����  V1.0
 * �� �� �ߣ�  01
 * ����ʱ�䣺  2021/8/11 0:17
 * ======================================
 * ��ʷ���¼�¼
 * �汾��V          �޸�ʱ�䣺         �޸��ˣ�
 * �޸����ݣ�
 * ======================================
*************************************************************************************/
// Copyright (c) 2011 rubicon IT GmbH
#include "BAddTree.h"
template<typename K, typename E>
inline BAT::BAddTree<K, E>::BAddTree(int order)
{
	if (order < 2)order = 2;//Ĭ��2��
	m_order = order;
	//ע������ʼ��ΪҶ�ӽڵ�
	this->m_root = new BAddTreeLeafNode<K, E>(); m_size = 0; m_hitParentNode = nullptr;
	m_header = new BAddTreeLeafNode<K, E>();
	m_trail = new BAddTreeLeafNode<K, E>();
	BAddTreeLeafNode<K, E>* _leaf = (BAddTreeLeafNode<K, E>*)(this->m_root);
	m_header->next = _leaf; m_trail->last = _leaf;//����
	_leaf->last = m_header; _leaf->next = m_trail;
}

template<typename K, typename E>
BAT::BAddTree<K, E>::~BAddTree()
{
	if (!this->m_root)return;//û�и��Ͳ�ɾ��
	std::deque<BAddTreeNode<K, E>> q;//���븨�����а���α���ɾ��
	
	q.push(this->m_root);//�������
	while (!q.empty())
	{
		BAddTreeNode<K, E>* p = q.front();
		q.pop();
		int count = p->child.size();
		for (int i = 0; i < count; ++i) {
			if (p->child[i]) {
				q.push(p->child[i]);//������к������
			}
		}
		if (p->isLeaf()) {
			BAddTreeLeafNode<K, E>* _t = (BAddTreeLeafNode<K, E>*)p;
			delete _t, _t = nullptr;//����Ҷ�ӽڵ�
		}
		else {
			delete p, p = nullptr;//�ͷ�ÿ���ڲ��ڵ�
		}
	}
	delete m_header, m_header = nullptr;
	delete m_trail, m_trail = nullptr;
	this->m_root = nullptr;
	this->m_size = 0;
}

template<typename K, typename E>
int const BAT::BAddTree<K, E>::order() const
{
	return m_order;
}

template<typename K, typename E>
int const BAT::BAddTree<K, E>::size() const
{
	return m_size;
}


