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

void Mysort::shellSort(vector<ElemType> &e)
{
	ElemType temp;
	for (int dk = e.size()/2; dk>=1; dk=dk/2)
	{
		for (int i = dk; i <=e.size()-1; i++)
		{
			if (e[i] < e[i - dk])
			{
				temp = e[i];
				int j;
				for ( j = i - dk; j >= 0 && temp < e[j]; j -= dk)
				{
					e[j + dk] = e[j];
				}
				e[j + dk] = temp;
			}
		}
	}
}

void Mysort::BubbleSort(vector<ElemType>& e)
{
	for (int i = 0; i < e.size()-1; i++)
	{
		bool flag = false;
		for (int j = e.size()-1; j>i; j--)
		{
			mySwap<ElemType>(e[j - 1], e[j]);
			flag = true;
		}
		if (!flag)
		{
			return;
		}
	}
}

int Partition(vector<ElemType>& e, int low, int high)
{
	ElemType pivot = e[low];
	while (low<high)
	{
		if (low<high&&e[high]>pivot)
		{
			high--;
		}
		else
		{
			e[low] = e[high];
		}

		if (low < high && e[low] <= pivot)
		{
			low++;
		}
		else
		{
			e[high] = e[low];
		}
	}
	e[low] = pivot;
	return low;
}
void Mysort::quickSort(vector<ElemType>& e, int low, int high)
{
	if (low < high)
	{
		int pivotpos = Partition(e, low, high);
		quickSort(e,low,pivotpos-1);
		quickSort(e, low, pivotpos + 1);
	}
}

void Mysort::selectSort(vector<ElemType>& e)
{
	int min;
	for (int i = 0; i <e.size(); i++)
	{
		min = i;
		for (int j = i+1; j <e.size()-1; j++)
		{
			if (e[j]<e[min])
			{
				min = j;
			}
		}
		if (min!=i)
		{
			mySwap<ElemType>(e[i], e[min]);
		}
	}
}
