#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

//找到两个单链表相交的起始节点,即第一个公共结点

typedef struct ListNode {
	int val;
	struct ListNode *next;
}ListNode;


// 首先需要知晓 ： <不带环单链表> 判断是否相交函数
int IsCross(ListNode *headA, ListNode *headB) {
	if (headA || headB) {
		return 0;
	}
	//找两个链表中最后一个结点，比较两最后结点，如果想等，说明相交
	ListNode* pTail1 = headA;
	ListNode* pTail2 = headB;
	while (pTail1->next)
		pTail1 = pTail1->next;
	while (pTail2->next)
		pTail2 = pTail2->next;
	return pTail1 == pTail2;
}
//如果链表带环，就找不到最后结点，也就不能使用判断相交函数



//正式逻辑
//返回相交结点函数
ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
	if (headA || headB) {
		return NULL;
	}

	ListNode *pLA = headA;
	ListNode *pLB = headB;
	//1. 统计两链表长度
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
	//2. 让长链表先向后移动 gap 步
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
	//让pLA与pLB同时向后移动，并检测二者是否相等
	//如果相等，说明该结点就是交点
	while (pLA && pLB) {
		if (pLA == pLB) {
			return pLA;
		}
		pLA = pLA->next;
		pLB = pLB->next;
	}
	return NULL;
}



//是否带环
bool HaveCycle(ListNode *head){
	//如果if判定在while循环刚开始，二者在从同一个起点开始，进入循环判定为真就返回真了，所以需要其中一个率先移动，那么把if条件放在后面就可以了
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