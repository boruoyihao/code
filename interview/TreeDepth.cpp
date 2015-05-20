/*
����һ�ö����������������ȡ�
�Ӹ���㵽Ҷ������ξ����Ľ�㣨������Ҷ��㣩�γ�����һ��·�����·���ĳ���Ϊ������ȡ�
*/
#include<iostream>
using namespace std;
namespace tree5{
	struct TreeNode {
		int val;
		TreeNode *left;
		TreeNode *right;
		TreeNode(int x) : val(x), left(NULL), right(NULL) {}
	};
	class Solution {
	public:
		int TreeDepth(TreeNode* pRoot)
		{
			if (!pRoot)
				return 0;
			int left = TreeDepth(pRoot->left)+1;
			int right = TreeDepth(pRoot->right)+1;
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
	using namespace tree5;
	TreeNode*root = createTree();
	Solution*s = new Solution;
	cout<<s->TreeDepth(root)<<endl;
	return 0;
}
#endif
