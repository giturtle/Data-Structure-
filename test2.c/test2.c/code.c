#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <stddef.h>
#include <assert.h>
#include <stdbool.h>

SeqList a;
SeqList *b;

SeqListInit(&a);	//��a�ĵ�ַ����Ϊa��ջ�ϵĿռ䣬���û��Լ��ģ����Կ���ֱ�Ӵ��Ρ����ʡ�
SeqListInit(b);		//��ָ��b��������������ֱ�Ӵ�ָ��b����Ϊbָ��Ŀռ�δ֪��ָ����Ч�����Ա����ȿ���һ���ڴ�ռ���Լ���b = malloc();�ű�֤��Ч

//******************˳���*********************
//���ŵ㡿��������ĳ��Ԫ�أ�ʹ��O(1)��ʱ�临�ӶȾͿ����ҵ�
//��ȱ�㡿��
//1. �м�/ͷ���Ĳ���ɾ����ʱ�临�Ӷ�ΪO(N)
//2. ������Ҫ�����¿ռ䣬�������ݣ��ͷžɿռ䡣���в�С�����ġ�
//3. ����һ���ǳ�2�����������Ʊػ���һ���Ŀռ��˷ѡ����統ǰ����Ϊ100�������Ժ����ݵ�200���ټ���������5�����ݣ�����û�����ݲ����ˣ���ô���˷���95�����ݿռ䡣


typedef int SLDataType;
typedef struct SeqList
{
	SLDataType* array;  // ָ��̬���ٵ�����
	size_t size;       // ��Ч���ݸ���
	size_t capacity;   // �����ռ�Ĵ�С
}SeqList;


//��ʼ��
void SeqListInit(SeqList *psl, size_t capacity) {
	assert(psl != NULL);
	psl->capacity = capacity;
	psl->size = 0;
	psl->array = (SLDataType*)malloc(capacity * sizeof(SLDataType));
	//�޴������
	assert(psl->array != NULL);
}


//��飺size��capacity
void CheckCapacity(SeqList *psl) {
	//�Ƿ�����
	if (psl->size < psl->capacity) {
		return;
	}

	//1. �����¿ռ�
	int NewCapacity = psl->capacity * 2;
	SLDataType *NewArray = (SLDataType*)malloc(sizeof(SLDataType)*NewCapacity);
	assert(NewArray);

	//2. ��������
	for (int i = 0; i < psl->size; ++i) {
		NewArray[i] = psl->array[i];
	}

	//3. �ͷžɿռ�,�����ڴ�й©
	free(psl->array);

	//4. �����¿ռ�
	psl->array = NewArray;
	psl->capacity = NewCapacity;
}


//���
void SeqListPrint(SeqList *psl) {
	for (int i = 0; i < psl->size; ++i) {
		printf("%d ", psl->array[i]);
	}
	printf("\n");
}


//ɾ����Ԫ��
void SeqListPopFront(SeqList *psl) {
	assert(psl);
	assert(psl->size > 0);
	//i���������ڵ��±�
	for (int i = 0; i < psl->size; ++i) {
		psl->array[i - 1] = psl->array[i];
	}
	psl->size--;
}


//ɾ��βԪ��
void SeqListPopBack(SeqList *psl) {
	assert(psl);
	assert(psl->size > 0);

	psl->size--;
}


//ͷ��
void SeqListPushFront(SeqList *psl, SLDataType data) {
	SeqListInsert(psl, 0, data);

#if 0
	assert(psl != NULL);
	CheckCapacity(psl);
	//��ͷ��β��������Ų��
	for (int i = psl->size; i >= 1; --i) {
		psl->array[i] = psl->array[i - 1];
	}
	psl->array[0] = data;
	psl->size--;
#endif
}


//β��
void SeqListPushBack(SeqList *psl, SLDataType data) {
	assert(psl != NULL);
	CheckCapacity(psl);
	psl->array[psl->size] = data;
	psl->size++;
}


//����������ڴ�
void SeqListDestroy(SeqList *psl) {
	assert(psl != NULL);
	free(psl->array);
	psl->array = NULL;		//�����Դ���
	psl->capacity = psl->size = 0;
}



