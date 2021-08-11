/*************************************************************************************
 *
 * 文 件 名:   BAddTree.cpp
 * 描    述: 
 * 
 * 版    本：  V1.0
 * 创 建 者：  01
 * 创建时间：  2021/8/11 0:17
 * ======================================
 * 历史更新记录
 * 版本：V          修改时间：         修改人：
 * 修改内容：
 * ======================================
*************************************************************************************/
// Copyright (c) 2011 rubicon IT GmbH
#include "BAddTree.h"
template<typename K, typename E>
inline BAT::BAddTree<K, E>::BAddTree(int order)
{
	if (order < 2)order = 2;//默认2阶
	m_order = order;
	//注：根初始化为叶子节点
	this->m_root = new BAddTreeLeafNode<K, E>(); m_size = 0; m_hitParentNode = nullptr;
	m_header = new BAddTreeLeafNode<K, E>();
	m_trail = new BAddTreeLeafNode<K, E>();
	BAddTreeLeafNode<K, E>* _leaf = (BAddTreeLeafNode<K, E>*)(this->m_root);
	m_header->next = _leaf; m_trail->last = _leaf;//链表
	_leaf->last = m_header; _leaf->next = m_trail;
}

template<typename K, typename E>
BAT::BAddTree<K, E>::~BAddTree()
{
	if (!this->m_root)return;//没有根就不删除
	std::deque<BAddTreeNode<K, E>> q;//引入辅助队列按层次遍历删除
	
	q.push(this->m_root);//树根入队
	while (!q.empty())
	{
		BAddTreeNode<K, E>* p = q.front();
		q.pop();
		int count = p->child.size();
		for (int i = 0; i < count; ++i) {
			if (p->child[i]) {
				q.push(p->child[i]);//添加所有孩子入队
			}
		}
		if (p->isLeaf()) {
			BAddTreeLeafNode<K, E>* _t = (BAddTreeLeafNode<K, E>*)p;
			delete _t, _t = nullptr;//析构叶子节点
		}
		else {
			delete p, p = nullptr;//释放每个内部节点
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


