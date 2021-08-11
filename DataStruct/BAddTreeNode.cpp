/*************************************************************************************
 *
 * 文 件 名:   BAddTreeNode.cpp
 * 描    述: 
 * 
 * 版    本：  V1.0
 * 创 建 者：  01
 * 创建时间：  2021/8/11 23:02
 * ======================================
 * 历史更新记录
 * 版本：V          修改时间：         修改人：
 * 修改内容：
 * ======================================
*************************************************************************************/
// Copyright (c) 2011 rubicon IT GmbH
#include "BAddTreeNode.h"
//内部节点
template<typename K, typename E>
inline BATN::BAddTreeNode<K, E>::BAddTreeNode()
{
	parent = nullptr;
	child.insert(child.end(), nullptr);//默认孩子为空
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