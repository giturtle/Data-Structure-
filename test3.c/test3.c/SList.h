#pragma once

// <��ͷ�����򡢷�ѭ������> �� ɾ �� �� ��ʵ�֣�

typedef int SLDataType;		//single list 

//����������ÿһ��"���" �Ľṹ��
typedef struct SListNode {
	SLDataType data;
	struct SListNode *next;
}SListNode;

//����"����" �Ľṹ��
typedef struct SList {
	struct SListNode *first;	//ָ�������һ������ָ��
}SList;


//***************************************
//****			�������			 ****
//***************************************
//****			���ܿ�ʼ			 ****
//***************************************


//��ʼ��������
void SListInit(SList *list);
void SListDestroy(SList *list);

//��ӡ
void SListPrint(SList *list);

//��ɾ�Ĳ�
//ͷ��
void SListPushFront(SList *list, SLDataType data);

//ͷɾ
void SListPopFront(SList *list);

//β��
SListNode *BuySListNode(SLDataType data);
void SListPushBack(SList *list, SLDataType data);

//βɾ
void SListPopBack(SList *list);

//����
SListNode* SListFind(SList* list, SLDataType data);

//��pos��һ�����ĺ�������½��
void SListInsertAfter(SListNode *pos, SLDataType data);

//ɾ��pos��һ����㣬ָ�����Ľ��(pos�������һ�����)
void SListEraseAfter(SListNode *pos);

//ɾ����һ������data���ݵĽ��
void SListRemove(SList *list, SLDataType data);