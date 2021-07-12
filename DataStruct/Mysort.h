#pragma once
#include<vector>
#include "common.h"

class Mysort
{
	//≤Â»Î≈≈–Ú
	void InsertSort(ElemType e[],int n);

	//’€∞Î≤Â»Î≈≈–Ú
	void binaryinsertSort(ElemType e[], int n);

	//œ£∂˚≈≈–Ú
	void shellSort(vector<ElemType> &e);

	//Ωªªª≈≈–Ú
	//√∞≈›≈≈–Ú
	void BubbleSort(vector<ElemType>& e);

	//øÏÀŸ≈≈–Ú
	void quickSort(vector<ElemType>& e,int low,int high);

	//‘Ò≈≈–Ú
	void selectSort(vector<ElemType>& e);
};

