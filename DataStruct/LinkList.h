/*************************************************************************************
 *
 * 文 件 名:   LinkList.h
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
#pragma once
#include "LNode.h"

class LinkList
{
	LinkList();

	//头插入法
	LinkList listHeadInsert(ElemType data);

	//查找d上一个节点
	LNode* find(const ElemType insertdata);

	//d的位置插入
	void insertPos(ElemType finddata, ElemType insertdata);
private:
	LNode* head;
};

