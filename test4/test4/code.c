#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>


//ɾ�������е��ڸ���ֵ val �����нڵ㡣
//ʾ�� :
//����: 1->2->6->3->4->5->6, val = 6
//���: 1->2->3->4->5

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
 
//����һ
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


//������
//���������ռ�ɸѡ�������ԭ�����޸���Ч��������
struct ListNode* removeElements(struct ListNode* head, int data) {
	//1. ����ռ�
	int *pData = (int*)malloc(sizeof(int)*head->val);
	if (pData == NULL) {
		exit(0);
	}
	//2. ��data��Ԫ�ؿ������¿ռ�
	int count = 0;
	for (int i = 0; i < head->size; ++i) {
		if (head->val != data) {
			pData[count++] = head->val[i];
		}
	}
	//3. ���¿ռ����ݷŻ�ԭ�ռ�
	memcpy(head->val, pData, sizeof(int)*count);
	head->size = count;
	//4. �ͷ�������ڴ�
	free(pData);
}


//������
//����һ�飬������ֵ������������ֵ��ǰ����(��ͬ�±���Ʋ��಻ͬ)
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