#include<iostream>
#include<vector>
#include<string>
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
	void TreePath(vector<string>& result, vector<int>& Paths, TreeNode* root)
	{
		Paths.emplace_back(root->val);
		if (!root->left && !root->right)
		{
			string s;
			for (int x : Paths)
			{
				s = s + to_string(x) + "->";
			}
			s.erase(s.size() - 2);
			result.emplace_back(s);
			return;
		}
		if (root->left)
		{
			TreePath(result, Paths, root->left);
			Paths.pop_back();
		}
		if (root->right)
		{
			TreePath(result, Paths, root->right);
			Paths.pop_back();
		}
	}

	vector<string> binaryTreePaths(TreeNode* root) {
		vector<int> Paths;
		vector<string> result;
		TreePath(result, Paths, root);
		return result;
	}
};

int main()
{
	Solution s;
	TreeNode* root = new TreeNode(1);
	root->left = new TreeNode(2);
	root->right = new TreeNode(3);
	root->left->right = new TreeNode(5);
	vector<string> result = s.binaryTreePaths(root);
	cout << result.size();
}