#pragma once
//定义常用的方法，模板方法以及参数
#include<iostream>
using namespace std;


typedef  int ElemType ;
 const int Maxsize=100;

//定义一个👉移函数，将最后一个数插入到第一个数，第一个至第i-1个往后移动
template<typename T>
 void shiftRight(T t[], int begin, int end)
{
	//算法思想
	//设T 有N个元素，将第end个赋值给begin移动，begin~end-1（包括begin）个元素往后移动
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

	//定义一个交换函数
	template<typename T>
	 void mySwap(T &a, T &b)
	{
		T temp;
		temp = a;
		a = b;
		b = temp;
	}

	