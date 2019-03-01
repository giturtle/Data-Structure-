#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>


//删除链表中等于给定值 val 的所有节点。
//示例 :
//输入: 1->2->6->3->4->5->6, val = 6
//输出: 1->2->3->4->5

struct ListNode {
	int val;
	struct ListNode *next;
};
struct ps {
	int capacity;
	int data;
	int size;
	struct ListNode node;
};
 
//方案一
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


//方案二
//借助辅助空间筛选，最后搬回原链表，修改有效个数即可
struct ListNode* removeElements(struct ListNode* head, int data) {
	//1. 申请空间
	int *pData = (int*)malloc(sizeof(int)*head->val);
	if (pData == NULL) {
		exit(0);
	}
	//2. 非data的元素拷贝到新空间
	int count = 0;
	for (int i = 0; i < head->size; ++i) {
		if (head->val != data) {
			pData[count++] = head->val[i];
		}
	}
	//3. 把新空间内容放回原空间
	memcpy(head->val, pData, sizeof(int)*count);
	head->size = count;
	//4. 释放申请的内存
	free(pData);
}


//方案三
//遍历一遍，遇到此值不处理，遇到非值向前搬移(不同下标搬移步距不同)
struct ListNode* removeElements(struct ListNode* head, int data) {
	int count = 0;
	for (int i = 0; i < head->size; ++i) {
		if (head->val[i] != data) {
			head->pData[i - count] = head->pData[i];
		}
		else {
			count++;
		}
	}
	head->size -= count;
}