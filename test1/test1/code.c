#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>


//13个人围成一圈，从第一个人开始顺序报号123，凡报到3者退出圈子，找出最后留在圈子中的人原来的序号，要求用链表实现
int main() {
	struct king {
		int data;
		struct king *next;
	};
	int i, m, n;
	scanf("%d %d", &n, &m);	//m:人数 n:报号数
	struct king *p, *head, *t;
	head = (struct king*)malloc(sizeof(struct king));
	head->next = NULL;
	head->data = 1;
	p = head;	 //循环链表
	for (i = 2; i <= n; i++) {
		t = (struct king*)malloc(sizeof(struct king));
		t->data = i;
		t->next = NULL;
		p->next = t;
		p = p->next;
	}
	p->next = head;		//循环链表
	p = head;		 //删除链表
	while (p->next != p) {
		for (i = 1; i < m - 1; i++) {
			p = p->next;
		}
		struct king *tmp;
		tmp = p->next;
		p->next = p->next->next;
		p = tmp->next;
		free(tmp);
	}
	printf("\n最后生存者:%d号\n", p->data);
	system("pause");
	return 0;
}



//写一个函数insert，用来向一个动态链表插入结点

//方法一
struct node {
	int data;
	struct node *next;
};
struct node *insert(struct node *head, struct node *p) {	//将p指向的结点插入链表，并使链表保持有序 
	struct node *p1, *p2;
	if (head == NULL) {	//如果原链表为空 
		head = p;
		p->next = NULL;
		return head;
	}
	p2 = p1 = head;
	while ((p->data) > (p1->data) && (p1->next != NULL)) {
		p2 = p1;
		p1 = p1->next;
	}
	if ((p->data) <= (p1->data)) {
		p->next = p1;
		if (head == p1)		//插在链表首部 
			head = p;
		else
			p2->next = p1;	//插在链表中间 
	}
	else {
		p1->next = p;		//插在链表尾结点之后 
		p->next = NULL;
	}
	return head;
}


//方法二
struct student {
	long num;
	float score;
	struct student *next;
};
int n;
struct student *insert(struct student *head, struct student *stud) {
	struct student *p0, *p1, *p2;
	p1 = head;                          //使p1指向第一个结点
	p0 = stud;                          //指向要插入的结点
	if (head == NULL) {                    //原来的链表是空表
		head = p0; p0->next = NULL;
	}          //使p0指向的结点作为头结点
	else {
		while ((p0->num > p1->num) && (p1->next != NULL)) {
			p2 = p1;                           //使ｐ２指向刚才p１指向的结点
			p1 = p1->next;
		}                    //p1后移一个结点
		if (p0->num <= p1->num) {
			if (head == p1) head = p0;           //插到原来第一个结点之前
			else p2->next = p0;               //插到p2指向的结点之后 
			p0->next = p1;
		}
		else {
			p1->next = p0;
			p0->next = NULL;                  //插到最后的结点之后
		}
	}
	n++;                         //结点数加１
	return (head);
}





//编写一个 <输出链表> 的函数print
#define LEN sizeof(struct Student)
struct Student {
	long num;
	float score;
	struct Student *next;
};
void print(struct Student *head) {
	struct Student *p;
	printf("\n现在有%d条数据记录.\n", n);
	p = head;
	if (head != NULL) {
		do {
			printf("%ld %5.1lf\n", p->num, p->score);
			p = p->next;		//将p原来所指向的结点中next的值赋给p，使p指向下一个结点
		} while (p != NULL);
	}
}