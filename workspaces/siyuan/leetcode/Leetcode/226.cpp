#include<iostream>
#include<queue>
using namespace std;

struct TreeNode {
	int val;
	TreeNode* left;
	TreeNode* right;
	TreeNode() : val(0), left(nullptr), right(nullptr) {}
	TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
	TreeNode(int x, TreeNode* left, TreeNode* right) : val(x), left(left), right(right) {}

};
//”≈ªØ∫Û
class Solution {
public:
	TreeNode* invertTree(TreeNode* root) {
		if (root == nullptr)
		{
			return root;
		}
		queue<TreeNode*> Q;
		Q.push(root);
		while (!Q.empty())
		{
			TreeNode* temp = Q.front();
			Q.pop();
			TreeNode* t = temp->right;
			temp->right = temp->left;
			temp->left = t;
			if (temp->left != nullptr)
			{
				Q.push(temp->left);
			}
			if (temp->right != nullptr)
			{
				Q.push(temp->right);
			}
		}
		return root;
	}
};