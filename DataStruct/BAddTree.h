/*************************************************************************************
 *
 * 文 件 名:   BAddTree.h
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
#pragma once
#include <deque>
#include "BAddTreeNode.h"
namespace BAT 
{
	using namespace BATN;
	template<typename K, typename E>
	class BAddTree
	{
	public:
		explicit BAddTree(int order);//当小于2时默认为2阶,即退化为二叉搜索树 (m>=2);这里不设默认值，便于继承
		~BAddTree();

		int const order()const;//阶次
		int const size()const;//规模

			//操作接口
		
		virtual BAddTreeLeafNode<K, E>* search(E const&);//查找
		virtual  bool insert(E const&);//插入
		virtual bool remove(E const&);//删除

		template<typename Visist>
		void list_traversal(Visist);//遍历
	protected:
		BAddTree();//可继承
		void solveOverFlow(BAddTreeLeafNode<K, E>*);//解决插入上溢现象 参数为节点
		void solveUnderFlow(BAddTreeLeafNode<K, E>*);//解决插入下溢现象 参数为节点
	protected:
		int m_size;//关键码总数
		int m_order;//B-树的阶次,至少为2(即退化为二叉搜索树) 创建时指定 一般不做修改
		BAddTreeNode<K, E>* m_root;//树根
		BAddTreeNode<K, E>* m_hitParentNode;//查找访问时命中节点的父亲或者穿透底层后最后一个访问的节点，当树为空时 其访问后为空
		BAddTreeLeafNode<K, E>* m_header, * m_trail;//双向链表首尾
	};
	
}


