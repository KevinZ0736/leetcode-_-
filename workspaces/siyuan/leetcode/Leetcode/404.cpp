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
	int sum = 0;
	void LeftLeaves(TreeNode* root) {
		if (!root->left && !root->right) { return; }
		if (root->left && !root->left->left && !root->left->right)
		{
			sum = sum + root->left->val;
		}
		LeftLeaves(root->left);
		LeftLeaves(root->right);
	}
	int sumOfLeftLeaves(TreeNode* root) {
		LeftLeaves(root);
		return sum;
	}
};

int main()
{
	TreeNode* r1 = new TreeNode(15);
	TreeNode* r2 = new TreeNode(7);
	TreeNode* r3 = new TreeNode(9);
	TreeNode* r4 = new TreeNode(20, r1, r2);
	TreeNode* r5 = new TreeNode(3, r3, r4);
	Solution s;
	cout << s.sumOfLeftLeaves(r5);
}