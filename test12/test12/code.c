#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

//����һ�����������һ��ʱ�临�Ӷ�ΪO(n),����ռ临�Ӷ�ΪO(1)���㷨���ж����Ƿ�Ϊ���Ľṹ��
//����һ�������ͷָ��A���뷵��һ��boolֵ���������Ƿ�Ϊ���Ľṹ����֤������С�ڵ���900��
//1 --> 2 --> 2 --> 1



//����һ
//�����Ŀû�и������� 900���򲻿�ʹ�� <����> ����
typedef struct ListNode {
	int val;
	struct ListNode *next;
}ListNode; 
bool chkPalindrome(ListNode* A) {
	if (A == NULL) {
		return true;		//��Ҳ����Ľṹ
	}
	int *p = (int*)malloc(sizeof(int) * 900);
	if (p == NULL) {
		return false;
	}

	ListNode *pCur = A;
	//��������ÿ������Ԫ��ֵ��������
	int count = 0;
	while (pCur) {
		p[count++] = pCur->val;
		pCur = pCur->next;
	}

	int left = 0, right = count - 1;
	while (left < right) {
		if (p[left] != p[right]) {
			free(p);
			return false;
		}
		else {
			left++;
			right--;
		}
	}
	free(p);
	return true;
}


//������
//��ʹ�����飬�����м���Ƚϵ�˼·

ListNode *reverse(ListNode *pHead) {
	ListNode *pNewHead = NULL;
	ListNode *pCur = pHead;
	while (pCur) {
		pHead = pHead->next;
		pCur->next = pNewHead;
		pNewHead = pCur;
		pCur = pHead;
	}
	return pNewHead;
}

bool chkPalindrome_1(ListNode* A) {
	if (A == NULL) {
		return true;
	}
	ListNode *pFast = A;
	ListNode *pSlow = A;
	ListNode *pPreSlow = NULL;
	//1. ��������м���
	while (pFast && pFast->next) {
		pFast = pFast->next->next;
		pPreSlow = pSlow;
		pSlow = pSlow->next;
	}

	//2. �Ͽ�ǰ������,��ǰ�벿�ֵ�β�����Ϊ��
	pPreSlow->next = NULL;
	

	//3. ���ú������
	pSlow = reverse(pSlow);

	//4. ���δ�ǰ���󣬽�������ǰ��αȽϽ�㣬����Ƿ� <����>
	ListNode *pL1 = A;
	ListNode *pL2 = pSlow;
	while (pL1 && pL2) {		//�н��
		if (pL1->val != pL2->val) {
			break;
		}
		pL1 = pL1->next;
		pL2 = pL2->next;
	}

	bool ret = false;
	if (pL1 == NULL) {
		return true;
	}

	//5. ��ԭ����,���ǲ����Ŀ��Բ���ԭ��ֱ����90�� return false;
	pPreSlow->next = reverse(pSlow);

	return true;
}

