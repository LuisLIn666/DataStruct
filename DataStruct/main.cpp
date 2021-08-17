/*************************************************************************************
 *
 * 文 件 名:   main.cpp
 * 描    述: 
 * 
 * 版    本：  V1.0
 * 创 建 者：  01
 * 创建时间：  2021/7/7 11:17
 * ======================================
 * 历史更新记录
 * 版本：V          修改时间：         修改人：
 * 修改内容：
 * ======================================
*************************************************************************************/
// Copyright (c) 2011 rubicon IT GmbH

#include <iostream>
#include <thread>

#include "SSTable.h"
#include"ChapterEightTest.h"

using namespace std;


int main()
{
	SSTable s;
	ElemType e[5] = { 4,2,9,0,8 };
	s.elem = e;
	s.TableLen = 5;

	ChapterEightTest mytest;
	mytest.two(s, s.TableLen);

	for (int i = 0; i < s.TableLen; i++)
	{
		cout << s.elem[i];
	}
	
	
	
	return 0;
}