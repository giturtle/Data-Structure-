#include <stdio.h>
#include <stdlib.h>

//在一个排序的链表中，存在重复的结点，请删除该链表中重复的结点，重复的结点不保留，返回链表头指针。
//1 -> 2 -> 3 -> 3 -> 4 -> 4 -> 5
//处理后为 1 -> 2 -> 5

//思路：
typedef struct ListNode {
	int val;
	struct ListNode *next;
}ListNode;
ListNode* deleteDuplication(ListNode* pHead) {
	//空链表 或 只有一个结点，没有重复的，直接返回
	if (pHead || pHead->next) {		
		return pHead;
	}

	ListNode *pPre = pHead;
	ListNode *pCur = pHead;
	ListNode *pFirst = NULL;		//用first和last标记重复区间,左闭右开,左删右不删
	ListNode *pLast = NULL;

	//1. 找重复连续结点的区间
	while (pCur) {
		pFirst = pCur;
		pLast = pCur->next;
		while (pLast) {		//pLast不为空说明pfirst之后还有结点
			if (pCur->val != pLast->val) {		//没有重复，跳出
				break;
			}
			else {		//如果pFirst和pLast相等,继续检查后面的
				pCur = pCur->next;
				pLast = pLast->next;
			}
		}
		//如果[ pFirst , pLast )区间中没有重复的元素，break跳出情况
		if (pFirst->next == pLast) {		//因为pCur在上个while循环中可能会移动，如果相等表示pCur没有移动
			pPre = pCur;
			pCur = pLast;	//后移一个单位，进行下次循环
		}
		else {	//说明[ pFirst , pLast )区间中有重复的元素，break跳出为中间结点重复停止，while循环结束跳出为整个链表都是重复元素情况，到达NULL重复停止
			//2. 删除重复结点(头删)
			//2.1 如果是头结点的情况，要改变头指针
			if (pFirst == pHead) {		
				while (pHead != pLast) {
					pHead = pHead->next;
					free(pFirst);
					pFirst = pHead;		//pFirst往后走一步
				}
			}
			//2.2 不是头结点的情况
			else {			
				ListNode *pDel = pFirst;
				while (pFirst != pLast) {
					pFirst = pFirst->next;
					free(pDel);
					pDel = pFirst;
				}
				//链接断点
				pPre->next = pLast;
				pCur = pLast;
			}
		}
	}
	return pHead;
}