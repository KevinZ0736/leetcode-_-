#include<iostream>
#include<stack>
using namespace std;

struct TreeNode {
	int val;
	TreeNode* left;
	TreeNode* right;
	TreeNode(int x) :val(x), left(nullptr), right(nullptr) {}
	TreeNode(int x, TreeNode* l, TreeNode* r) :val(x), left(l), right(r) {}
};

void PlantTree(TreeNode*& tree)
{
	int val;
	if (tree == nullptr)
	{
		cin >> val;
		if (val == 0) { return; }
		tree = new TreeNode(val);
	}
	PlantTree(tree->left);
	PlantTree(tree->right);
}

//·ÇµÝ¹é±éÀú
void PreOrder(TreeNode* tree)
{
	stack<TreeNode*> NodeStack;
	if (tree != nullptr) {
		NodeStack.push(tree);
	}
	TreeNode* Temp;
	cout << "Pre:" << endl;
	while (!NodeStack.empty())
	{
		Temp = NodeStack.top();
		NodeStack.pop();
		cout << Temp->val << " ";
		if (Temp->right != nullptr)
		{
			NodeStack.push(Temp->right);
		}
		if (Temp->left != nullptr)
		{
			NodeStack.push(Temp->left);
		}
	}
	cout << endl;

}

void MidOrder(TreeNode* tree)
{
	stack<TreeNode*> NodeStack;
	cout << "Mid:" << endl;
	while (!NodeStack.empty() || tree != nullptr)
	{
		while (tree != nullptr)
		{
			NodeStack.push(tree);
			tree = tree->left;
		}
		if (!NodeStack.empty())
		{
			tree = NodeStack.top();
			cout << tree->val << " ";
			NodeStack.pop();
			tree = tree->right;
		}
	}
}

void PostOrder(TreeNode* tree)
{
	stack<TreeNode*> NodeStack;
	stack<int> TmpStack;

	if (tree != nullptr) {
		NodeStack.push(tree);
	}
	TreeNode* Temp;
	while (!NodeStack.empty())
	{
		Temp = NodeStack.top();
		NodeStack.pop();
		TmpStack.push(Temp->val);
		if (Temp->left != nullptr)
		{
			NodeStack.push(Temp->left);
		}
		if (Temp->right != nullptr)
		{
			NodeStack.push(Temp->right);
		}
	}
	cout << "Post:" << endl;
	while (!TmpStack.empty())
	{
		cout << TmpStack.top() << " ";
		TmpStack.pop();
	}
	cout << endl;
}

int main()
{
	TreeNode* root = new TreeNode(1);
	PlantTree(root);
	PreOrder(root);
	PostOrder(root);
	return 0;
}