#include<iostream>
#include<cassert>
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
	int maxDepth(TreeNode* root) {
		if (root == nullptr)
		{
			return  0;
		}
		else
		{
			return max(maxDepth(root->left), maxDepth(root->right)) + 1;
		}
	}
};

int main() {
	Solution solution;
	TreeNode* root = new TreeNode(1);
	root->left = new TreeNode(2);
	root->right = new TreeNode(3);
	root->left->left = new TreeNode(4);
	root->left->right = new TreeNode(5);
	assert(solution.maxDepth(root) == 3);
	std::cout << "Test passed!" << std::endl;
	return 0;
}