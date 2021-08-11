/*************************************************************************************
 *
 * �� �� ��:   BAddTreeNode.h
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
#pragma once
#include<deque>
namespace BATN
{
	//�ڲ��ڵ�
	template<typename K, typename E>
	class BAddTreeNode
	{
	public:

		//Ĭ�Ϲ��캯�� ����һ����B-tree����ʼ��ʱ��0���ؼ��뼰1���պ��ӷ�֧ 
		//�ڲ��ڵ�
		explicit BAddTreeNode();

	public:
		BAddTreeNode<K, E>* parent;//���ڵ�
		std::deque<K>key;//�ؼ���
		std::deque<BAddTreeNode<K, E>*>child;//���ӷ�֧���ܱȹؼ����1
	};
	
}


