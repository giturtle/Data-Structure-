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

ListNode* partition(ListNode* pHead, int x) {
        // write code here
        if (pHead == NULL) {
	    	return NULL;
	    }
        struct ListNode *smaller = (struct ListNode *)malloc(sizeof(ListNode)*x);
        struct ListNode *bigger = (struct ListNode *)malloc(sizeof(ListNode)*x);
        struct ListNode *cur = pHead;
        struct ListNode *smalltail = smaller;
        struct ListNode *bigtail = bigger;
        while(cur){
            if(cur->val < x){
                smalltail->next = cur;
                smalltail = cur;
            }else{
                bigtail->next = cur;
                bigtail = cur;
            }
            cur = cur->next;
        }
        smalltail->next = bigger->next;
        bigtail->next = NULL;
        return smaller->next;
}
