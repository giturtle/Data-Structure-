#include <stdio.h>
#include <stdlib.h>

//编写代码，以给定值x为基准将链表分割成两部分，所有小于x的结点排在大于或等于x的结点之前
//			6 --> 1 --> 8 --> 7 --> 2 --> 3 --> NULL	(x = 5)
//[处理后]	1 --> 2 --> 3 --> 6 --> 8 --> 7 --> NULL
//给定一个链表的头指针 ListNode* pHead，请返回重新排列后的链表的头指针。注意：分割以后保持原来的数据顺序不变。

//思路：准备两个带头结点的新链表（不带头结点的也可以，但是需要额外比较判定头结点与x值），大于 x 值链接在node1之后，小于 x 值链接在node2之后，之后合并两链表
struct ListNode {
	int val;
	struct ListNode *next;
}; 

struct ListNode* partition(struct ListNode* pHead, int x) {
	if (pHead == NULL) {
		return NULL;
	}
	struct ListNode LessHead;	//头结点
	struct ListNode GreatHead;
	struct ListNode *pLessTail = &LessHead;
	struct ListNode *pGreatTail = &GreatHead;

	struct ListNode *pCur = pHead;
	//填充两个新链表
	while (pCur) {
		if (pCur->val < x) {
			pLessTail->next = pCur;
			pLessTail = pLessTail->next;
		}
		else {
			pGreatTail->next = pCur;
			pGreatTail = pGreatTail->next;
		}
		pCur = pCur->next;
	}//原链表结点处理完到达NULL,跳出循环
	pLessTail->next = GreatHead.next;		//小链表的尾结点需要链接大链表首节点之后的结点(大链表首结点我们初始设置无效,只是借助)
	pGreatTail->next = NULL;
	return LessHead.next;
}
