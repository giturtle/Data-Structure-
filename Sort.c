#pragma once

#include <stdio.h>

void Swap(int array[], int i, int j) {
	int t = array[i];
	array[i] = array[j];
	array[j] = t;
}

/*插入排序*/
/*
数据越有序，速度越快
时间复杂度
最快：O(n)			已经有序
平均：O(n^2)
最慢：O(n^2)		逆序
空间复杂度：		O(1)
稳定性：稳定
*/
void InsertSort(int array[], int size) {
	for (int i = 0; i < size; i++) {
		int key = array[i];
		int j;
		// [i - 1, 0]
		for (j = i - 1; j >= 0; j--) {
			if (array[j] <= key) {
				break;
			}

			array[j + 1] = array[j];
		}

		array[j + 1] = key;
	}
}

/*希尔排序 -- 快速排序进化*/
/*
时间复杂度:
最好: O(n)
平均：O(n^1.3-1.4)
最坏: O(n^2)
空间复杂度:
O(1)
稳定性：不稳定
*/
void InsertSortWithGap(int array[], int size, int gap) {
	for (int i = 0; i < size; i++) {
		int key = array[i];
		int j;
		// [i - 1, 0]
		for (j = i - gap; j >= 0; j -= gap) {
			if (array[j] <= key) {
				break;
			}

			array[j + gap] = array[j];
		}

		array[j + gap] = key;
	}
}


void ShellSort(int array[], int size) {
	int gap = size;
	while (1) {
		gap = gap / 3 + 1;
		// gap = gap / 2;

		InsertSortWithGap(array, size, gap);

		if (gap == 1) {
			return;
		}
	}
}

/*选择排序*/
/*
直接选择
时间复杂度： O(n^2)		数据不敏感
空间复杂度: O(1)
稳定性：不稳定
*/
void SelectSort(int array[], int size) {
	for (int i = 0; i < size; i++) {
		int maxIdx = 0;
		for (int j = 0; j < size - i; j++) {
			if (array[j] > array[maxIdx]) {
				maxIdx = j;
			}
		}

		Swap(array, maxIdx, size - 1 - i);
	}
}



/*
堆排序：
O(n * log(n))		不敏感
空间复杂度			O(1)
稳定性：不稳定





void PrintArray(int array[], int size) {
	for (int i = 0; i < size; i++) {
		printf("%d ", array[i]);
	}
	printf("\n");
}


/*冒泡排序*/
/*
最好：O(n)
平均 O(n^2)
最坏 O(n^2)

空间	O(1)
稳定性 稳定
*/
void BubbleSort(int array[], int size) {
	for (int i = 0; i < size; i++) {
		int isSorted = 1;
		for (int j = 0; j < size - 1 - i; j++) {
			if (array[j] > array[j + 1]) {
				Swap(array, j, j + 1);
				isSorted = 0;
			}
		}
		if (isSorted == 1) {
			break;
		}
	}
}




void InsertSort2(int array[], int size) {
	for (int i = 0; i < size; i++) {
		// array[0, i - 1] 部分是有序的
		// 要处理的这个数是 array[i]
		// array[i + 1, size - 1] 部分是无序的

		// 我们需要在有序部分 [0, i - 1] 给 array[i] 找到合适的位置
		int pos = i;
		for (int j = 0; j <= i - 1; j++) {
			// array[j] 比 array[i] 小，说明我们还没找到合适的位置
			// array[j] 和 array[i] 相等，为了保证稳定性，我们继续前进
			if (array[j] > array[i]) {
				pos = j;
				break;
			}
		}

		// pos 就是应该放 array[i] 的位置
		// 类似顺序表的插入，把 array[i] 插入到 array[0, i - 1] 所在的顺序表的 pos 下标
		if (pos != i) {
			int key = array[i];
			// 避免数据被覆盖，我们倒着搬数据
			// k 代表的是 数据应该被放到的空间的下标
			for (int k = i; k > pos; k--) {
				array[k] = array[k - 1];
			}

			array[pos] = key;
		}
	}
}


void SelectSort2(int array[], int size) {
	for (int i = 0; i < size; i++) {
		int record = 0;	// 假设最大的数放在 array[0]
		// [size - i, size - 1] 有序的
		// [0, size - 1 - i]	无序的
		// 在无序的部分，找到最大数的下标
		for (int j = 0; j <= size - 1 - i; j++) {
			if (array[j] > array[record]) {
				record = j;
			}
		}

		// 整个无序部分都找完了，已经确定最大的
		// 把最大的数和无序部分的最后一个数进行交换
		Swap(array, record, size - 1 - i);
	}
}


void BubbleSort2(int array[], int size) {
	for (int i = 0; i < size; i++) {
		int isSorted = 1;
		// 每次冒泡，把一个最大的数挤到无序部分的最后去
		// 有序部分 [size - i, size - 1]
		// 无序部分 [0, size - 1 - i]
		// 遍历整个无序区间，挨个挤
		for (int j = 0; j < size - 1 - i; j++) {
			if (array[j] > array[j + 1]) {
				Swap(array, j, j + 1);
				isSorted = 0;
			}
		}

		// 如果遍历整个无序区间期间，一次交换都没发生，说明
		// 其实无序区间是有序的
		if (isSorted == 1) {
			return;
		}
	}
}







/*test*/


void Test() {
	int array[] = { 3, 9, 1, 4, 7, 5, 2, 8, 0, 10, 9 };
	int size = sizeof(array) / sizeof(int);

	PrintArray(array, size);
	BubbleSort2(array, size);
	PrintArray(array, size);
}


#include "高精度计时.h"

/*
完全有序
完全逆序
完全相等
完全随机
*/

int * CreateArraySorted(int size) {
	int *array = (int *)malloc(sizeof(int)* size);
	for (int i = 0; i < size; i++) {
		array[i] = rand() % size;
	}

	ShellSort(array, size);

	return array;
}

int * CreateArraySortedReverse(int size) {
	int *array = (int *)malloc(sizeof(int)* size);
	for (int i = 0; i < size; i++) {
		array[i] = rand() % size;
	}

	HeapSort(array, size);

	return array;
}

int * CreateArrayEqual(int size) {
	int key = rand() % size;
	int *array = (int *)malloc(sizeof(int)* size);
	for (int i = 0; i < size; i++) {
		array[i] = key;
	}

	return array;
}

int * CreateArrayRandom(int size) {
	int *array = (int *)malloc(sizeof(int)* size);
	for (int i = 0; i < size; i++) {
		array[i] = rand() % size;
	}

	return array;
}


