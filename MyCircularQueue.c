class MyCircularQueue {
public:
	int size;
	int capacity;
	int *array;

	int front;
	int rear;

	/** Initialize your data structure here. Set the size of the queue to be k. */
	MyCircularQueue(int k) {
		array = (int *)malloc(sizeof(int)* k);
		size = 0;
		capacity = k;

		front = 0;
		rear = 0;
	}

	/** Insert an element into the circular queue. Return true if the operation is successful. */
	bool enQueue(int value) {
		if (size >= capacity) {
			return false;
		}

		array[rear] = value;
		rear = (rear + 1) % capacity;
		size++;
		return true;
	}

	/** Delete an element from the circular queue. Return true if the operation is successful. */
	bool deQueue() {
		if (size <= 0) {
			return false;
		}

		size--;
		front = (front + 1) % capacity;
		return true;
	}

	/** Get the front item from the queue. */
	int Front() {
		if (size <= 0) {
			return -1;
		}
		return array[front];
	}

	/** Get the last item from the queue. */
	int Rear() {
		if (size <= 0) {
			return -1;
		}

		int index = (rear - 1 + capacity) % capacity;
		return array[index];
	}

	/** Checks whether the circular queue is empty or not. */
	bool isEmpty() {
		return size == 0;
	}

	/** Checks whether the circular queue is full or not. */
	bool isFull() {
		return size == capacity;
	}
};
