#include "Mysearch.h"
#include "common.h"
#include "SSTable.h"
#include "IndexTable.h"
#include <algorithm>
//�����ڱ���˳�����
int Mysearch::Sq_search(SStable ST,ElemType key)
{
	ST.elem[0] = key;
	int i;
	for ( i = ST.TableLen; ST.elem[i] != key; i--);
	
	return i;
}
//���ֲ���
int Mysearch::Binary_Search(SqList L, ElemType key)
{
	int low = 0; int high = L.length - 1;
	int mid;

	while (low<=high)
	{
		mid= (low + high) / 2;
		if (L.elem[mid]==key)
		{
			return mid;
		}
		else if(L.elem[mid]>key)
		{
			high = mid - 1;
		}
		else
		{
			low = mid + 1;
		}

	}


	return -1;
}

//��������
int Mysearch::Block_Search(vector<ElemType> a, int key, IndexTable table)
{
		
	//1.�Կ��������
	sort(0, table.len - 1);
	int low, high, mid;

	low = 0; high = table.len - 1;
	//�㷨˼�룺��ͨ�����ֲ����ҵ���Ӧ�Ŀ飬�ٶԿ����˳�����
	while (low<=mid)
	{
		if (high-low==1) // low��high��һ�������飬˵��Ԫ����high��ָ�Ŀ���
		{
			for (int i =table.indx[high].start; i <= table.indx[high].end; i++)
			{
				if (a[i]==key)
				{
					return key;
				}
				else
				{
					return -1;
				}
			}
		}
		else if (table.indx[mid].maxkey>key)
		{
			high = mid - 1;
		}
		else
		{
			low = mid + 1;
		}
	}

	
	return 0;
}
;



	 



