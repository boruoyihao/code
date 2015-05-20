/*
��ʵ��һ�������������ж�һ�Ŷ������ǲ��ǶԳƵġ�
ע�⣬���һ��������ͬ�˶������ľ�����ͬ���ģ�������Ϊ�ԳƵġ�
*/

#include<iostream>
using namespace std;

namespace tree9{
	struct TreeNode {
		int val;
		TreeNode *left;
		TreeNode *right;
		TreeNode(int x) : val(x), left(NULL), right(NULL) {}
	};

	class Solution {
	public:
		bool isSymmetrical(TreeNode* pRoot)
		{
			if (!pRoot)
				return true;
			return check(pRoot->left,pRoot->right);
		}
		bool check(TreeNode*root1, TreeNode*root2){
			if (!root1&&!root2)
				return true;
			if (!root1&&root2)
				return false;
			if (root1&&!root2)
				return false;
			if (root1->val == root2->val){
				return check(root1->left,root2->right)&&check(root1->right,root2->left);
			}
			else{
				return false;
			}
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
	using namespace tree9;
	Solution*s = new Solution;
	TreeNode*root = createTree();
	cout<<s->isSymmetrical(root)<<endl;
	return 0;
}
#endif