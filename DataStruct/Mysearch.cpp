#include "Mysearch.h"
#include "common.h"
#include "SSTable.h"
#include "IndexTable.h"
#include <algorithm>
//带有哨兵的顺序查找
int Mysearch::Sq_search(SStable ST,ElemType key)
{
	ST.elem[0] = key;
	int i;
	for ( i = ST.TableLen; ST.elem[i] != key; i--);
	
	return i;
}
//二分查找
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

//索引查找
int Mysearch::Block_Search(vector<ElemType> a, int key, IndexTable table)
{
		
	//1.对块进行排序
	sort(0, table.len - 1);
	int low, high, mid;

	low = 0; high = table.len - 1;
	//算法思想：先通过二分查找找到对应的块，再对块进行顺序查找
	while (low<=mid)
	{
		if (high-low==1) // low和high差一个索引块，说明元素在high所指的块中
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



	 



