/*
����һ�ö��������������ö���������ת����һ�������˫������
Ҫ���ܴ����κ��µĽ�㣬ֻ�ܵ������н��ָ���ָ��
*/
#include<iostream>
using namespace std;
namespace tree4{
	struct TreeNode {
		int val;
		TreeNode *left;
		TreeNode *right;
		TreeNode(int x) : val(x), left(NULL), right(NULL) {}
	};

	class Solution {
	public:
		TreeNode* Convert(TreeNode* pRootOfTree)
		{
			if (!pRootOfTree)
				return NULL;
			TreeNode*current =NULL;
			inorder(pRootOfTree,current);
			TreeNode*p = current;
			while (p->left){
				p = p->left;
			}
			return p;
		}

		void inorder(TreeNode*pRootOfTree,TreeNode*&current){
			if (!pRootOfTree)
				return;

			inorder(pRootOfTree->left,current);
			pRootOfTree->left = current;
			if (current)
				current->right = pRootOfTree;
			current = pRootOfTree;
			inorder(pRootOfTree->right,current);
		}
	};

	void print(TreeNode*head){
		TreeNode*p=head;
		while (p)
		{
			cout << p->val << " ";
			p = p->right;
		}
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
	using namespace tree4;
	Solution*s = new Solution;
	TreeNode*root = createTree();
	TreeNode*result=s->Convert(root);
	print(result);
	return 0;
}
#endif