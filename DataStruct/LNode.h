/*************************************************************************************
 *
 * 文 件 名:   LNode.h
 * 描    述: 
 * 
 * 版    本：  V1.0
 * 创 建 者：  01
 * 创建时间：  2021/7/21 23:51
 * ======================================
 * 历史更新记录
 * 版本：V          修改时间：         修改人：
 * 修改内容：
 * ======================================
*************************************************************************************/
// Copyright (c) 2011 rubicon IT GmbH
#pragma once
#include "common.h"



class LNode
{
public:
	LNode(const ElemType data);

	
	

	ElemType data;     //数据域
	LNode* next;  //指针域
};

