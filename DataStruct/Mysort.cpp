#include "Mysort.h"

void Mysort::InsertSort(ElemType e[], int n)
{
	//第0-i-1为排序好的序列，第i为待排序序列，第i+1-n-1为未排序序列
	int i, j;
	//找出0-i-1的位置k，满足e[j]<=e[i]<e[j+1]
	//将e[j+1]~e[i-1]往后移动
	//将e[i]插入到e[k+1]上
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
			//j+1~i-1往后移动，i插入到j+1里面
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
