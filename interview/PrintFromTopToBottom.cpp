/*
从上往下打印出二叉树的每个节点，同层节点从左至右打印。
*/

#include<iostream>
#include<vector>
#include<queue>
using namespace std;
namespace tree1{
	struct TreeNode {
		int val;
		TreeNode *left;
		TreeNode *right;
		TreeNode(int x) : val(x), left(NULL), right(NULL) {}
	};
	class Solution {
	public:
		vector<int> PrintFromTopToBottom(TreeNode *root) {
			vector<int>result;
			if (!root)
				return result;
			queue<TreeNode*>q;
			q.push(root);
			result.push_back(root->val);
			TreeNode*temp =NULL;
			while (!q.empty())
			{
				temp = q.front();
				q.pop();
				if (temp->left){
					q.push(temp->left);
					result.push_back(temp->left->val);
				}
				if (temp->right){
					q.push(temp->right);
					result.push_back(temp->right->val);
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
# if 0
int main(){
	using namespace tree1;
	TreeNode*root = createTree();
	Solution*s = new Solution;
	vector<int>result = s->PrintFromTopToBottom(root);
	for (int i = 0; i < result.size(); i++){
		cout << result[i] << " ";
	}
	cout << endl;
	return 0;
}
#endif