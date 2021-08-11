/*************************************************************************************
 *
 * �� �� ��:   BAddTree.h
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
		explicit BAddTree(int order);//��С��2ʱĬ��Ϊ2��,���˻�Ϊ���������� (m>=2);���ﲻ��Ĭ��ֵ�����ڼ̳�
		~BAddTree();

		int const order()const;//�״�
		int const size()const;//��ģ

			//�����ӿ�
		
		virtual BAddTreeLeafNode<K, E>* search(E const&);//����
		virtual  bool insert(E const&);//����
		virtual bool remove(E const&);//ɾ��

		template<typename Visist>
		void list_traversal(Visist);//����
	protected:
		BAddTree();//�ɼ̳�
		void solveOverFlow(BAddTreeLeafNode<K, E>*);//��������������� ����Ϊ�ڵ�
		void solveUnderFlow(BAddTreeLeafNode<K, E>*);//��������������� ����Ϊ�ڵ�
	protected:
		int m_size;//�ؼ�������
		int m_order;//B-���Ľ״�,����Ϊ2(���˻�Ϊ����������) ����ʱָ�� һ�㲻���޸�
		BAddTreeNode<K, E>* m_root;//����
		BAddTreeNode<K, E>* m_hitParentNode;//���ҷ���ʱ���нڵ�ĸ��׻��ߴ�͸�ײ�����һ�����ʵĽڵ㣬����Ϊ��ʱ ����ʺ�Ϊ��
		BAddTreeLeafNode<K, E>* m_header, * m_trail;//˫��������β
	};
	
}


