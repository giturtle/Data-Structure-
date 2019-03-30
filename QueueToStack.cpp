class MyStack {
public:
	queue<int>  q;

	/** Initialize your data structure here. */
	MyStack() {
	}

	/** Push element x onto stack. */
	void push(int x) {
		q.push(x);
	}

	/** Removes the element on top of the stack and returns that element. */
	int pop() {
		int size = q.size();
		for (int i = 0; i < size - 1; i++) {
			int v = q.front();
			q.pop();
			q.push(v);
		}

		int v = q.front();
		q.pop();
		return v;
	}

	/** Get the top element. */
	int top() {
		int size = q.size();
		for (int i = 0; i < size - 1; i++) {
			int v = q.front();
			q.pop();
			q.push(v);
		}

		int v = q.front();
		q.pop();
		q.push(v);
		return v;
	}

	/** Returns whether the stack is empty. */
	bool empty() {
		return q.empty();
	}
};
