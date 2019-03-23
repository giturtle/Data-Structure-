#pragma once
#include <stdlib.h>
#include <assert.h>
//用单链表实现队列

typedef int QDataType;
//链表的结点
typedef struct QNode{
  QDataType val;
  struct QNode *next;
}QNode;

//队列
typedef struct Queue{
  QNode *front;   //指向链表的第一个结点，如果链表为空，等于NULL
  QNode *rear;    //指向链表的最后一个结点，如果链表为空，等于NULL
  int size;      //表示队列中数据个数(可加可不加~)
}Queue;

//初始化
void QueueInit(Queue *queue){
  queue->front = queue->rear = NULL;
  queue->size = 0;
}

//销毁
void QueueDeatroy(Queue *queue){
  QNode *next;
  QNode *cur = queue->front;
  for(;cur != NULL;cur = next){
    next = cur->next;
    free(cur);
  }
  queue->front = queue->rear = NULL;
  queue->size = 0;
}


//增删改查
//队列只存在尾插
void QueuePush(Queue *queue,QDataType val){
  //1. 申请结点
  QNode *node = (QNode*)malloc(sizeof(QNode));
  node->val = val;
  node->next = NULL;
  queue->size++;

  if(queue->rear == NULL){
    queue->front = queue->rear = node;
    return;
  }
  //2. 队尾插入元素
  queue->rear->next = node;

  //3. 更新rear
  queue->rear = node;
}


//删除
void QueuePop(Queue *queue){
  assert(queue->size > 0);

  QNode *old_front = queue->front;
  queue->front = queue->front->next;
  free(old_front);

  queue->size--;

  //当只有一个结点，删除之后，rear成为一个野指针，所以要处理一下这种情况,将rear置为NULL
  if(queue->front == NULL){
    queue->rear = NULL;
  }
}

//返回队首元素
QDataType QueuFront(const Queue *queue){
  assert(queue->size > 0);
  return queue->front->val;
}

//判断队列是否为空
int QueueEmpty(const Queue *queue){
  return queue->size == 0?1:0;
}

//返回队列元素个数
int QueueSize(const Queue *queue){
  return queue->size;
}
