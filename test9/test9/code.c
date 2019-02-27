#include <stdio.h>
#include <stdlib.h>

//将两个有序链表合并为一个新的有序链表并返回。
//新链表是通过拼接给定的两个链表的所有节点组成的，不能创建新结点
//输入：1->2->4,	 1->3->4
//输出：1->1->2->3->4->4
struct ListNode {
	int val;
	struct ListNode *next;
	
};
struct ListNode* mergeTwoLists(struct ListNode* l1, struct ListNode* l2) {
	struct ListNode *pNewHead = NULL;
	struct ListNode *pTailNode = NULL;
	struct ListNode *pL1 = l1;
	struct ListNode *pL2 = l2;

	//如果合并前有空表，则返回另一个
	if (l1 == NULL) {
		return l2;
	}
	if (l2 == NULL) {
		return l1;
	}
	//第一个结点单独处理
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