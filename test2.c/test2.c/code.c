#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <stddef.h>
#include <assert.h>
#include <stdbool.h>

SeqList a;
SeqList *b;

SeqListInit(&a);	//传a的地址，因为a是栈上的空间，是用户自己的，所以可以直接传参、访问。
SeqListInit(b);		//传指针b，但函数不可以直接传指针b，因为b指向的空间未知，指针无效。所以必须先开辟一段内存空间给自己用b = malloc();才保证有效

//******************顺序表*********************
//【优点】：当查找某个元素，使用O(1)的时间复杂度就可以找到
//【缺点】：
//1. 中间/头部的插入删除，时间复杂度为O(N)
//2. 增容需要申请新空间，拷贝数据，释放旧空间。会有不小的消耗。
//3. 增容一般是呈2倍的增长，势必会有一定的空间浪费。例如当前容量为100，满了以后增容到200，再继续插入了5个数据，后面没有数据插入了，那么就浪费了95个数据空间。


typedef int SLDataType;
typedef struct SeqList
{
	SLDataType* array;  // 指向动态开辟的数组
	size_t size;       // 有效数据个数
	size_t capacity;   // 容量空间的大小
}SeqList;


//初始化
void SeqListInit(SeqList *psl, size_t capacity) {
	assert(psl != NULL);
	psl->capacity = capacity;
	psl->size = 0;
	psl->array = (SLDataType*)malloc(capacity * sizeof(SLDataType));
	//无错误检验
	assert(psl->array != NULL);
}


//检查：size和capacity
void CheckCapacity(SeqList *psl) {
	//是否扩容
	if (psl->size < psl->capacity) {
		return;
	}

	//1. 申请新空间
	int NewCapacity = psl->capacity * 2;
	SLDataType *NewArray = (SLDataType*)malloc(sizeof(SLDataType)*NewCapacity);
	assert(NewArray);

	//2. 搬移数据
	for (int i = 0; i < psl->size; ++i) {
		NewArray[i] = psl->array[i];
	}

	//3. 释放旧空间,否则内存泄漏
	free(psl->array);

	//4. 保存新空间
	psl->array = NewArray;
	psl->capacity = NewCapacity;
}


//输出
void SeqListPrint(SeqList *psl) {
	for (int i = 0; i < psl->size; ++i) {
		printf("%d ", psl->array[i]);
	}
	printf("\n");
}


//删除首元素
void SeqListPopFront(SeqList *psl) {
	assert(psl);
	assert(psl->size > 0);
	//i：数据所在的下标
	for (int i = 0; i < psl->size; ++i) {
		psl->array[i - 1] = psl->array[i];
	}
	psl->size--;
}


//删除尾元素
void SeqListPopBack(SeqList *psl) {
	assert(psl);
	assert(psl->size > 0);

	psl->size--;
}


//头插
void SeqListPushFront(SeqList *psl, SLDataType data) {
	SeqListInsert(psl, 0, data);

#if 0
	assert(psl != NULL);
	CheckCapacity(psl);
	//从头到尾进行数据挪移
	for (int i = psl->size; i >= 1; --i) {
		psl->array[i] = psl->array[i - 1];
	}
	psl->array[0] = data;
	psl->size--;
#endif
}


//尾插
void SeqListPushBack(SeqList *psl, SLDataType data) {
	assert(psl != NULL);
	CheckCapacity(psl);
	psl->array[psl->size] = data;
	psl->size++;
}


//销毁申请的内存
void SeqListDestroy(SeqList *psl) {
	assert(psl != NULL);
	free(psl->array);
	psl->array = NULL;		//防御性代码
	psl->capacity = psl->size = 0;
}



//查找：从 0 开始的第一个，如果找到了返回数据所在的下标，如果没找到返回 -1 
int SeqListFind(SeqList* sl, SLDataType data) {
	for (int i = 0; i < sl->size; ++i) {
		if (sl->array[i] == data) {
			return i;
		}
	}
	//没有找到
	return -1;
}


