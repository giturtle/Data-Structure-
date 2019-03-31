class MinStack {
public:
	stack<int>  normal;
	stack<int>  min;

	/** initialize your data structure here. */
	MinStack() {

	}

	void push(int x) {
		normal.push(x);
		if (min.empty() || x <= min.top()) {
			min.push(x);
		}
		else {
			min.push(min.top());
		}
	}

	void pop() {
		normal.pop();
		min.pop();
	}

	int top() {
		return normal.top();
	}

	int getMin() {
		return min.top();
	}
};
