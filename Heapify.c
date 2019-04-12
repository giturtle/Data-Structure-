void AdjustDown(int tree[], int size, int rootIdx) {
	// 怎么判断 rootIdx 是不是叶子
	// 没有左右孩子
	// 完全二叉树，没有左孩子就一定没有右孩子
	// 判断有没有左孩子
	// 因为我们是存在数组里的，判断标准就是左孩子的下标是否数组越界
	int leftIdx = 2 * rootIdx + 1;
	int rightIdx = 2 * rootIdx + 2;
	if (leftIdx >= size) {
		// 是叶子，结束
		return;
	}

	// 不是叶子
	int minIdx = leftIdx;
	if (rightIdx < size && tree[rightIdx] < tree[leftIdx]) {
		minIdx = rightIdx;
	}

	// 最小孩子的下标就是 minIdx
	if (tree[rootIdx] <= tree[minIdx]) {
		// 最小的已经是根了，满足堆的性质，停止
		return;
	}

	int t = tree[minIdx];
	tree[minIdx] = tree[rootIdx];
	tree[rootIdx] = t;

	// 如果发生了交换，则下面的树的堆性质可能被破坏了，继续调整
	AdjustDown(tree, size, minIdx);
}

void AdjustDown2(int tree[], int size, int rootIdx) {
	// 如果是叶子，调整结束，直接返回
	if (2 * rootIdx + 1 >= size) {
		return;
	}
	// 如果不是叶子，找到最小孩子的下标
	int minIdx;
	if (2 * rootIdx + 2 >= size) {
		// 右孩子的下标数组越界了，所以没有右孩子
		minIdx = 2 * rootIdx + 1;
	}
	else if (tree[2 * rootIdx + 1] <= tree[2 * rootIdx + 2]) {
		minIdx = 2 * rootIdx + 1;
	}
	else {
		minIdx = 2 * rootIdx + 2;
	}
	// 拿最小孩子的值 和 要调整的根的值进行比较
	if (tree[rootIdx] <= tree[minIdx]) {
		// 如果根的值比较小，调整结束，直接返回
		return;
	}
	else {
		// 否则，交换根的值 和 最小孩子的值，
		int t = tree[minIdx]; 
		tree[minIdx] = tree[rootIdx];
		tree[rootIdx] = t;

		// 继续堆刚才最小孩子的下标进行调整
		AdjustDown2(tree, size, minIdx);
	}
}

// 粗略看，时间复杂度是 O(n * log(n))
// 精确算，是 O(n)
void CreateHeap(int tree[], int size) {
	// parent = (child - 1) / 2
	// 带入 (size - 2) / 2
	for (int i = (size - 2) / 2; i >= 0; i--) {
		AdjustDown(tree, size, i);
	}
}

void Test() {
	int array[] = { 6, 9, 13, 7, 1, 8, 2, 4, 5 };
	int size = sizeof(array) / sizeof(int);
	CreateHeap(array, size);

	printf("Hello World\n");
}
