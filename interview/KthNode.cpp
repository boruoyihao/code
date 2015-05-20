/*
给定一颗二叉搜索树，请找出其中的第k大的结点。
例如， 5 / \ 3 7 /\ /\ 2 4 6 8 中，按结点数值大小顺序第三个结点的值为4。
*/

#include<iostream>
using namespace std;
namespace tree11{
	struct TreeNode {
		int val;
		TreeNode *left;
		TreeNode *right;
		TreeNode(int x) : val(x), left(NULL), right(NULL) {}
	};

	class Solution {
	public:
		TreeNode* KthNode(TreeNode* pRoot, unsigned int k)
		{
			if (k <= 0||!pRoot)
				return NULL;
			TreeNode*result = NULL;
			inorder(pRoot,k,result);
			return result;
		}

		void inorder(TreeNode*pRoot, unsigned int &k, TreeNode*&result){
			if (!pRoot)
				return;
			inorder(pRoot->left,k,result);
			if (--k == 0){
				result = pRoot;
			}
			inorder(pRoot->right, k, result);
		}

	};

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
	using namespace tree11;
	TreeNode*root = createTree();
	Solution*s = new Solution;
	TreeNode*result=s->KthNode(root,6);
	if (!result){
		cout << "NULL" << endl;
	}
	else{
		cout << result->val << endl;
	}
	return 0;
}
#endif