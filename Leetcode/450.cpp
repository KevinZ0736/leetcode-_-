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
	TreeNode* PreChild = nullptr;
	TreeNode* PreNode = nullptr;
	TreeNode* deleteNode(TreeNode* root, int key) {
		if (!root) return root;
		if (root->val == key)
		{
			TreeNode* Child = nullptr;
			if (root->left)
			{
				PreChild = root;
				Child = findLNode(PreChild->left);
				change(root, Child);

			}
			else if (root->right)
			{
				PreChild = root;
				Child = findRNode(PreChild->right);
				change(root, Child);
			}
			if (Child == root)
			{
				if (PreNode->left == root)
					PreNode->left = nullptr;
				if (PreNode->right == root)
					PreNode->right = nullptr;
			}
			delete root;
			root = nullptr;
			return Child;
		}
		else if (root->val > key)
		{
			PreNode = root;
			deleteNode(root->left, key);
			return root;
		}
		else if (root->val < key)
		{
			PreNode = root;
			deleteNode(root->right, key);
			return root;
		}
		return root;
	}

	void change(TreeNode* tar, TreeNode* Child)
	{
		if (PreNode)
		{
			if (tar->val < PreNode->val)
			{
				PreNode->left = Child;
			}
			else
			{
				PreNode->right = Child;
			}
		}
		Child->left = tar->left;
		Child->right = tar->right;
	}

	TreeNode* findRNode(TreeNode* tmp)
	{
		if (!tmp->left)
		{
			if (PreChild->left == tmp)
				PreChild->left = nullptr;
			if (PreChild->right == tmp)
				PreChild->right = nullptr;
			return tmp;
		}
		else {
			PreChild = tmp;
			return findRNode(tmp->left);
		}
	}

	TreeNode* findLNode(TreeNode* tmp)
	{
		if (!tmp->right)
		{

			if (PreChild->left == tmp)
				PreChild->left = nullptr;
			if (PreChild->right == tmp)
				PreChild->right = nullptr;
			return tmp;
		}
		else {
			PreChild = tmp;
			return findLNode(tmp->right);
		}

	}
};

int main()
{
	TreeNode* root = new TreeNode(5);
	root->left = new TreeNode(3);
	root->right = new TreeNode(6);
	root->left->left = new TreeNode(2);
	root->left->right = new TreeNode(4);
	root->right->right = new TreeNode(7);
	Solution s;
	s.deleteNode(root, 7);
}
