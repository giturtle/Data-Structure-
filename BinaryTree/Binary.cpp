#include <stack>

typedef struct Node {
	char value;
	struct Node *left;
	struct Node *right;
}	Node;



void LevelOrder(Node *root) {
	if (root == NULL) {
		printf("\n");
	}

	// 启动
	std::queue<Node *> q;
	q.push(root);

	while (!q.empty()) {
		Node *front = q.front();
		q.pop();

		printf("%c ", front->value);

		if (front->left != NULL) {
			q.push(front->left);
		}

		if (front->right != NULL) {
			q.push(front->right);
		}
	}

	printf("\n");
}

bool IsComplete(Node *root) {
	std::queue<Node *> q;
	q.push(root);

	while (true) {
		Node *front = q.front();
		q.pop();

		if (front == NULL) {
			break;
		}

		// 层序遍历，空结点也进队列
		q.push(front->left);
		q.push(front->right);
	}

	// 判定队列中剩余数据是否全是 NULL
	while (!q.empty()) {
		Node *front = q.front();
		q.pop();
		if (front != NULL) {
			return false;
		}
	}
	// 所有都是 NULL
	return true;
}

void Test5() {
	char *inorder = "DBEAC";
	char *postorder = "DEBCA";
	int size = strlen(inorder);

	Node *root = buildTree2(inorder, postorder, size);

	LevelOrder(root);
	if (IsComplete(root)) {
		printf("是完全二叉树\n");
	}
	else {
		printf("不是完全二叉树\n");
	}
}



void PreOrderNoR(Node *root) {
	std::stack<Node *> s;
	Node *cur = root;

	while (cur != NULL || !s.empty()) {
		while (cur != NULL) {
			printf("%c ", cur->value);
			s.push(cur);
			cur = cur->left;
		}
		Node *top = s.top(); s.pop();
		cur = top->right;
	}
}

void InOrderNoR(Node *root) {
	std::stack<Node *> s;
	Node *cur = root;

	while (cur != NULL || !s.empty()) {
		while (cur != NULL) {
			s.push(cur);
			cur = cur->left;
		}
		Node *top = s.top(); s.pop();
		printf("%c ", top->value);
		cur = top->right;
	}
}

void PostOrderNoR(Node *root) {
	std::stack<Node *> s;
	Node *cur = root;
	Node *last = NULL;

	while (cur != NULL || !s.empty()) {
		while (cur != NULL) {
			// 第一次遇到
			s.push(cur);
			cur = cur->left;
		}


		Node *top = s.top();
		// 我不知道是第二次遇到还是第三次遇到
		if (top->right == NULL) {
			printf("%c ", top->value);
			s.pop();
			last = top;
		}
		else if (top->right == last) {
			printf("%c ", top->value);
			s.pop();
			last = top;
		}
		else {
			cur = top->right;
		}
	}
}


Node *prev = NULL;
// 保证按有序的顺序调用该函数
void NodeToDoublyLink(Node *node) {
	node->left = prev;	// node->prev = prev;
	if (prev != NULL) {
		prev->right = node;	// prev->next = node;
	}

	prev = node;
}


void InOrder(Node *root) {
	if (root != NULL) {
		InOrder(root->left);
		// 根 root
		NodeToDoublyLink(root);
		InOrder(root->right);
	}
}


void Test6() {
	char *inorder = "DBEAC";
	char *postorder = "DEBCA";
	int size = strlen(inorder);

	Node *root = buildTree2(inorder, postorder, size);

	PreOrderNoR(root);
}
