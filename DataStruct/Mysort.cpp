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
//���������
void HeadAdjust(vector<ElemType>& e,int k,int len)
{
	ElemType temp = e[k];
	for (int i = 2*k; i <=len; i*=2)
	{
		if (i < len && e[i] < e[i + 1])
		{
			i++;
		}
		else if (temp >e[i])
		{
			break;
		}
		else
		{
			e[k] = e[i];
			k = i;
		}
	}
	e[k] = temp;
}
void buildMaxHeap(vector<ElemType>& e)
{
	for (int i = e.size()/2; i >=0; i--)
	{
		HeadAdjust(e, i, e.size());
	}
}

void Mysort::heapSort(vector<ElemType>& e) 
{
	buildMaxHeap(e);
	for (int i = e.size(); i>=0; i--)
	{
		mySwap<ElemType>(e[i], e[0]);
		HeadAdjust(e, 1, i - 1);
	}
}
void Merge(vector<ElemType>& e, int low, int mid,int high)
{
	//e���low~mid��mid+1~high��Ϊ��������
	int high_point = mid + 1;
	int low_point = low;
	vector<ElemType> b;
	for (low_point, high_point; low_point <= mid && high_point <= high_point;)
	{
		if (e[low_point]<=e[high_point])
		{
			b.push_back(e[low_point]);
			low_point++;
		}
		else
		{
			b.push_back(e[high_point]);
			high_point++;
		}
	}
	while (low_point<=mid)
	{
		b.push_back(e[low_point]);
		low_point++;
	}

	while (high_point <= high)
	{
		b.push_back(e[high_point]);
		high_point++;
	}
	e = b;
}


void Mysort::mergeSort(vector<ElemType>& e, int low, int high) 
{
	if (low<high)
	{
		int mid = (low + high) / 2;
		mergeSort(e,low,mid);
		mergeSort(e,mid+1,high);
		Merge(e,low,mid,high);
	}
}
