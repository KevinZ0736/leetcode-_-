#include<iostream>
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
	bool result = false;
	void PathSum(TreeNode* tmp, int target, int& sum)
	{
		if (!tmp->left && !tmp->right && !result)
		{
			if (sum == target) { result = true; return; }
			else { return; }
		}
		if (tmp->left)
		{
			sum = sum + tmp->left->val;
			PathSum(tmp->left, target, sum);
			sum = sum - tmp->left->val;
		}
		if (tmp->right)
		{
			sum = sum + tmp->right->val;
			PathSum(tmp->right, target, sum);
			sum = sum - tmp->right->val;
		}
	}

	bool hasPathSum(TreeNode* root, int targetSum) {
		if (root)
		{
			int sum = root->val;
			PathSum(root, targetSum, sum);
		}
		return result;
	}
};