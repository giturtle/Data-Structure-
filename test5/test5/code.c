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
	if (!head || !head->next) {		//���������
		return head;
	}
	struct ListNode* p = head, *newHead = head;
	while (head->next) {		
		//���������ָ��
		p = head->next;
		head->next = p->next;
		p->next = newHead;
		newHead = p;
	}
	return newHead;
}