//���ң��� 0 ��ʼ�ĵ�һ��������ҵ��˷����������ڵ��±꣬���û�ҵ����� -1 
int SeqListFind(SeqList* sl, SLDataType data) {
	for (int i = 0; i < sl->size; ++i) {
		if (sl->array[i] == data) {
			return i;
		}
	}
	//û���ҵ�
	return -1;
}


//���룺��pos���ڵ��±������ݲ���
void SeqListInsert(SeqList* psl, size_t pos, SLDataType data) {
	//1. ��Ч�Լ���
	assert(psl);
	//2. psl�������㹻
	//3. pos����Ч��Χ[0,size]
	assert(pos >= 0 && pos <= psl->size);

	//i��ʾ�����±�
	for (int i = psl->size - 1; i >= (int)pos; --i) {
		psl->array[i + 1] = psl->array[i];
	}
	psl->array[pos] = data;
	psl->size++;
}


//ɾ����ɾ��pos���ڵ��±�����
void SeqListErase(SeqList* psl, size_t pos) {
	assert(psl);
	assert(psl->size > 0);
	assert(pos >= 0 && pos < psl->size);

	//i��ʾ���������±�
	for (int i = pos + 1; i < psl->size; ++i) {
		psl->array[i - 1] = psl->array[i];
	}
	psl->size--;
}


//ɾ����ɾ����һ��������data
void SeqListRemove(SeqList* psl, SLDataType data) {
	assert(psl != NULL);
	int pos = SeqListFind(psl, data);
	if (pos != -1) {		//�ҵ���
		SeqListErase(psl, pos);
	}
}


//ɾ����ɾ����������data����
void SeqListRemoveAll(SeqList *psl, SLDataType data) {

//����һ��ʱ�临�Ӷ�ΪO(n^2),�ռ临�Ӷ�ΪO(n)
#if 0		
	int pos;
	while (pos == SeqListFind(psl, data) != -1) {		//ʱ�临�Ӷ�O(n)
		SeqListErase(psl, pos);		//ʱ�临�Ӷ�O(n)
	}

#endif


//��������ʱ�临�Ӷ�ΪO(n)	�ռ临�Ӷ�ΪO(n)
#if 0		
	SLDataType *temparray = (SLDataType*)malloc(sizeof(SLDataType*)*psl->size);
	assert(temparray);
	int j = 0;
	for (int i = 0; i < psl->size; ++i) {
		if (psl->array[i] != data) {
			temparray[j++] = psl->array[i];
		}
	}	//��Ҫ�����ѭ��ռ���Ӷ�����
	for (int k = 0; k < j; k++) {
		psl->array[k] = temparray[k];
	}
	psl->size = j;
}
#endif


//��������ʱ�临�Ӷ�ΪO(n)	�ռ临�Ӷ�ΪO(1)
	int j = 0;
	for (int i = 0; i < psl->size; ++i) {
		if (psl->array[i] != data) {
			psl->array[j++] = psl->array[i];
		}
	}
	psl->size = j;
}


//�޸ģ��޸�pos���ڵ��±�
void SeqListModify(SeqList* psl, size_t pos, SLDataType data) {
	assert(pos >= 0 && pos < psl->size);
	psl->array[pos] = data;
}


//ð������
void SeqListBubbleSort(SeqList *psl) {
	assert(psl != NULL);
	bool isSort = true;		//���������bool���Ϳ���ʹ�ã�int isSort = 1��
	for (int i = 0; i < psl->size; i++) {
		for (int j = psl->size - 1; j > i; --j) {
			if (psl->array[i - 1] > psl->array[i]) {
				int temp = psl->array[i - 1];
				psl->array[i - 1] = psl->array[i];
				psl->array[i] = temp;
				isSort = false;		//�����������ʹ���Ϊfalse
			}
		}
	}
	if (isSort == true) {
		return;
	}
}


//���ֲ���(ǰ������������)
//����ҵ��������±꣬���û�ҵ�������-1
int SeqListBinarySearch(SeqList *psl, SLDataType data) {
	assert(psl != NULL);
	//left �� right�����±�
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