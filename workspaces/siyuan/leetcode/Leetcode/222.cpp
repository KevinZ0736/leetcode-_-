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

class Solution {
public:

	int countNodes(TreeNode* root) {
		if (root == nullptr)
		{
			return 0;
		}
		int doubleroot = 0; int singleroot = 0;
		queue<TreeNode*> tree;
		tree.emplace(root);
		while (!tree.empty())
		{
			TreeNode* tmp = tree.front();
			tree.pop();
			if (tmp->left && tmp->right)
			{
				doubleroot++;
			}
			else if (tmp->left == nullptr && tmp->right == nullptr)
			{
				break;
			}
			else if (tmp->left != nullptr && tmp->right == nullptr)
			{
				singleroot++;
				break;
			}
			tree.emplace(tmp->left);
			tree.emplace(tmp->right);
		}
		return 2 * doubleroot + singleroot + 1;

	}
};