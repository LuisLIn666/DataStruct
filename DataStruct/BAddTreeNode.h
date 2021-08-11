/*************************************************************************************
 *
 * 文 件 名:   BAddTreeNode.h
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
#pragma once
#include<deque>
namespace BATN
{
	//内部节点
	template<typename K, typename E>
	class BAddTreeNode
	{
	public:

		//默认构造函数 创建一个空B-tree，初始化时有0个关键码及1个空孩子分支 
		//内部节点
		explicit BAddTreeNode();
		~BAddTreeNode();
		//通过孩子是否为空判断是否为底层节点
		bool isLeaf()const;

	public:
		BAddTreeNode<K, E>* parent;//父节点
		std::deque<K>key;//关键码
		std::deque<BAddTreeNode<K, E>*>child;//孩子分支，总比关键码多1

	
	};
	
	//叶子节点
	template<typename K, typename E>
	class BAddTreeLeafNode :public BAddTreeNode<K, E>
	{
	public:
		//只能作为根节点创建 

		explicit BAddTreeLeafNode();
		//默认构造函数 创建一个空B-tree，初始化时有0个关键码及1个空孩子分支 

		~BAddTreeLeafNode();

	public:
		std::deque <E*>e;//记录
		BAddTreeLeafNode<K, E>* last, * next;//链表前后
	};

}


