#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>


//十二、给定一个链表，每个节点包含一个额外增加的随机指针，该指针可以指向链表中的任何节点或空节点。
//要求返回这个链表的深度拷贝。【经典】
struct RandomListNode {
	int label;
	struct RandomListNode* next;
	struct RandomListNode* random;
};
struct RandomListNode *CreateNode(int label) {
	struct RandomListNode *p = (struct RandomListNode*)malloc(sizeof(struct RandomListNode));
	p->label = label;
	p->next = p->random = NULL;		//都置为空
	return p;
}
struct RandomListNode* copyRandomList(struct RandomListNode *head) {
	if (head == NULL) {
		return NULL;
	}

	//1. 复制原链表，让新的结点跟在老的结点后边
	struct RandomListNode *oldNode = head;
	while (oldNode != NULL) {
		struct RandomListNode *newNode = CreateNode(oldNode->label);
		//把老链表结点赋予新结点
		newNode->next = oldNode->next;
		//把新链表结点接在老链表结点之后
		oldNode->next = newNode;

		//老结点一次走两步才能像原链表遍历一样
		oldNode = oldNode->next->next;
	}
	//**** 老链表复制逻辑结束 ****


	//2. 处理random指针
	oldNode = head;
	while (oldNode != NULL) {
		struct RandomListNode *newNode = oldNode->next;
		if (oldNode->random != NULL) {
			newNode->random = oldNode->random->next;
			//相当于oldNode->next->random = oldNode->random->next
		}
		oldNode = oldNode->next->next;
	}


	//3. 把一个链表拆分成两个链表
	oldNode = head;
	struct RandomListNode *newHead = head->next;		//保存新链表的头指针
	while (oldNode != NULL) {
		struct RandomListNode *newNode = oldNode->next;
		oldNode->next = newNode->next;
		if (oldNode->next != NULL) {
			newNode->next = oldNode->next->next;
			//形如 1->3  2->4
		}
		else {			
			newNode->next = NULL;	//其实没必要特殊处理，因为它本身就是空指针
		}

		//oldNode->next 已经更新，所以往后走一个next单位即为原来老链表的两个单位
		oldNode = oldNode->next;
	}
	return newHead;
}
