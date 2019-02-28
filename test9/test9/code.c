#include <stdio.h>
#include <stdlib.h>

//��������������ϲ�Ϊһ���µ������������ء�
//��������ͨ��ƴ�Ӹ�����������������нڵ���ɵģ����ܴ����½��
//���룺1->2->4,	 1->3->4
//�����1->1->2->3->4->4
struct ListNode {
	int val;
	struct ListNode *next;
	
};
struct ListNode* mergeTwoLists(struct ListNode* l1, struct ListNode* l2) {
	struct ListNode *pNewHead = NULL;
	struct ListNode *pTailNode = NULL;
	struct ListNode *pL1 = l1;
	struct ListNode *pL2 = l2;

	//1. ����ϲ�ǰ�пձ��򷵻���һ��
	if (l1 == NULL) {
		return l2;
	}
	if (l2 == NULL) {
		return l1;
	}
	//2. ����while�߼��޷������һ����㣬�����ó�������������С�߷�����������ײ������������������ƶ�һ�����
	if (pL1->val <= pL2->val) {
		pNewHead = pTailNode = pL1;
		pL1 = pL1->next;
	}
	else {
		pNewHead = pTailNode = pL2;
		pL2 = pL2->next;
	}
	//����β��
	while (pL1 && pL2) {		//������һ����Ϊ���ˣ�ֻ����±��β������ӵ�δ��ı�ͷ����
		if (pL1->val <= pL2->val) {
			pTailNode->next = pL1;	//β���߼�
			pL1 = pL1->next;
		}
		else {
			pTailNode->next = pL2;
			pL2 = pL2->next;
		}
		pTailNode = pTailNode->next;
	}
	//ѭ������������pL1Ϊ���ˣ����pL2�����������±���档����pL2Ϊ�գ���pL1��������֮��
	if (pL1) {
		pTailNode->next = pL1;
	}
	else {
		pTailNode->next = pL2;
	}
	return pNewHead;
}