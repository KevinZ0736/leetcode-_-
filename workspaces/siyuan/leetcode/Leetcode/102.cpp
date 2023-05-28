#include<iostream>
#include<vector>
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
	vector<vector<int>> levelOrder(TreeNode* root) {
		if (root == nullptr)
		{
			return;
		}
		vector<vector<int>> result;
		queue<TreeNode*> R;
		R.push(root);
		while (!R.empty())
		{
			vector<int> tmp;
			int size = R.size();
			for (int i = 0; i < size; i++)
			{
				TreeNode* temp = R.front();
				R.pop();
				tmp.emplace_back(temp->val);
				if (temp->left != nullptr)
				{
					R.push(temp->left);
				}
				if (temp->right != nullptr)
				{
					R.push(temp->right);
				}
			}
			result.emplace_back(tmp);
		}

	}
};