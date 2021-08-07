/*************************************************************************************
 *
 * 文 件 名:   stack.cpp
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
#include "sqStack.h"

void sqStack::initStack(sqStack& s)
{
	s.top = -1;
}

bool sqStack::emptyStack(sqStack& s)
{
	if (s.top==-1)
	{
		return true;
	}
	else
	{
		return false;
	}
}

bool sqStack::Push(sqStack& s, ElemType e)
{
	if (s.top==Maxsize-1)
	{
		return false;
	}
	else
	{
		s.top++;
		s.data[s.top] = e;
		return true;
	}
	
}

bool sqStack::pop(sqStack& s, ElemType& e)
{
	if (s.top==-1)
	{
		return false;
	}
	else
	{
		e = s.data[s.top--];
		return true;
	}
	
}

ElemType sqStack::getTop(sqStack s)
{
	if (s.top==-1)
	{
		return NULL;
	}
	else
	{
		return s.data[s.top];
	}
}
