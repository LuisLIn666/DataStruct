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