/*
输入两颗二叉树A，B，判断B是不是A的子结构。
*/

#include<iostream>
using namespace std;
namespace sp5{
	struct TreeNode {
		int val;
		TreeNode *left;
		TreeNode *right;
		TreeNode(int x) : val(x), left(NULL), right(NULL) {}
	};
	class Solution {
	public:
		bool HasSubtree(TreeNode* pRoot1, TreeNode* pRoot2)
		{
			if (!pRoot1 || !pRoot2)
				return false;
			bool flag = false;
			subtree(pRoot1, pRoot2, flag);
			return flag;
		}

		void subtree(TreeNode*pRoot1, TreeNode*pRoot2, bool &flag){
			if (!pRoot1)
				return;
			if (pRoot1->val == pRoot2->val){
				if (isSubtree(pRoot1, pRoot2))
					flag = true;
			}
			subtree(pRoot1->left, pRoot2, flag);
			subtree(pRoot1->right, pRoot2, flag);
		}

		bool isSubtree(TreeNode*pRoot1, TreeNode*pRoot2){
			if (!pRoot2)
				return true;
			if (!pRoot1&&pRoot2)
				return false;
			if (pRoot1->val == pRoot2->val){
				return isSubtree(pRoot1->left, pRoot2->left) && isSubtree(pRoot1->right, pRoot2->right);
			}
			else{
				return false;
			}
		}
	};

	void afterOrder(TreeNode*root){
		if (!root)
			return;
		afterOrder(root->left);
		afterOrder(root->right);
		cout << root->val << " ";
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
	using namespace sp5;
	cout << "输入第一颗树" << endl;
	TreeNode*root0 = createTree();
	cout << "输入第二颗树" << endl;
	TreeNode*root1 = createTree();
	Solution*s = new Solution;
	cout<<s->HasSubtree(root0,root1)<<endl;
	return 0;
}
#endif