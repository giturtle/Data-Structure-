#include <stdio.h>
#include <stdlib.h>

//��һ������������У������ظ��Ľ�㣬��ɾ�����������ظ��Ľ�㣬�ظ��Ľ�㲻��������������ͷָ�롣
//1 -> 2 -> 3 -> 3 -> 4 -> 4 -> 5
//�����Ϊ 1 -> 2 -> 5

//˼·��
typedef struct ListNode {
	int val;
	struct ListNode *next;
}ListNode;
ListNode* deleteDuplication(ListNode* pHead) {
	//������ �� ֻ��һ����㣬û���ظ��ģ�ֱ�ӷ���
	if (pHead || pHead->next) {		
		return pHead;
	}

	ListNode *pPre = pHead;
	ListNode *pCur = pHead;
	ListNode *pFirst = NULL;		//��first��last����ظ�����,����ҿ�,��ɾ�Ҳ�ɾ
	ListNode *pLast = NULL;

	//1. ���ظ�������������
	while (pCur) {
		pFirst = pCur;
		pLast = pCur->next;
		while (pLast) {		//pLast��Ϊ��˵��pfirst֮���н��
			if (pCur->val != pLast->val) {		//û���ظ�������
				break;
			}
			else {		//���pFirst��pLast���,�����������
				pCur = pCur->next;
				pLast = pLast->next;
			}
		}
		//���[ pFirst , pLast )������û���ظ���Ԫ�أ�break�������
		if (pFirst->next == pLast) {		//��ΪpCur���ϸ�whileѭ���п��ܻ��ƶ��������ȱ�ʾpCurû���ƶ�
			pPre = pCur;
			pCur = pLast;	//����һ����λ�������´�ѭ��
		}
		else {	//˵��[ pFirst , pLast )���������ظ���Ԫ�أ�break����Ϊ�м����ظ�ֹͣ��whileѭ����������Ϊ�����������ظ�Ԫ�����������NULL�ظ�ֹͣ
			//2. ɾ���ظ����(ͷɾ)
			//2.1 �����ͷ���������Ҫ�ı�ͷָ��
			if (pFirst == pHead) {		
				while (pHead != pLast) {
					pHead = pHead->next;
					free(pFirst);
					pFirst = pHead;		//pFirst������һ��
				}
			}
			//2.2 ����ͷ�������
			else {			
				ListNode *pDel = pFirst;
				while (pFirst != pLast) {
					pFirst = pFirst->next;
					free(pDel);
					pDel = pFirst;
				}
				//���Ӷϵ�
				pPre->next = pLast;
				pCur = pLast;
			}
		}
	}
	return pHead;
}