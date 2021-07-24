/*************************************************************************************
 *
 * �� �� ��:   LinkList.h
 * ��    ��: 
 * 
 * ��    ����  V1.0
 * �� �� �ߣ�  01
 * ����ʱ�䣺  2021/7/21 23:53
 * ======================================
 * ��ʷ���¼�¼
 * �汾��V          �޸�ʱ�䣺         �޸��ˣ�
 * �޸����ݣ�
 * ======================================
*************************************************************************************/
// Copyright (c) 2011 rubicon IT GmbH
#pragma once
#include "LNode.h"

class LinkList
{
	LinkList();

	//ͷ���뷨
	LinkList listHeadInsert(ElemType data);

	//����d��һ���ڵ�
	LNode* find(const ElemType insertdata);

	//d��λ�ò���
	void insertPos(ElemType finddata, ElemType insertdata);
private:
	LNode* head;
};
