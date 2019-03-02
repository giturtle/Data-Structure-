#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

//对于一个链表，请设计一个时间复杂度为O(n),额外空间复杂度为O(1)的算法，判断其是否为回文结构。
//给定一个链表的头指针A，请返回一个bool值，代表其是否为回文结构。保证链表长度小于等于900。
//1 --> 2 --> 2 --> 1



//方案一
//如果题目没有给出长度 900，则不可使用 <数组> 方法
typedef struct ListNode {
	int val;
	struct ListNode *next;
}ListNode; 
bool chkPalindrome(ListNode* A) {
	if (A == NULL) {
		return true;		//空也算回文结构
	}
	int *p = (int*)malloc(sizeof(int) * 900);
	if (p == NULL) {
		return false;
	}

	ListNode *pCur = A;
	//将链表中每个结点的元素值放入数组
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


//方案二
//不使用数组，逆置中间结点比较的思路

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
	//1. 找链表的中间结点
	while (pFast && pFast->next) {
		pFast = pFast->next->next;
		pPreSlow = pSlow;
		pSlow = pSlow->next;
	}

	//2. 断开前后链表,将前半部分的尾结点置为空
	pPreSlow->next = NULL;
	

	//3. 逆置后半链表
	pSlow = reverse(pSlow);

	//4. 依次从前往后，将后半段与前半段比较结点，检测是否 <回文>
	ListNode *pL1 = A;
	ListNode *pL2 = pSlow;
	while (pL1 && pL2) {		//有结点
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

	//5. 还原链表,若是不关心可以不还原，直接在90行 return false;
	pPreSlow->next = reverse(pSlow);

	return true;
}

