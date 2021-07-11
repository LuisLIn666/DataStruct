/*************************************************************************************
 *
 * �� �� ��:   SqList.h
 * ��    ��: 
 * 
 * ��    ����  V1.0
 * �� �� �ߣ�  01
 * ����ʱ�䣺  2021/7/11 14:05
 * ======================================
 * ��ʷ���¼�¼
 * �汾��V          �޸�ʱ�䣺         �޸��ˣ�
 * �޸����ݣ�
 * ======================================
*************************************************************************************/
// Copyright (c) 2011 rubicon IT GmbH
#pragma once
#include "common.h"
class SqList
{
public:
	//���캯��
	SqList(int size);
	//��������
	~SqList();
	//�ж��Ƿ�Ϊ��
	bool is_empty();
	//���
	void ClearList();
	//�����Ա�ֵ
	bool addList(ElemType e[]);

	//�������
	void printList();
private:
	ElemType* data;
	int length;
	int MaxSize;

	friend class Mysearch;
};

