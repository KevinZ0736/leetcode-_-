#include<iostream>
using namespace std;

struct TreeNode {

	int val;
	TreeNode* left;
	TreeNode* right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}

};

// 利用二叉搜索树的特性，数量在两节点之间的，就是公共节点
class Solution {
public:
	TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
		if (root == nullptr)
		{
			return root;
		}
		else
		{
			int high = max(p->val, q->val);
			int low = min(p->val, q->val);

			if (root->val == high || root->val == low)
			{
				return root;
			}
			else if (root->val < low)
			{
				root = lowestCommonAncestor(root->right, p, q);
			}
			else if (root->val > high)
			{
				root = lowestCommonAncestor(root->left, p, q);
			}
			else {
				return root;
			}
		}
	}
};

int main()
{

}