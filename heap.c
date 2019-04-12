

typedef struct Heap {
	int array[100];	// 静态顺序表
	int size;		// 数据个数
}	Heap;

void HeapInit(Heap *pH, int array[], int size) {
	assert(size <= 100);
	memcpy(pH->array, array, size * sizeof(int));
	pH->size = size;
	CreateHeap(pH->array, pH->size);
}

void AdjustUp(int tree[], int size, int child) {
	if (child == 0) {
		return;
	}

	int parent = (child - 1) / 2;
	if (tree[child] >= tree[parent]) {
		return;
	}

	int t = tree[child];
	tree[child] = tree[parent];
	tree[parent] = t;

	AdjustUp(tree, size, parent);
}

// log(n)
void HeapPush(Heap *pH, int v) {
	pH->array[pH->size++] = v;
	AdjustUp(pH->array, pH->size, pH->size - 1);
}

// O(log(n))	每次出的是当前最小值
int HeapPop(Heap *pH) {
	int v = pH->array[0];
	pH->array[0] = pH->array[pH->size - 1];
	pH->size--;
	AdjustDown(pH->array, pH->size, 0);

	return v;
}


void Test2() {
	int array[] = { 9, 5, 7, 3, 8, 4, 2, 1, 0 };
	int size = sizeof(array) / sizeof(int);

	Heap heap;
	HeapInit(&heap, array, size);

	for (int i = 0; i < 3; i++) {
		printf("%d\n", HeapPop(&heap));
	}
	printf("After pop\n");
	for (int i = 0; i < 3; i++) {
		HeapPush(&heap, i);
	}
	printf("After push\n");

	int size2 = heap.size;
	for (int i = 0; i < size2; i++) {
		printf("%d\n", HeapPop(&heap));
	}
}


// 排降序，建小堆
// 建大堆，找出最大值后，会破坏堆结构
void HeapSort(int array[], int size) {
	CreateHeap(array, size);
	for (int i = 0; i < size; i++) {
		int t = array[0];
		array[0] = array[size - 1 - i];
		array[size - 1 - i] = t;

		AdjustDown(array, size - 1 - i, 0);
	}
}

void Test3() {
	int array[] = { 9, 4, 5, 7, 3, 8, 6, 2, 4, 0, 1, 7 };
	int size = sizeof(array) / sizeof(int);

	HeapSort(array, size);

	printf("hello\n");
}
