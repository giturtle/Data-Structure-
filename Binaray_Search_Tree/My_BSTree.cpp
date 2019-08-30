#include <iostream>

using namespace std;

template<class K,class V>
class BSTreeNode {
public:
	pair<K, V> _kv;
	BSTreeNode<K, V>* _left;
	BSTreeNode<K, V>* _right;

	BSTreeNode(const pair<K, V>& kv)
		:_left(nullptr)
		, _right(nullptr)
		, _kv(kv) 
	{}
};

template<class K, class V>
class BSTree {
	typedef BSTreeNode<K,V> Node;
public:
	BSTree()
		:_root(nullptr)
	{}

	bool Insert(const pair<K, V>& kv) {
		if (_root == nullptr) {
			_root = new Node(kv);
			return true;
		}
		Node* parent = nullptr;
		Node* cur = _root;
		while (cur) {
			if (cur->_kv.first > kv.first) {
				parent = cur;
				cur = cur->_left;
			}
			else if (cur->_kv.first < kv.first) {
				parent = cur;
				cur = cur->_right;
			}
			else {
				if (cur->_kv.first == kv.first) {
					return false;
				}
			}
		}
		cur = new Node(kv);
		if (parent->_kv.first > kv.first) {
			parent->_left = cur;
		}
		else {
			parent->_right = cur;
		}
		return true;
	}

	Node* Find(const K& key) {
		Node* cur = _root;
		while (cur) {
			if (cur->_kv.first > key) {
				cur = cur->_left;
			}else if (cur->_kv.first < key) {
				cur = cur->_right;
			}
			else
				return cur;
		}
		return nullptr;
	}

	bool Remove(const K& key) {
		Node* parent = nullptr;
		Node* cur = _root;
		while (cur) {
			if (cur->_kv.first > key) {
				parent = cur;
				cur = cur->_left;
			}
			else if (cur->_kv.first < key) {
				parent = cur;
				cur = cur->_right;
			}
			else {
				//要删除的就是cur结点
				Node* del = cur;
				//cur有可能有：0，1，2个孩子
				if (cur->_left == nullptr) {
					if (parent == nullptr) {
						_root = cur->_right;
					}
					else {
						if (cur == parent->_left) {
							parent->_left = cur->_right;
						}
						else {
							parent->_right = cur->_right;
						}
					}
				}
				else if (cur->_right == nullptr) {
					if (parent == nullptr) {
						_root = cur->_left;
					}
					else {
						if (parent->_left == cur) {
							parent->_left = cur->_left;
						}
						else {
							parent->_right = cur->_left;
						}
					}
				}
				else {
					//先找到最左节点
					Node* rpParent = cur;
					Node* replace = cur->_right;
					while (replace->_left) {
						rpParent = replace;
						replace = replace->_left;
					}
					cur->_kv = replace->_kv;
					del = replace;

					if (replace == rpParent->_left) {
						rpParent->_left = replace->_right;
					}
					else {
						rpParent->_right = replace->_right;
					}
				}
				delete del;
				return true;
			}
		}
		return false;
	}

	void _Inorder(Node* root) {
		if (root == nullptr)
			return;
		_Inorder(root->_left);
		cout << root->_kv.first << ":" << root->_kv.second << endl;
		_Inorder(root->_right);
	}
	void Inorder() {
		_Inorder(_root);
	}

private:
	Node* _root;
};




int main(){
	BSTree<int, int> bs;
	bs.Insert(make_pair(1, 2));
	bs.Insert(make_pair(2, 3));
	bs.Insert(make_pair(4, 5));
	bs.Insert(make_pair(8, 7));
	bs.Insert(make_pair(6, 4));

	bs.Remove(2);
	bs.Remove(3);		//没有key值为3的结点~
	bs.Inorder();
  return 0;
}
