#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include "SeqList.h"

static void CheckCapacity(SeqList *seqlist){
  if(seqlist->size < seqlist->capacity){
    return;
  }
  int NewCapacity = 2 * seqlist->capacity;
  SLDataType *NewArray = (SLDataType*)malloc(sizeof(SLDataType)*NewCapacity);
  assert(NewArray);
  for(int i = 0;i < seqlist->capacity;i++){
    NewArray[i] = seqlist->arr[i];
  }
  free(seqlist->arr);
  seqlist->capacity = NewCapacity;
  seqlist->arr = NewArray;
}

void SeqListInit(SeqList *seqlist,int capacity){
  assert(seqlist != NULL);
  seqlist->arr = (SLDataType*)malloc(sizeof(SLDataType)*capacity);
  seqlist->size = 0;
}
void SeqListPushBack(SeqList *seqlist,int val) ;
void SeqListPushFront(SeqList *seqlist,int val){
  assert(seqlist != NULL);
  for(int i = seqlist->size -1;i >= 0;--i){
    seqlist->arr[i+1] = seqlist->arr[i];
  }
  seqlist->arr[0] = val;
  seqlist->size++;
}

void SeqListInsert(SeqList *seqlist,SLDataType val,int pos){
  int i = seqlist->size;
  while(i > pos){
    seqlist->arr[i] = seqlist->arr[i-1];
  }
  seqlist->arr[pos] = val;
  seqlist->size++;
}
 
void SeqListPopBack(SeqList *seqlist){
  assert(seqlist != NULL);
  assert(seqlist->size > 0);
  seqlist->size--;
}

void SeqListPopFront(SeqList *seqlist){
  for(int i = 1;i <= seqlist->size - 1;++i){
    seqlist->arr[i] = seqlist->arr[i+1];
  }
  seqlist->size--;
}

void SeqListErase(SeqList *seqlist,int pos){
  assert(seqlist != NULL);
  assert(seqlist->size > 0);
  assert(pos >= 0 && pos <= seqlist->size);
  for(int i = pos;i < seqlist->size - 1;i++){
    seqlist->arr[i] = seqlist->arr[i + 1];
  }
  seqlist->size--;
}

void SeqListRemoveAll(SeqList *seqlist,SLDataType v){
  //删除掉所有v元素
  assert(seqlist != NULL);
  int i, j;
  for(i = 0,j = 0;i < seqlist->size;i++){
    if(seqlist->arr[i] == v){
      seqlist->arr[j++] = seqlist->arr[i];
    }
  }
  seqlist->size = j;
}

