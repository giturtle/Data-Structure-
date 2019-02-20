#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>


//13����Χ��һȦ���ӵ�һ���˿�ʼ˳�򱨺�123��������3���˳�Ȧ�ӣ��ҳ��������Ȧ���е���ԭ������ţ�Ҫ��������ʵ��
int main() {
	struct king {
		int data;
		struct king *next;
	};
	int i, m, n;
	scanf("%d %d", &n, &m);	//m:���� n:������
	struct king *p, *head, *t;
	head = (struct king*)malloc(sizeof(struct king));
	head->next = NULL;
	head->data = 1;
	p = head;	 //ѭ������
	for (i = 2; i <= n; i++) {
		t = (struct king*)malloc(sizeof(struct king));
		t->data = i;
		t->next = NULL;
		p->next = t;
		p = p->next;
	}
	p->next = head;		//ѭ������
	p = head;		 //ɾ������
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
	printf("\n���������:%d��\n", p->data);
	system("pause");
	return 0;
}



//дһ������insert��������һ����̬���������

//����һ
struct node {
	int data;
	struct node *next;
};
struct node *insert(struct node *head, struct node *p) {	//��pָ��Ľ�����������ʹ���������� 
	struct node *p1, *p2;
	if (head == NULL) {	//���ԭ����Ϊ�� 
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
		if (head == p1)		//���������ײ� 
			head = p;
		else
			p2->next = p1;	//���������м� 
	}
	else {
		p1->next = p;		//��������β���֮�� 
		p->next = NULL;
	}
	return head;
}


//������
struct student {
	long num;
	float score;
	struct student *next;
};
int n;
struct student *insert(struct student *head, struct student *stud) {
	struct student *p0, *p1, *p2;
	p1 = head;                          //ʹp1ָ���һ�����
	p0 = stud;                          //ָ��Ҫ����Ľ��
	if (head == NULL) {                    //ԭ���������ǿձ�
		head = p0; p0->next = NULL;
	}          //ʹp0ָ��Ľ����Ϊͷ���
	else {
		while ((p0->num > p1->num) && (p1->next != NULL)) {
			p2 = p1;                           //ʹ��ָ��ղ�p��ָ��Ľ��
			p1 = p1->next;
		}                    //p1����һ�����
		if (p0->num <= p1->num) {
			if (head == p1) head = p0;           //�嵽ԭ����һ�����֮ǰ
			else p2->next = p0;               //�嵽p2ָ��Ľ��֮�� 
			p0->next = p1;
		}
		else {
			p1->next = p0;
			p0->next = NULL;                  //�嵽���Ľ��֮��
		}
	}
	n++;                         //������ӣ�
	return (head);
}





//��дһ�� <�������> �ĺ���print
#define LEN sizeof(struct Student)
struct Student {
	long num;
	float score;
	struct Student *next;
};
void print(struct Student *head) {
	struct Student *p;
	printf("\n������%d�����ݼ�¼.\n", n);
	p = head;
	if (head != NULL) {
		do {
			printf("%ld %5.1lf\n", p->num, p->score);
			p = p->next;		//��pԭ����ָ��Ľ����next��ֵ����p��ʹpָ����һ�����
		} while (p != NULL);
	}
}