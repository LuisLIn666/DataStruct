/*************************************************************************************
 *
 * �� �� ��:   stack.h
 * ��    ��: 
 * 
 * ��    ����  V1.0
 * �� �� �ߣ�  01
 * ����ʱ�䣺  2021/7/28 23:05
 * ======================================
 * ��ʷ���¼�¼
 * �汾��V          �޸�ʱ�䣺         �޸��ˣ�
 * �޸����ݣ�
 * ======================================
*************************************************************************************/
// Copyright (c) 2011 rubicon IT GmbH
#pragma once
#include "common.h"
class sqStack
{


public:
	ElemType data[Maxsize];
	int top;
	
	//��ʼ��
	void initStack(sqStack &s);

	//�ж�ջ��
	bool emptyStack(sqStack& s);

	//��ջ
	bool Push(sqStack& s, ElemType e);

	//��ջ
	bool pop(sqStack& s, ElemType &e);

	//��ȡջ��
	ElemType getTop(sqStack s);
};

