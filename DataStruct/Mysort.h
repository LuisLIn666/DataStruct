#pragma once
#include<vector>
#include "common.h"

class Mysort
{
	//��������
	void InsertSort(ElemType e[],int n);

	//�۰��������
	void binaryinsertSort(ElemType e[], int n);

	//ϣ������
	void shellSort(vector<ElemType> &e);

	//��������
	//ð������
	void BubbleSort(vector<ElemType>& e);

	//��������
	void quickSort(vector<ElemType>& e,int low,int high);

	//������
	void selectSort(vector<ElemType>& e);

	//���������
	void heapSort(vector<ElemType>& e);

	//�鲢����
	void mergeSort(vector<ElemType>& e,int low ,int high);


};

