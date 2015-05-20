/*
����ĳ��������ǰ���������������Ľ�������ؽ����ö�������
���������ǰ���������������Ľ���ж������ظ������֡�
��������ǰ���������{1,2,4,7,3,5,6,8}�������������{4,7,2,1,5,3,8,6}��
���ؽ���������������ĺ���������С�
(���������У�"��"�������ʽ���������Ĳ�α�����û�нڵ����#������)
*/

#include<iostream>
#include<vector>
using namespace std;
namespace sp4{
	struct TreeNode {
		int val;
		TreeNode *left;
		TreeNode *right;
		TreeNode(int x) : val(x), left(NULL), right(NULL) {}
	};
	class Solution {
	public:
		struct TreeNode* reConstructBinaryTree(vector<int> pre, vector<int> in) {
			if (0 == pre.size() || 0 == in.size() || pre.size() != in.size()){
				return NULL;
			}
			return getBinaryTree(pre, 0, pre.size(), in, 0, in.size());
		}

		struct TreeNode*getBinaryTree(vector<int>&pre, int start1, int end1, vector<int>&in, int start2, int end2){
			if (start2 >= end2)
				return NULL;
			int rootdata = pre[start1];
			TreeNode *root = new TreeNode(rootdata);

			int i;
			for (i = start2; i < end2; i++){
				if (in[i] == rootdata){
					break;
				}
			}
			if (i == end2)
				return NULL;

			root->left = getBinaryTree(pre, start1 + 1, start1 + i - start2, in, start2, i);
			root->right = getBinaryTree(pre, start1 + i - start2 + 1, end1, in, i + 1, end2);
			return root;
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
	Solution*s = new Solution;
	int prearray[] = { 1, 2, 4, 7,9,3,5,6 };
	vector<int>pre(prearray,prearray+8);

	int midarray[] = { 4, 9,7, 2, 1, 5, 3, 6 };
	vector<int>mid(midarray,midarray+8);
	TreeNode*root=s->reConstructBinaryTree(pre,mid);
	afterOrder(root);
	cout << endl;
	return 0;
}
#endif