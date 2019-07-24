#include<iostream>
#include<string>
#include<vector>
#include<stack>
#include<queue>
#include<algorithm>

using namespace std;

struct BinaryTreeNode {
	int _data;
	BinaryTreeNode* _left;
	BinaryTreeNode* _right;
};

//打印二叉树
//	deque
void PrintFromTopToBottom1(BinaryTreeNode* pTreeRoot) {
	if (!pTreeRoot)	return;
	std::deque<BinaryTreeNode*> q;
	q.push_back(pTreeRoot);
	while (q.size()) {
		BinaryTreeNode* pNode = q.front();
		q.pop_front();
		cout << pNode->_data;
		if (pNode->_left)
			q.push_back(pNode->_left);
		if (pNode->_right)
			q.push_back(pNode->_right);
	}
}

//queue
void PrintFromTopToBottom2(BinaryTreeNode* pTreeRoot) {
	if (!pTreeRoot)	return;
	std::queue<BinaryTreeNode*> q;
	q.push(pTreeRoot);
	while (q.size()) {
		BinaryTreeNode* pNode = q.front();
		q.pop();
		cout << pNode->_data;
		if (pNode->_left)
			q.push(pNode->_left);
		if (pNode->_right)
			q.push(pNode->_right);
	}
}
