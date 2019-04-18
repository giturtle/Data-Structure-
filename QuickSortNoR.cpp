//快排的非递归实现



#include <stack>	

void QuickSortNoR(int array[], int size) {
	std::stack<int>	stack;
	stack.push(0);			// low
	stack.push(size - 1);	// high

	while (!stack.empty()) {
		int high = stack.top();
		stack.pop();
		int low = stack.top();
		stack.pop();

		if (low >= high) {
			continue;
		}

		int pivotIdx = Partition_2(array, low, high);
		// [low, pivotIdx - 1]
		stack.push(low);
		stack.push(pivotIdx - 1);
		// [pivotIdx + 1, high]
		stack.push(pivotIdx + 1);
		stack.push(high);
	}
}
