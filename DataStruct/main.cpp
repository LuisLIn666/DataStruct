﻿#include<iostream>
#include<vector>
using namespace std;


//定义一个👉移函数
template<typename T>
void shiftRight(T t[],int begin,int end)
{
	//算法思想
	//设T 有N个元素，将第end个元素往begin移动，begin 包括begin~end-1个元素往后移动
	T temp;
	try
	{
		//最后一个元素开始
		temp = t[end];
		for (int i = end; i >begin; i--)
		{
			t[i] = t[i- 1];
		}
		t[begin] = temp;
	}
	catch (const std::exception& e)
	{
		cout << e.what() << endl;
	}
}

int main()
{
	 int a[]  = { 1,4,5,6,7 };
	shiftRight(a,0,4);
	for (int i = 0; i <5; i++)
	{
		cout << a[i] << endl;

	}
	return 0;
}