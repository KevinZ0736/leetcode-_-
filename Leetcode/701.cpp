#include<iostream>
using namespace std;

struct TreeNode {
	int val;
	TreeNode* left;
	TreeNode* right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}

};

class Solution {
public:
	TreeNode* pre = nullptr;

	TreeNode* insertIntoBST(TreeNode* root, int val) {
		if (!root)
		{
			if (pre)
			{
				TreeNode* NewRoot = new TreeNode(val);
				if (pre->val > val) pre->left = NewRoot;
				if (pre->val < val) pre->right = NewRoot;
			}
			return root;
		}
		else {
			if (val > root->val)
			{
				pre = root;
				insertIntoBST(root->right, val);
				return root;
			}
			else if (val < root->val)
			{
				pre = root;
				insertIntoBST(root->left, val);
				return root;
			}
			else { return root; }
		}
	}
};