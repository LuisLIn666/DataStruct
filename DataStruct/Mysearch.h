#pragma once
#include<vector>

#include "common.h"
#include "SSTable.h"
#include "SqList.h"
#include "IndexTable.h"
 class Mysearch
{
public:
	//˳�����
	int Sq_search(SStable ST,ElemType key);
	//�۰����
	int Binary_Search(SqList L, ElemType key);
	//�����

	int Block_Search(vector<ElemType> a, int key, IndexTable &table);
};

