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
	bool isEqual(TreeNode* A, TreeNode* B)
	{
		if ((A->val != B->val) || ((A == nullptr) && (B != nullptr)) || ((A != nullptr) && (B == nullptr)))
		{
			return false;
		}
		else if (A->val == B->val || ((A == nullptr) && (B == nullptr)))
		{
			return isEqual(A->left, B->right) && isEqual(A->right, B->left);
		}

	}

	bool isSymmetric(TreeNode* root) {
		return isEqual(root->left, root->right);
	}
};