//插入：在pos所在的下标做数据插入
void SeqListInsert(SeqList* psl, size_t pos, SLDataType data) {
	//1. 有效性检验
	assert(psl);
	//2. psl的容量足够
	//3. pos的有效范围[0,size]
	assert(pos >= 0 && pos <= psl->size);

	//i表示数据下标
	for (int i = psl->size - 1; i >= (int)pos; --i) {
		psl->array[i + 1] = psl->array[i];
	}
	psl->array[pos] = data;
	psl->size++;
}


//删除：删掉pos所在的下标数据
void SeqListErase(SeqList* psl, size_t pos) {
	assert(psl);
	assert(psl->size > 0);
	assert(pos >= 0 && pos < psl->size);

	//i表示的是数据下标
	for (int i = pos + 1; i < psl->size; ++i) {
		psl->array[i - 1] = psl->array[i];
	}
	psl->size--;
}


//删除：删除第一个遇到的data
void SeqListRemove(SeqList* psl, SLDataType data) {
	assert(psl != NULL);
	int pos = SeqListFind(psl, data);
	if (pos != -1) {		//找到了
		SeqListErase(psl, pos);
	}
}


//删除：删除表中所有data数据
void SeqListRemoveAll(SeqList *psl, SLDataType data) {

//方案一：时间复杂度为O(n^2),空间复杂度为O(n)
#if 0		
	int pos;
	while (pos == SeqListFind(psl, data) != -1) {		//时间复杂度O(n)
		SeqListErase(psl, pos);		//时间复杂度O(n)
	}

#endif


//方案二：时间复杂度为O(n)	空间复杂度为O(n)
#if 0		
	SLDataType *temparray = (SLDataType*)malloc(sizeof(SLDataType*)*psl->size);
	assert(temparray);
	int j = 0;
	for (int i = 0; i < psl->size; ++i) {
		if (psl->array[i] != data) {
			temparray[j++] = psl->array[i];
		}
	}	//主要是这个循环占复杂度主体
	for (int k = 0; k < j; k++) {
		psl->array[k] = temparray[k];
	}
	psl->size = j;
}
#endif


//方案三：时间复杂度为O(n)	空间复杂度为O(1)
	int j = 0;
	for (int i = 0; i < psl->size; ++i) {
		if (psl->array[i] != data) {
			psl->array[j++] = psl->array[i];
		}
	}
	psl->size = j;
}


//修改：修改pos所在的下标
void SeqListModify(SeqList* psl, size_t pos, SLDataType data) {
	assert(pos >= 0 && pos < psl->size);
	psl->array[pos] = data;
}


//冒泡排序
void SeqListBubbleSort(SeqList *psl) {
	assert(psl != NULL);
	bool isSort = true;		//如果不适用bool类型可以使用：int isSort = 1；
	for (int i = 0; i < psl->size; i++) {
		for (int j = psl->size - 1; j > i; --j) {
			if (psl->array[i - 1] > psl->array[i]) {
				int temp = psl->array[i - 1];
				psl->array[i - 1] = psl->array[i];
				psl->array[i] = temp;
				isSort = false;		//发生过交换就处理为false
			}
		}
	}
	if (isSort == true) {
		return;
	}
}


//二分查找(前提是数据有序)
//如果找到，返回下标，如果没找到，返回-1
int SeqListBinarySearch(SeqList *psl, SLDataType data) {
	assert(psl != NULL);
	//left 、 right代表下标
	int left = 0;
	int right = psl->size - 1;
	while (left <= right) {
		int mid = (left + right) / 2;
		if (psl->array[mid] == data) {
			return mid;
		}
		else if (data <= psl->array[left]) {
			right = mid - 1;
		}
		else {
			left = mid + 1;
		}
	}
	return -1;
}