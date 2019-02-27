#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

//给定一个单链表，返回链表的中间结点，如果有两个中间结点则返回第二个中间结点
//		1 --> 2 --> 3 --> 4 --> 5 --> NULL ,返回结点 3
//		1 --> 2 --> 3 --> 4 --> NULL ,返回结点 3
//
//一般思路：
//1. 遍历链表，求出链表中结点的个数size
//2. 找到中间结点 size/2，pCur从链表的第一个结点的位置开始，向后移动 size/2 步
//
//但是要求：只能遍历一次链表
//所以使用：< 快慢指针法 >: pSlow步距为1，pFast步距为2，同一起点，pFast到头，pSlow就在中间
struct ListNode {
	int val;
	struct ListNode *next;
};

struct ListNode* middleNode(struct ListNode* head) {
	assert(head);
	struct ListNode *pFast = head;
	struct ListNode *pSlow = head;
	while (pFast && pFast->next) {
		pFast = pFast->next->next;
		pSlow = pSlow->next;
	}
	return pSlow;
}