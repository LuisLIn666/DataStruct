#pragma once
#include "common.h"

//�������������ڷֿ����

//��������
typedef struct
{
	 ElemType maxkey; //���key
	 //ȡ������
	 int start; //��ʼ�±�
	 int end;  //�����±�

}Node;

typedef struct
{
	Node indx[10];
	int len;
}IndexTable;