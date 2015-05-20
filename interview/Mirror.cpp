/*
输入一个二叉树，输出其镜像。
*/
#include<iostream>
using namespace std;
namespace tree0{
	struct TreeNode {
		int val;
		TreeNode *left;
		TreeNode *right;
		TreeNode(int x) : val(x), left(NULL), right(NULL) {}
	};
	class Solution {
	public:
		void Mirror(TreeNode *pRoot) {
			if (!pRoot)
				return;
			TreeNode*temp = pRoot->left;
			pRoot->left = pRoot->right;
			pRoot->right = temp;
			Mirror(pRoot->left);
			Mirror(pRoot->right);

		}
	};
	void preOrder(TreeNode*root){
		if (!root)
			return;
		cout << root->val << " ";
		preOrder(root->left);
		preOrder(root->right);
	}

	TreeNode*createTree(){
		int data;
		cin >> data;
		TreeNode*temp = NULL;
		if (-1 == data)
			return NULL;
		else{
			temp = new TreeNode(data);
			temp->left = createTree();
			temp->right = createTree();
		}
		return temp;
	}
}
#if 0
int main(){
	using namespace tree0;
	TreeNode*root = createTree();
	cout << "Before OP" << endl;
	preOrder(root);
	cout << endl;
	Solution*s = new Solution;
	s->Mirror(root);
	cout << "After OP" << endl;
	preOrder(root);
	cout << endl;
	return 0;
}
#endif