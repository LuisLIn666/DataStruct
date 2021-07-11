/*************************************************************************************
 *
 * 文 件 名:   SqList.h
 * 描    述: 
 * 
 * 版    本：  V1.0
 * 创 建 者：  01
 * 创建时间：  2021/7/11 14:05
 * ======================================
 * 历史更新记录
 * 版本：V          修改时间：         修改人：
 * 修改内容：
 * ======================================
*************************************************************************************/
// Copyright (c) 2011 rubicon IT GmbH
#pragma once
#include "common.h"
class SqList
{
public:
	//构造函数
	SqList(int size);
	//析构函数
	~SqList();
	//判断是否为空
	bool is_empty();
	//清空
	void ClearList();
	//给线性表赋值
	bool addList(ElemType e[]);

	//输出内容
	void printList();
private:
	ElemType* data;
	int length;
	int MaxSize;

	friend class Mysearch;
};

