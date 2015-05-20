/*
输入一棵二叉树，判断该二叉树是否是平衡二叉树。
*/
#include<iostream>
using namespace std;
namespace tree6{
	struct TreeNode {
		int val;
		TreeNode *left;
		TreeNode *right;
		TreeNode(int x) : val(x), left(NULL), right(NULL) {}
	};
	class Solution {
	public:
		bool IsBalanced_Solution(TreeNode* pRoot) {
			if (!pRoot)
				return true;
			bool flag = true;
			depth(pRoot,flag);
			return flag;
		}
		int depth(TreeNode*pRoot,bool&flag){
			if (!pRoot)
				return 0;
			int left = depth(pRoot->left,flag) + 1;
			int right = depth(pRoot->right,flag) + 1;
			if (left - right > 1 || right - left > 1)
				flag = false;
			return left > right ? left : right;
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
	using namespace tree6;
	TreeNode*root = createTree();
	Solution*s = new Solution;
	cout << s->IsBalanced_Solution(root)<<endl;
}
#endif