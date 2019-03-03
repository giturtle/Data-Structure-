#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

//�ҵ������������ཻ����ʼ�ڵ�,����һ���������

typedef struct ListNode {
	int val;
	struct ListNode *next;
}ListNode;


// ������Ҫ֪�� �� <������������> �ж��Ƿ��ཻ����
int IsCross(ListNode *headA, ListNode *headB) {
	if (headA || headB) {
		return 0;
	}
	//���������������һ����㣬�Ƚ�������㣬�����ȣ�˵���ཻ
	ListNode* pTail1 = headA;
	ListNode* pTail2 = headB;
	while (pTail1->next)
		pTail1 = pTail1->next;
	while (pTail2->next)
		pTail2 = pTail2->next;
	return pTail1 == pTail2;
}
//���������������Ҳ�������㣬Ҳ�Ͳ���ʹ���ж��ཻ����



//��ʽ�߼�
//�����ཻ��㺯��
ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
	if (headA || headB) {
		return NULL;
	}

	ListNode *pLA = headA;
	ListNode *pLB = headB;
	//1. ͳ����������
	int sizeA = 0;		
	int sizeB = 0;
	while (pLA) {
		sizeA++;
		pLA = pLA->next;
	}
	while (pLB) {
		sizeB++;
		pLB = pLB->next;
	}
	int gap = sizeA - sizeB;
	pLA = headA;
	pLB = headB;
	//2. �ó�����������ƶ� gap ��
	if (gap > 0) {
		while (gap--) {
			pLA = pLA->next;
		}
	}
	else {
		while (gap++) {
			pLB = pLB->next;
		}
	}
	//��pLA��pLBͬʱ����ƶ������������Ƿ����
	//�����ȣ�˵���ý����ǽ���
	while (pLA && pLB) {
		if (pLA == pLB) {
			return pLA;
		}
		pLA = pLA->next;
		pLB = pLB->next;
	}
	return NULL;
}



//�Ƿ����
bool HaveCycle(ListNode *head){
	//���if�ж���whileѭ���տ�ʼ�������ڴ�ͬһ����㿪ʼ������ѭ���ж�Ϊ��ͷ������ˣ�������Ҫ����һ�������ƶ�����ô��if�������ں���Ϳ�����
	ListNode *pFast = head;
	ListNode *pSlow = head;
	while (pFast && pFast->next) {
		pFast = pFast->next->next;
		pSlow = pSlow->next;
		if (pFast == pSlow) {
			return true;
		}
	}
	return false;
}