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
	int result;
	int depth = 0;

	void deep(TreeNode* tmp, int d)
	{
		if (!tmp->left && !tmp->right)
		{
			if (d > depth)
			{
				result = tmp->val;
				depth = d;
			}
			return;
		}
		if (tmp->left)
		{
			deep(tmp->left, ++d);
			d--;
		}
		if (tmp->right)
		{
			deep(tmp->right, ++d);
			d--;
		}

	}

	int findBottomLeftValue(TreeNode* root) {
		deep(root, 0);
		return result;
	}
};

int main()
{
	TreeNode* t1 = new TreeNode(1);
	TreeNode* t2 = new TreeNode(3);
	TreeNode* t3 = new TreeNode(4, t1, t2);
	Solution s;
	cout << s.findBottomLeftValue(t3);
}