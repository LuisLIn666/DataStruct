/*************************************************************************************
 *
 * �� �� ��:   ChapterTwoTest.h
 * ��    ��: �ڶ��¿κ���ϰ
 * 
 * ��    ����  V1.0
 * �� �� �ߣ�  01
 * ����ʱ�䣺  2021/7/21 23:48
 * ======================================
 * ��ʷ���¼�¼
 * �汾��V          �޸�ʱ�䣺         �޸��ˣ�
 * �޸����ݣ�
 * ======================================
*************************************************************************************/
// Copyright (c) 2011 rubicon IT GmbH
#pragma once
#include "SqList.h"

class ChapterTwoTest
{
	//��һ��
	bool del_min(SqList &L);

	//�ڶ���
	void reverseList(SqList& L);

	//������
	bool dele_Elem_X(SqList& L, ElemType x);
	
	//������,����
	bool del_s_to_t(SqList& L, ElemType s, ElemType t);

	//�����⣬����
	bool del_s_to_t2(SqList& L, ElemType s, ElemType t);

	//������
	void del_repetion(SqList& L);

	//������
	SqList& merge(SqList& L1, SqList& L2);

	//8
	void reverse_a_b(SqList& L,int m,int n);

	//9
	void searchExchangeInsert(SqList& L, ElemType x);
	
	//10

};

