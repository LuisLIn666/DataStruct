#pragma once
#include "common.h"

//定义索引表用于分块查找

//索引表项
typedef struct
{
	 ElemType maxkey; //最大key
	 //取闭区间
	 int start; //开始下标
	 int end;  //结束下标

}Node;

typedef struct
{
	Node indx[10];
	int len;
}IndexTable;