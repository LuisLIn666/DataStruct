/*************************************************************************************
 *
 * 文 件 名:   BitNode.h
 * 描    述:   二叉树节点
 * 
 * 版    本：  V1.0
 * 创 建 者：  01
 * 创建时间：  2021/7/11 16:58
 * ======================================
 * 历史更新记录
 * 版本：V          修改时间：         修改人：
 * 修改内容：
 * ======================================
*************************************************************************************/
// Copyright (c) 2011 rubicon IT GmbH
#pragma once
#include "common.h"


class BitNode
{
public:
	BitNode();
	BitNode(ElemType data);

	ElemType data;
	BitNode* lchild, * rchild;

};


