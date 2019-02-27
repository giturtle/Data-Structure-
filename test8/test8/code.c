#include <stdio.h>
#include <stdlib.h>

//����һ����������������е�����k����㣬ֻ�ܱ���һ������
//< �Ⱥ�ָ�뷨 >
//����ָ���ͷ��㿪ʼ���ÿ�ָ������ k ����һ��ͬʱ�ƶ�����ָ�뵽���β����ʱ��ָ�봦�ڵ����� k �����

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
	//1. �ÿ�ָ��������ƶ� k ��	
	while (k--) {
		if (pFast == NULL) {		//(k ���ܴ��������нڵ�ĸ���)
			return NULL;
		}
		pFast = pFast->next;
	}
	//2. �ÿ���ָ��ͬʱ����ƶ���ֱ����ָ���ߵ�NULL����������㣩
	while (pFast) {
		pFast = pFast->next;
		pSlow = pSlow->next;
	}
	return pSlow;
}
