#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include "SList.h"


//��ʼ��
void SListInit(SList *list) {
	assert(list != NULL);
	list->first = NULL;		//��Ϊһ��������
}


//����
//ʱ�临�Ӷ�O(n)����Ϊ��Ҫ����
void SListDestroy(SList *list) {
	SListNode *next;
	for (SListNode *cur = list->first; cur != NULL; cur = next) {
		next = cur->next;
		free(cur);
	}
	list->first = NULL;
}


//��ӡ
void SListPrint(SList *list) {
	for (SListNode *cur = list->first; cur != NULL; cur = cur->next) {
		printf("%d --> ", cur->data);
	}
	printf("NULL\n");
}


//ͷ��
//ʱ�临�Ӷ�O(1)
void SListPushFront(SList *list, SLDataType data) {
	assert(list != NULL);

	//1. Node �ռ�
	SListNode *node = (SListNode*)malloc(sizeof(SListNode));
	assert(node);
	//2. ��ֵ
	node->data = data;
	//3. �µĵ�һ��������һ��������ԭ���ĵ�һ�����
	node->next = list->first;
	list->first = node;
	//4. ��¼�µĵ�һ�����
	list->first = node;

	//ǰ2��Ҳ������BuySListNode��װ���ĺ���ʵ��
}


//ͷɾ
//ʱ�临�Ӷ�O(1)
void SListPopFront(SList *list) {
	assert(list != NULL);		//��ʾû������
	assert(list->first != NULL);		//��ʾ������������Ϊ��

	SListNode *old_first = list->first;
	list->first = list->first->next;
	free(old_first);
}


//β��
//ʱ�临�Ӷ�O(n)����Ϊ�б�����������
SListNode *BuySListNode(SLDataType data) {
	SListNode *node = (SListNode*)malloc(sizeof(SListNode));
	assert(node != NULL);
	node->data = data;
	node->next = NULL;

	return node;
}

void SListPushBack(SList *list, SLDataType data) {
	assert(list != NULL);

	//***************************************
	//****   �������޽��(������)�����  ****
	//***************************************
	if (list->first == NULL) {
		//����Ϊ�յ�β�弴ͷ��
		SListPushFront(list, data);
		return;
	}

	//***************************************
	//****     �������Ѿ��н������    ****
	//***************************************

	//1. �����һ�����
	SListNode *last = list->first;
	for (; last->next != NULL; last = last->next);
	//��ʱlast�����һ�����

	//2. ����ռ�
	SListNode *node = BuySListNode(data);
	last->next = node;
}


//βɾ
//ʱ�临�Ӷ�O(n)����Ϊ�б�����������
void SListPopBack(SList *list) {
	assert(list != NULL);
	assert(list->first != NULL);		// 0 �����

	if (list->first->next == NULL) {
		//ֻ�� 1 ���ڵ㣬��ʱβɾ����ͷɾ
		SListPopFront(list);
		return;
	}

	//ͨ�����		>= 2 �����
	SListNode *cur;
	for (cur = list->first; cur->next->next != NULL; cur = cur->next);
	// cur �ǵ����ڶ������
	free(cur->next);	//cur->next�ͱ������Чָ����
	cur->next = NULL;

	//Ҳ���Դ���һ�������洢��ΪNULL֮ǰ��ֵ
	/*SListNode *last = cur->next;
	cur->next = NULL;
	free(last);*/
}


//����
//�ҵ����� <���ĵ�ַ> .û�ҵ����� <NULL>��
//ʱ�临�Ӷ�O(n)����Ϊ�б���
SListNode* SListFind(SList* list, SLDataType data) {
	for (SListNode *cur = list->first; cur != NULL; cur = cur->next) {		//����
		if (cur->data == data) {
			return cur;
		}
	}
	//����û�ҵ�
	return NULL;
}


//��pos��һ�����ĺ�������½��
//ʱ�临�Ӷ�O(n)����Ϊ�б���
void SListInsertAfter(SListNode *pos, SLDataType data) {
	SListNode *node = BuySListNode(data);
	node->next = pos->next;
	pos->next = node;
}


//ɾ��pos��һ����㣬ָ�����Ľ��(pos�������һ�����)
//ʱ�临�Ӷ�O(n)����Ϊ�б���
void SListEraseAfter(SListNode *pos) {
	assert(pos != NULL);

	//����һ
	SListNode *del = pos->next;		//��¼�ɽ�㣬���б�Ҫ
	pos->next = pos->next->next;
	free(del);

	////������
	//SListNode *next = pos->next->next;
	//free(pos->next);
	//pos->next = next;
}


//ɾ����һ������data���ݵĽ��
void SListRemove(SList *list, SLDataType data) {
	//�ص����ҵ�data����ڵ��ǰһ�����
	SListNode *previous = NULL;		//����ֵ����㶼��
	SListNode *cur = list->first;

	while (cur != NULL && cur->data != data) {
		previous = cur;
		cur = cur->next;
	}
	//cur == NULL����ʾû�ҵ�
	//cur != NULL && previous != NULL��cur����Ҫɾ�Ľ�㣬ͬʱprevous��Ҫɾ����ǰһ���ڵ�-->����ϣ��ɾ���м�Ԫ�ص����
	//cur != NULL && previous == NULL, ͷɾ  -->����ϣ��ɾ����Ԫ�ص����
	if (cur == NULL) {
		return;
	}
	if (previous == NULL) {
		SListPopFront(list);
		return;
	}
	previous->next = cur->next;
	free(cur);
}