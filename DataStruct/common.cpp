/*************************************************************************************
 *
 * 文 件 名:   common.cpp
 * 描    述: 
 * 
 * 版    本：  V1.0
 * 创 建 者：  01
 * 创建时间：  2021/7/10 15:07
 * ======================================
 * 历史更新记录
 * 版本：V          修改时间：         修改人：
 * 修改内容：
 * ======================================
*************************************************************************************/
// Copyright (c) 2011 rubicon IT GmbH
#include "common.h"

//定义一个👉移函数
template<typename T>
void shiftRight(T t[], int begin, int end)
{
	//算法思想
	//设T 有N个元素，将第end个元素往begin移动，begin 包括begin~end-1个元素往后移动
	T temp;
	try
	{
		//最后一个元素开始
		temp = t[end];
		for (int i = end; i > begin; i--)
		{
			t[i] = t[i - 1];
		}
		t[begin] = temp;
	}
	catch (const std::exception& e)
	{
		cout << e.what() << endl;
	}
}