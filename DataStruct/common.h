#pragma once
//定义常用的方法，模板方法以及参数
#include<iostream>
using namespace std;


typedef  int ElemType ;


//定义一个👉移函数
template<typename T>
void shiftRight(T t[], int begin, int end);