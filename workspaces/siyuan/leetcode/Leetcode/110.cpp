#include<iostream>
#include <assert.h>
using namespace std;

struct TreeNode {
	int val;
	TreeNode* left;
	TreeNode* right;
	TreeNode() : val(0), left(nullptr), right(nullptr) {}
	TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
	TreeNode(int x, TreeNode* left, TreeNode* right) : val(x), left(left), right(right) {}
};

class Solution {
public:
	bool IsBalanced = 1;
	int deep(TreeNode* root)
	{
		if (IsBalanced) {
			if (root == nullptr)
			{
				return 0;
			}
			else
			{
				int deepleft = deep(root->left);
				int deepright = deep(root->right);
				int min = deepleft - deepright;
				if (min * min > 1) { IsBalanced = 0; }
				return max(deepleft, deepright) + 1;

			}
		}
		else
		{
			return 0;
		}
	}

	bool isBalanced(TreeNode* root) {
		if (root == nullptr) { return false; }
		else {
			int a = deep(root);
			return IsBalanced;
		}
	}
};


void test_isBalanced() {
	Solution solution;
	TreeNode* root = new TreeNode(1);
	root->left = new TreeNode(2);
	root->right = new TreeNode(3);
	root->left->left = new TreeNode(4);
	root->left->right = new TreeNode(5);
	root->left->left->left = new TreeNode(6);
	root->left->left->right = new TreeNode(7);
	solution.isBalanced(root);
}

int main() {
	test_isBalanced();
	return 0;
}