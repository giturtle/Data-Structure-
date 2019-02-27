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
	if (!head || !head->next) {		//处理空链表及单结点链表
		return head;
	}
	struct ListNode* pPre = NULL;
	struct ListNode* pCur = head;
	struct ListNode* pNext = NULL;
	while (pCur) {
		pNext = pCur->next;		//把当前结点的next保存下来
		pCur->next = pPre;
		pPre = pCur;
		pCur = pNext;
	}
	return pPre;
}


//方案二
//原链表结点< 头插 >到新链表中
struct ListNode* reverseList(struct ListNode* head) {
	struct ListNode* pNewHead = NULL;
	struct ListNode* pCur = head;

	while (pCur) {		//遍历
		head = head->next;		//记录下个节点
		pCur->next = pNewHead;
		pNewHead = pCur;
		pCur = head;
	}
	return pNewHead;
}

