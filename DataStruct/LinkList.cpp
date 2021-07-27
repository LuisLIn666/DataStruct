/*************************************************************************************
 *
 * �� �� ��:   LinkList.cpp
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
#include "LinkList.h"
LinkList::LinkList()
{
	head = new LNode(NULL);
}

LinkList LinkList::listHeadInsert(ElemType data)
{
	auto p = new LNode(data);

	p->next = head->next;
	head->next = p;
	
	return LinkList();
}

LNode* LinkList::find(const ElemType data)
{
	auto p = head;
	for (; p; p = p->next){
		if (p->next->data == data);
		break;
	}
	return p;
}

void LinkList::insertPos(ElemType finddata, ElemType insertdata)
{
	auto p=find(finddata);
	auto q = new LNode(insertdata);
	q->next = p->next;
	p->next = q;
	
}

void LinkList::tailInsert(LNode* head,ElemType e)
{
	//����ͷ�ڵ�
	if (this->head==NULL)
	{
		head = new LNode(NULL);
	}

	auto h = head; 
	auto r = h;
	//rһֱ�ƶ������һ���ڵ�
	if (r->next!=NULL)
	{
		r = r->next;
	}

	auto p = new LNode(e);

	r->next = p;
	r = r->next;
}

LNode* LinkList::getEle(LNode* head, int i)
{
	int j = 1;
	auto p = head->next;
	if (i==0)
	{
		return head;
	}
	else if (i < 0)
	{
		return nullptr;
	}
	while (p&&j<i)
	{
		p = p->next;
		j++;
	}
	
}
