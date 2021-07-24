/*************************************************************************************
 *
 * 文 件 名:   LinkList.cpp
 * 描    述: 
 * 
 * 版    本：  V1.0
 * 创 建 者：  01
 * 创建时间：  2021/7/21 23:53
 * ======================================
 * 历史更新记录
 * 版本：V          修改时间：         修改人：
 * 修改内容：
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
