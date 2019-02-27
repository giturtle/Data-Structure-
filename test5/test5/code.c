#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

//��תһ������
//����: 1->2->3->4->5->NULL
//���: 5->4->3->2->1->NULL

struct ListNode {
	int val;
	struct ListNode *next;
};


//����һ
struct ListNode* reverseList(struct ListNode* head) {
	if (!head || !head->next) {		//������������������
		return head;
	}
	struct ListNode* pPre = NULL;
	struct ListNode* pCur = head;
	struct ListNode* pNext = NULL;
	while (pCur) {
		pNext = pCur->next;		//�ѵ�ǰ����next��������
		pCur->next = pPre;
		pPre = pCur;
		pCur = pNext;
	}
	return pPre;
}


//������
//ԭ������< ͷ�� >����������
struct ListNode* reverseList(struct ListNode* head) {
	struct ListNode* pNewHead = NULL;
	struct ListNode* pCur = head;

	while (pCur) {		//����
		head = head->next;		//��¼�¸��ڵ�
		pCur->next = pNewHead;
		pNewHead = pCur;
		pCur = head;
	}
	return pNewHead;
}

