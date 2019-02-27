#include <stdio.h>
#include <stdlib.h>

//输入一个链表，输出该链表中倒数第k个结点，只能遍历一次链表
//< 先后指针法 >
//让慢指针从头结点开始，让快指针先走 k 步，一起同时移动，快指针到达表尾，此时慢指针处于倒数第 k 个结点

struct ListNode {
	int val;
	struct ListNode *next;
};

struct ListNode *FindKthToTail(struct ListNode *pHead, unsigned int k) {
	if (pHead == NULL) {
		return NULL;
	}
	struct ListNode *pFast = pHead;
	struct ListNode *pSlow = pHead;
	//1. 让快指针先向后移动 k 步	
	while (k--) {
		if (pFast == NULL) {		//(k 不能大于链表中节点的个数)
			return NULL;
		}
		pFast = pFast->next;
	}
	//2. 让快慢指针同时向后移动，直到快指针走到NULL（或者最后结点）
	while (pFast) {
		pFast = pFast->next;
		pSlow = pSlow->next;
	}
	return pSlow;
}
