/*************************************************************************************
 *
 * 文 件 名:   stack.h
 * 描    述: 
 * 
 * 版    本：  V1.0
 * 创 建 者：  01
 * 创建时间：  2021/7/28 23:05
 * ======================================
 * 历史更新记录
 * 版本：V          修改时间：         修改人：
 * 修改内容：
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
	
	//初始化
	void initStack(sqStack &s);

	//判定栈空
	bool emptyStack(sqStack& s);

	//进栈
	bool Push(sqStack& s, ElemType e);

	//出栈
	bool pop(sqStack& s, ElemType &e);

	//读取栈顶
	ElemType getTop(sqStack s);
};

