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

	//����ϲ�ǰ�пձ��򷵻���һ��
	if (l1 == NULL) {
		return l2;
	}
	if (l2 == NULL) {
		return l1;
	}
	//��һ����㵥������
	if (pL1->val <= pL2->val) {
		pNewHead = pTailNode = pL1;
		pL1 = pL1->next;
	}
	else {
		pNewHead = pTailNode = pL2;
		pL2 = pL2->next;
	}
	while (pL1 && pL2) {
		if (pL1->val <= pL2->val) {
			pTailNode->next = pL1;
			pL1 = pL1->next;
		}
		else {
			pTailNode->next = pL2;
			pL2 = pL2->next;
		}
		pTailNode = pTailNode->next;
	}
	if (pL1) {
		pTailNode->next = pL1;
	}
	else {
		pTailNode->next = pL2;
	}
	return pNewHead;
}