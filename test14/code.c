#include <stdio.h>
#include <stdlib.h>
int main(){
  void BubbleSort(int arr[],int size);
  int BinarySearch(int arr[],int size,int value);
  int BinarySearch2(int arr[],int size,int value);
  return 0;
}

int sorted;
void BubbleSort(int arr[],int size){
  for(int i = 0;i < size;i++){
    //经过上次冒泡，数组已经可能有序，所以先假设数组有序
    sorted = 1;
    //进行一次冒泡
    for(int j = 0;j < size - 1 - i;j++){
      if(arr[j] > arr[j+1]){
        int t = arr[j];
        arr[j] = arr[j+1];
        arr[j+1] = t;
        //若果发生交换，数组有序的假设不成立
        sorted = 0;
        }
    }
    //如果冒泡结束后，一次交换都没有发生，则数组已经有序
    if(sorted == 1){
     break;
    }
  }
}

int BinarySearch(int arr[],int size,int value){
  //左闭右闭区间
  int left = 0;
  int right = size - 1;
  //left 和 right 构成的区间中还有数，循环就要继续
  while(left <= right){
    int mid = left + (right - left)/2;
    if(value == arr[mid]){
      return mid;
    }
    else if(value < arr[mid]){
      right = mid - 1;
    }
    else if(value > arr[mid]){
      left = mid + 1;
    }
  }
  return -1;
}

int BinarySearch2(int arr[],int size,int value){
  //左闭右开区间
  int left = 0;
  int right = size;
  while(left < right){
    int mid = left + (right - left)/2;
    if(value == arr[mid]){
      return mid;
    }
    else if(value < arr[mid]){
      right = mid;
    }
    else if(value > arr[mid]){
      left = mid + 1;
    }
  }
  return -1;
}
