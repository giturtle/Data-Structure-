/*快速排序*/
/*
时间复杂度：
	最好 O(n * log(n))
	平均 O(n * log(n))
	最坏 O(n^2)
空间复杂度：
	最好 O(log(n))
	平均 O(log(n))
	最坏 O(n)
稳定性：不稳定
*/

// 需要排序的区间是 [low, high]
void __QuickSort(int array[], int low, int high) {
	// 直到
	// 区间长度为 0
	if (low > high) {
		return;
	}
	// 或者区间长度为 1，表示区间内的数已经有序
	if (low == high) {
		return;
	}

	// 1. 找基准值，选最左边，基准值的下标是 low
	// 2. 遍历整个区间，把小的放左，大的放右，返回基准值所在下标
	int pivotIdx = Partition_3(array, low, high);
	// 3. 区间被分成三部分
	// [low, pivotIdx - 1] 小
	// [pivotIdx, pivotIdx] 有序
	// [pivotIdx + 1, high] 大
	// 分治算法，分别处理所有两个小区间
	__QuickSort(array, low, pivotIdx - 1);
	__QuickSort(array, pivotIdx + 1, high);
}


void QuickSort(int array[], int size) {
	__QuickSort(array, 0, size - 1);
}

// partiton三种方法：
// 1）Hover法
// 对数组中 [low, high] 的区间做分组
// 基准值是 array[low]

int Partition_1(int array[], int low, int high) {
	int begin = low;	// 从基准值位置开始，而不是 low + 1
	int end = high;
	int pivot = array[low];

	// (begin, end) 的区间是没有被比较过的数据
	while (begin < end) {
		// 重点: 如果基准值在左边，需要从右边开始走
		while (begin < end && array[end] >= pivot) {
			end--;
		}
		// array[end] 比基准值小了

		while (begin < end && array[begin] <= pivot) {
			begin++;
		}
		// array[begin] 比基准值大了

		// 交换 begin 和 end 下标处的数据
		Swap(array, begin, end);
	}

	// low 基准值
	// [low + 1, begin] 比基准值小
	// [begin + 1, high] 比基准值大
	// 把基准值和比它小的最后一个数交换
	Swap(array, low, begin);

	return begin;
}

//2）挖坑法
// 对数组中 [low, high] 的区间做分组
// 基准值是 array[low]

int Partition_2(int array[], int low, int high) {
	int begin = low;	// 从基准值位置开始，而不是 low + 1
	int end = high;
	int pivot = array[low];	// begin 是坑的下标

	// (begin, end) 的区间是没有被比较过的数据
	while (begin < end) {
		// 重点: 如果基准值在左边，需要从右边开始走
		while (begin < end && array[end] >= pivot) {
			end--;
		}
		// array[end] 比基准值小了
		// 坑的下标是 begin
		array[begin] = array[end];
		// end 是坑的下标

		while (begin < end && array[begin] <= pivot) {
			begin++;
		}
		// array[begin] 比基准值大了
		// 坑的下标是 end
		array[end] = array[begin];
		// begin 变成坑的下标
	}

	// low 基准值
	// [low + 1, begin] 比基准值小
	// [begin + 1, high] 比基准值大
	// 把基准值和比它小的最后一个数交换
	array[begin] = pivot;

	return begin;
}

// 3）前后下标法
// 对数组中 [low, high] 的区间做分组
// 基准值是 array[low]

int Partition_3(int array[], int low, int high) {
	int d = low + 1;
	int i = low + 1;
	int pivot = array[low];
	while (i <= high) {
		if (array[i] < pivot) {
			Swap(array, d, i);
			d++;
		}
		i++;
	}

	Swap(array, d - 1, low);

	return d - 1;
}


//归并排序
/*
时间复杂度：	O(n * log(n))
空间复杂度：	O(n)
稳定性：		稳定

归并排序是 外部排序 的【首选】
*/
void Merge(int array[], int left, int mid, int right, int extra[]) {
	int i = left;	// 左边区间的下标
	int j = mid;	// 右边区间的下标
	int k = left;		// extra 的下标

	while (i < mid && j < right) {
		if (array[i] <= array[j]) {
			extra[k++] = array[i++];
		}
		else {
			extra[k++] = array[j++];
		}
	}

	while (i < mid) {
		extra[k++] = array[i++];
	}

	while (j < right) {
		extra[k++] = array[j++];
	}

	// 把 extra 的数据移回来
	for (int x = left; x < right; x++) {
		array[x] = extra[x];
	}
}


// [left, right)
void __MergeSort(int array[], int left, int right, int extra[]) {
	// 直到
	// size == 1	[3, 4)
	if (right == left + 1) {
		return;
	}
	// size == 0
	if (right <= left) {
		return;
	}

	// 1. 把数组平均分成两部分
	int mid = left + (right - left) / 2;
	// [left, mid)
	// [mid, right)
	// 2. 分治算法，排序左右两部分
	__MergeSort(array, left, mid, extra);
	__MergeSort(array, mid, right, extra);

	// 3. 合并两个有序数组
	// [left, mid)	[mid, right)
	Merge(array, left, mid, right, extra);
}


void MergeSort(int array[], int size) {
	int *extra = (int *)malloc(sizeof(int)* size);
	__MergeSort(array, 0, size, extra);
	free(extra);
}

//**测试代码**
void Test() {
	int array[] = { 3, 9, 1, 4, 7, 5, 2, 8, 0, 10, 9 };
	int size = sizeof(array) / sizeof(int);

	PrintArray(array, size);
	xxx_Sort(array, size);
	PrintArray(array, size);
}
