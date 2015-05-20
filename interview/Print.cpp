/*
从上到下按层打印二叉树，同一层结点从左至右输出。每一层输出一行。
*/
#include<iostream>
#include<vector>
#include<queue>
using namespace std;
namespace tree7{
	struct TreeNode {
		int val;
		TreeNode *left;
		TreeNode *right;
		TreeNode(int x) : val(x), left(NULL), right(NULL) {}
	};

	class Solution {
	public:
		vector<vector<int> > Print(TreeNode* pRoot) {
			vector<vector<int>>result;
			if (!pRoot)
				return result;
			queue<TreeNode*>q1, q2;
			q1.push(pRoot);
			while (!q1.empty())
			{
				vector<int>v1;
				while (!q1.empty())
				{
					TreeNode*p = q1.front();
					q1.pop();
					v1.push_back(p->val);
					if (p->left){
						q2.push(p->left);
					}
					if (p->right){
						q2.push(p->right);
					}
				}
				result.push_back(v1);
				while (!q2.empty())
				{
					TreeNode*p = q2.front();
					q1.push(p);
					q2.pop();
				}
			}

			return result;
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
	using namespace tree7;
	Solution*s = new Solution;
	TreeNode*root=createTree();
	vector<vector<int>>result=s->Print(root);
	for (int i = 0; i < result.size(); i++){
		for (int j = 0; j < result[i].size(); j++){
			cout << result[i][j] << " ";
		}
		cout << endl;
	}
	return 0;
}
#endif