#include <stdio.h>
#include <stdlib.h>

//��д���룬�Ը���ֵxΪ��׼������ָ�������֣�����С��x�Ľ�����ڴ��ڻ����x�Ľ��֮ǰ
//			6 --> 1 --> 8 --> 7 --> 2 --> 3 --> NULL	(x = 5)
//[�����]	1 --> 2 --> 3 --> 6 --> 8 --> 7 --> NULL
//����һ�������ͷָ�� ListNode* pHead���뷵���������к�������ͷָ�롣ע�⣺�ָ��Ժ󱣳�ԭ��������˳�򲻱䡣

//˼·��׼��������ͷ��������������ͷ����Ҳ���ԣ�������Ҫ����Ƚ��ж�ͷ�����xֵ�������� x ֵ������node1֮��С�� x ֵ������node2֮��֮��ϲ�������
struct ListNode {
	int val;
	struct ListNode *next;
}; 

struct ListNode* partition(struct ListNode* pHead, int x) {
	if (pHead == NULL) {
		return NULL;
	}
	struct ListNode LessHead;	//ͷ���
	struct ListNode GreatHead;
	struct ListNode *pLessTail = &LessHead;
	struct ListNode *pGreatTail = &GreatHead;

	struct ListNode *pCur = pHead;
	//�������������
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
	}//ԭ�����㴦���굽��NULL,����ѭ��
	pLessTail->next = GreatHead.next;		//С�����β�����Ҫ���Ӵ������׽ڵ�֮��Ľ��(�������׽�����ǳ�ʼ������Ч,ֻ�ǽ���)
	pGreatTail->next = NULL;
	return LessHead.next;
}
