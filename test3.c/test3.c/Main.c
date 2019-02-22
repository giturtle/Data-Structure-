#define _CRT_SECURE_NO_WARNINGS
#include "SList.h"
#include <stdlib.h>

//****************** ���� *********************
//�߼��������Խṹ�������ڴ治һ������
//����Ԫ�ص��߼�˳����ͨ�������е�ָ�����Ӵ���ʵ�ֵ� ��


void test1() {
	SList list;
	SListInit(&list);
	SListPushFront(&list, 3);
	SListPushFront(&list, 2);
	SListPushFront(&list, 1);
	SListPrint(&list);

	SListPopFront(&list);
	SListPrint(&list);
	SListPushBack(&list, 4);
	SListPushBack(&list, 5);
	SListPushBack(&list, 6);
	SListPrint(&list);

	SListPopBack(&list);
	SListPrint(&list);
	SListPopBack(&list);
	SListPrint(&list);
	SListPopBack(&list);
	SListPrint(&list); 
	SListPopBack(&list);
	SListPrint(&list);
	SListPopBack(&list);
	SListPrint(&list);

}

void test2() {
	SList list;
	SListInit(&list);

	SListPushBack(&list, 1);
	SListPushBack(&list, 2);
	SListPushBack(&list, 3);
	SListPushBack(&list, 4);
	SListPushBack(&list, 5);

	SListNode *n3 = SListFind(&list, 3);
	SListInsertAfter(n3, 10);
	SListPrint(&list);

	SListEraseAfter(n3);
	SListPrint(&list);

}

void test3() {
	SList list;
	SListInit(&list);

	SListPushBack(&list, 1);
	SListPushBack(&list, 2);
	SListPushBack(&list, 3);
	SListPushBack(&list, 4);
	SListPushBack(&list, 5);
	SListPrint(&list);

	SListRemove(&list, 3);
	SListPrint(&list);
	SListRemove(&list, 1);
	SListPrint(&list);
	SListRemove(&list, 5);
	SListPrint(&list);


}



int main() {
	//test1();
	//test2();
	test3();
	system("pause");
	return 0;
}