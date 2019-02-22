#pragma once

// <无头、单向、非循环链表> 增 删 查 改 的实现：

typedef int SLDataType;		//single list 

//定义链表中每一个"结点" 的结构体
typedef struct SListNode {
	SLDataType data;
	struct SListNode *next;
}SListNode;

//定义"链表" 的结构体
typedef struct SList {
	struct SListNode *first;	//指向链表第一个结点的指针
}SList;


//***************************************
//****			定义结束			 ****
//***************************************
//****			功能开始			 ****
//***************************************


//初始化、销毁
void SListInit(SList *list);
void SListDestroy(SList *list);

//打印
void SListPrint(SList *list);

//增删改查
//头插
void SListPushFront(SList *list, SLDataType data);

//头删
void SListPopFront(SList *list);

//尾插
SListNode *BuySListNode(SLDataType data);
void SListPushBack(SList *list, SLDataType data);

//尾删
void SListPopBack(SList *list);

//查找
SListNode* SListFind(SList* list, SLDataType data);

//在pos这一个结点的后面插入新结点
void SListInsertAfter(SListNode *pos, SLDataType data);

//删除pos这一个结点，指向后面的结点(pos不是最后一个结点)
void SListEraseAfter(SListNode *pos);

//删除第一个遇到data数据的结点
void SListRemove(SList *list, SLDataType data);