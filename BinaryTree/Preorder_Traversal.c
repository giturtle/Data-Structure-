

struct TreeNode {
	int val;
	struct TreeNode *left;
	struct TreeNode *right;
};

int *array;
int size;
//array + size = ˳���

void preorder(struct TreeNode *root) {
	if (root != NULL) {       //д��(!root)������
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