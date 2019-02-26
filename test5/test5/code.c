#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

//反转一个链表
//输入: 1->2->3->4->5->NULL
//输出: 5->4->3->2->1->NULL

struct ListNode {
	int val;
	struct ListNode *next;
};

//方案一
struct ListNode* reverseList(struct ListNode* head) {
	if (!head) {		//处理空链表
		return head;
	}
	struct ListNode* p = head, *newHead = head;
	while (head->next) {		
		//交换两结点指针
		p = head->next;
		head->next = p->next;
		p->next = newHead;
		newHead = p;
	}
	return newHead;
}


//方案二
struct ListNode* reverseList(struct ListNode* head) {
	if (!head || !head->next)
		return head;
	struct ListNode *pre = head, *cur = head->next, *next;
	pre->next = NULL;
	while (cur)
	{
		next = cur->next;
		cur->next = pre;
		pre = cur;
		cur = next;
	}
	return pre;
}