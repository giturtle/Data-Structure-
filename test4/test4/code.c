#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>


//ɾ�������е��ڸ���ֵ val �����нڵ㡣
//ʾ�� :
//����: 1->2->6->3->4->5->6, val = 6
//���: 1->2->3->4->5

struct ListNode {
	int val;
	struct ListNode *next;
};
 
struct ListNode* removeElements(struct ListNode* head, int val) {
	if (head == NULL) {
		return NULL;
	}
	struct ListNode *prev = head;
	struct ListNode *cur = head->next;
	while (cur != NULL) {
		if (cur->val != val) {
			prev = cur;
		}
		else {
			prev->next = cur->next;
			free(cur);
		}
		cur = prev->next;
	}
	struct ListNode *NewHead = head;
	if (head->val == val) {
		NewHead = head->next;
		free(head);
	}
	return NewHead;
}
