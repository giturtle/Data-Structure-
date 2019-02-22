#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include "SList.h"


//初始化
void SListInit(SList *list) {
	assert(list != NULL);
	list->first = NULL;		//成为一个空链表
}


//销毁
//时间复杂度O(n)，因为需要遍历
void SListDestroy(SList *list) {
	SListNode *next;
	for (SListNode *cur = list->first; cur != NULL; cur = next) {
		next = cur->next;
		free(cur);
	}
	list->first = NULL;
}


//打印
void SListPrint(SList *list) {
	for (SListNode *cur = list->first; cur != NULL; cur = cur->next) {
		printf("%d --> ", cur->data);
	}
	printf("NULL\n");
}


//头插
//时间复杂度O(1)
void SListPushFront(SList *list, SLDataType data) {
	assert(list != NULL);

	//1. Node 空间
	SListNode *node = (SListNode*)malloc(sizeof(SListNode));
	assert(node);
	//2. 赋值
	node->data = data;
	//3. 新的第一个结点的下一个结点就是原来的第一个结点
	node->next = list->first;
	list->first = node;
	//4. 记录新的第一个结点
	list->first = node;

	//前2步也可以用BuySListNode封装出的函数实现
}


//头删
//时间复杂度O(1)
void SListPopFront(SList *list) {
	assert(list != NULL);		//表示没有链表
	assert(list->first != NULL);		//表示有链表，但链表为空

	SListNode *old_first = list->first;
	list->first = list->first->next;
	free(old_first);
}


//尾插
//时间复杂度O(n)，因为有遍历，单链表
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
	//****   链表中无结点(空链表)的情况  ****
	//***************************************
	if (list->first == NULL) {
		//链表为空的尾插即头插
		SListPushFront(list, data);
		return;
	}

	//***************************************
	//****     链表中已经有结点的情况    ****
	//***************************************

	//1. 找最后一个结点
	SListNode *last = list->first;
	for (; last->next != NULL; last = last->next);
	//此时last是最后一个结点

	//2. 申请空间
	SListNode *node = BuySListNode(data);
	last->next = node;
}


//尾删
//时间复杂度O(n)，因为有遍历，单链表
void SListPopBack(SList *list) {
	assert(list != NULL);
	assert(list->first != NULL);		// 0 个结点

	if (list->first->next == NULL) {
		//只有 1 个节点，此时尾删就是头删
		SListPopFront(list);
		return;
	}

	//通常情况		>= 2 个结点
	SListNode *cur;
	for (cur = list->first; cur->next->next != NULL; cur = cur->next);
	// cur 是倒数第二个结点
	free(cur->next);	//cur->next就变成了无效指针了
	cur->next = NULL;

	//也可以创建一个变量存储变为NULL之前的值
	/*SListNode *last = cur->next;
	cur->next = NULL;
	free(last);*/
}


//查找
//找到返回 <结点的地址> .没找到返回 <NULL>。
//时间复杂度O(n)，因为有遍历
SListNode* SListFind(SList* list, SLDataType data) {
	for (SListNode *cur = list->first; cur != NULL; cur = cur->next) {		//遍历
		if (cur->data == data) {
			return cur;
		}
	}
	//否则没找到
	return NULL;
}


//在pos这一个结点的后面插入新结点
//时间复杂度O(n)，因为有遍历
void SListInsertAfter(SListNode *pos, SLDataType data) {
	SListNode *node = BuySListNode(data);
	node->next = pos->next;
	pos->next = node;
}


//删除pos这一个结点，指向后面的结点(pos不是最后一个结点)
//时间复杂度O(n)，因为有遍历
void SListEraseAfter(SListNode *pos) {
	assert(pos != NULL);

	//方案一
	SListNode *del = pos->next;		//记录旧结点，很有必要
	pos->next = pos->next->next;
	free(del);

	////方案二
	//SListNode *next = pos->next->next;
	//free(pos->next);
	//pos->next = next;
}


//删除第一个遇到data数据的结点
void SListRemove(SList *list, SLDataType data) {
	//重点是找到data这个节点的前一个结点
	SListNode *previous = NULL;		//赋初值，随便都行
	SListNode *cur = list->first;

	while (cur != NULL && cur->data != data) {
		previous = cur;
		cur = cur->next;
	}
	//cur == NULL，表示没找到
	//cur != NULL && previous != NULL，cur就是要删的结点，同时prevous是要删除的前一个节点-->处理希望删除中间元素的情况
	//cur != NULL && previous == NULL, 头删  -->处理希望删除首元素的情况
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