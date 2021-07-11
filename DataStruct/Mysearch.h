#pragma once
#include<vector>

#include "common.h"
#include "SSTable.h"
#include "SqList.h"
#include "IndexTable.h"
 class Mysearch
{
public:
	//À≥–Ú≤È’“
	int Sq_search(SStable ST,ElemType key);
	//’€∞Î≤È’“
	int Binary_Search(SqList L, ElemType key);
	//øÈ≤È’“

	int Block_Search(vector<ElemType> a, int key, IndexTable &table);
};

