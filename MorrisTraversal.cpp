#include "stdafx.h"
using namespace std;

struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
	TreeNode(int x, TreeNode* l, TreeNode* r) : val(x), left(l), right(r) {}
};

void MorrisTraversal(TreeNode* root, bool preOrder = false) {
	auto curr = root;
	while (curr != nullptr) {
		if (curr->left == nullptr) {
			printf("%d->", curr->val);
			curr = curr->right;
		}
		else {
			auto pred = curr->left;
			while (pred->right != nullptr	&& pred->right != curr)
				pred = pred->right;

			if (pred->right == nullptr) {
				if(preOrder)
					printf("%d->", curr->val);
				pred->right = curr;
				curr = curr->left;
			}
			else {
				if (!preOrder)
					printf("%d->", curr->val);
				curr = curr->right;
			}
		}
	}
	printf("\n");
}

int main()
{
	auto root = new TreeNode(1, new TreeNode(2, new TreeNode(3), new TreeNode(4, new TreeNode(9), nullptr)), new TreeNode(5, new TreeNode(6), nullptr));
	MorrisTraversal(root);
  	return 0;
}

