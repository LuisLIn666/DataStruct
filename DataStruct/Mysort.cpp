#include "Mysort.h"

void Mysort::InsertSort(ElemType e[], int n)
{
	//��0-i-1Ϊ����õ����У���iΪ���������У���i+1-n-1Ϊδ��������
	int i, j;
	//�ҳ�0-i-1��λ��k������e[j]<=e[i]<e[j+1]
	//��e[j+1]~e[i-1]�����ƶ�
	//��e[i]���뵽e[k+1]��
	for ( i = 1; i <n; i++)
	{
		ElemType temp = e[i];
		if (e[i]<e[i-1])
		{
			
			j = i - 1;
			while (temp<e[j])
			{
				j--;
			}
			//j+1~i-1�����ƶ���i���뵽j+1����
			shiftRight<ElemType>(e,j+1,i);
		}
	}

}

void Mysort::binaryinsertSort(ElemType e[], int n)
{
	int i, low, high, mid;
	for ( i = 1; i <=n; i++)
	{
		
		low = 1; high = i - 1;
		while (low<=high)
		{
			mid = (low+high)/2;
			if (e[mid]>e[0])
			{
				high = mid - 1;

			}
			else
			{
				low = mid + 1;
			}

		}
		shiftRight<ElemType>(e, high + 1, i);
	}
}
