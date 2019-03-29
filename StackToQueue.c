class MyQueue {
public:
	stack<int>  in;
	stack<int>  out;

	/** Initialize your data structure here. */
	MyQueue() {

	}

	/** Push element x to the back of queue. */
	void push(int x) {
		in.push(x);
	}

	/** Removes the element from in front of queue and returns that element. */
	int pop() {
		if (out.empty()) {
			while (!in.empty()) {
				int v = in.top();
				in.pop();
				out.push(v);
			}
		}

		int v = out.top();
		out.pop();
		return v;
	}

	/** Get the front element. */
	int peek() {
		if (out.empty()) {
			while (!in.empty()) {
				int v = in.top();
				in.pop();
				out.push(v);
			}
		}

		int v = out.top();
		return v;
	}

	/** Returns whether the queue is empty. */
	bool empty() {
		return in.empty() && out.empty();
	}
};
