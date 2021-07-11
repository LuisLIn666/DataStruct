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
