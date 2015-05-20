/*
����һ�Ŷ�������һ����������ӡ���������н��ֵ�ĺ�Ϊ��������������·����
·������Ϊ�����ĸ���㿪ʼ����һֱ��Ҷ����������Ľ���γ�һ��·����
*/
#include<iostream>
#include<vector>
using namespace std;
namespace tree2{
	struct TreeNode {
		int val;
		TreeNode *left;
		TreeNode *right;
		TreeNode(int x) : val(x), left(NULL), right(NULL) {}
	};

	class Solution {
	public:
		vector<vector<int> > FindPath(TreeNode* root, int expectNumber) {
			vector<vector<int>>v;
			if (!root)
				return v;
			vector<int>temp;
			int sum = 0;
			FindSubPath(root, expectNumber, v,temp,0);
			return v;
		}

		void FindSubPath(TreeNode*root,int expectNumber,vector<vector<int>>&v,vector<int>temp,int sum){
			if ((!root)){
				return;
			}
			temp.push_back(root->val);
			sum += root->val;
			FindSubPath(root->left, expectNumber, v, temp,sum);
			FindSubPath(root->right,expectNumber,v,temp,sum);
			if (root->left == NULL&&root->right == NULL){
				if (sum == expectNumber)
					v.push_back(temp);
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
	void preOrder(TreeNode*root){
		if (!root)
			return;
		cout << root->val << " ";
		preOrder(root->left);
		preOrder(root->right);
	}

}
#if 0
int main(){
	using namespace tree2;
	Solution*s = new Solution;
	TreeNode*root=createTree();
	preOrder(root);
	cout << endl << endl;
	int target = 4;
	vector<vector<int>>result = s->FindPath(root,target);
	cout << "the result size="<<result.size() << endl;
	for (int i = 0; i < result.size(); i++){
		for (int j = 0; j < result[i].size(); j++){
			cout << result[i][j] << " ";
		}
		cout << endl;
	}
	cout << endl;
	return 0;
}
#endif