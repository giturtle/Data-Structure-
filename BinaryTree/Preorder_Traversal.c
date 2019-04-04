

struct TreeNode {
	int val;
	struct TreeNode *left;
	struct TreeNode *right;
};

int *array;
int size;
//array + size = 顺序表

void preorder(struct TreeNode *root) {
	if (root != NULL) {       //写成(!root)不可以
		array[size++] = root->val;
		preorder(root->left);
		preorder(root->right);
	}
}

int* preorderTraversal(struct TreeNode* root, int* returnSize) {
	array = (int*)malloc(1000000 * sizeof(int));
	size = 0;

	preorder(root);

	*returnSize = size;

	return array;
}