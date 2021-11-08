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

int function(int a, int b, int c)
{
	
	return abs(a - b) + abs(b - c) + abs(c-a);
}
	
int main()
{
	int e, f, g;
	int a[3] = { -1,0,9 };
	int b[4] = { -25,-10,10,11 };
	int c[5] = { 2,9,17,30,41 };
	int d[3][4][5];
	int min = function(a[0],b[0],c[0]);
	for ( int i = 0; i <3; i++)
	{
		for (int  j = 0; j <4; j++)
		{
			for (int  k = 0; k <5; k++)
			{
				if (min > function(a[i],b[j],c[k]))
				{
					min = function(a[i], b[j], c[k]);
					e = i;
					f = j;
					g = k;
					
				}
				
				
				//cout<<function(a[i],b[k],c[j])<<endl;
				//cout << "(" << a[i] << "," << b[j] << "," << c[k] << ")" << endl;
			}
		}
	}
	
	cout << min;
	cout << e+1 <<" "<< f+1 <<" "<< g+1;
	return 0;
}