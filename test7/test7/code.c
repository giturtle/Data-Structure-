#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

//����һ������������������м��㣬����������м����򷵻صڶ����м���
//		1 --> 2 --> 3 --> 4 --> 5 --> NULL ,���ؽ�� 3
//		1 --> 2 --> 3 --> 4 --> NULL ,���ؽ�� 3
//
//һ��˼·��
//1. ����������������н��ĸ���size
//2. �ҵ��м��� size/2��pCur������ĵ�һ������λ�ÿ�ʼ������ƶ� size/2 ��
//
//����Ҫ��ֻ�ܱ���һ������
//����ʹ�ã�< ����ָ�뷨 >: pSlow����Ϊ1��pFast����Ϊ2��ͬһ��㣬pFast��ͷ��pSlow�����м�
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