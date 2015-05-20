/*
��ʵ��һ����������֮���δ�ӡ������������һ�а��մ����ҵ�˳���ӡ��
�ڶ��㰴�մ��������˳���ӡ�������а��մ����ҵ�˳���ӡ���������Դ����ơ�
*/

#include<iostream>
#include<vector>
#include<queue>
#include<stack>
using namespace std;
namespace tree10{
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
			queue<TreeNode*>q1;
			stack<TreeNode*>s2;
			q1.push(pRoot);
			int i = 1;
			while (!q1.empty())
			{
				vector<int>v1;
				while (!q1.empty())
				{
					TreeNode*p = q1.front();
					q1.pop();
					v1.push_back(p->val);
					if (i%2==1){
						if (p->left){
							s2.push(p->left);
						}
						if (p->right){
							s2.push(p->right);
						}
					}
					else{
						if (p->right){
							s2.push(p->right);
						}

						if (p->left){
							s2.push(p->left);
						}
					}
				}
				i++;
				result.push_back(v1);
				while (!s2.empty())
				{
					TreeNode*p = s2.top();
					q1.push(p);
					s2.pop();
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
	using namespace tree10;
	Solution*s = new Solution;
	TreeNode*root = createTree();
	vector<vector<int>>result = s->Print(root);
	for (int i = 0; i < result.size(); i++){
		for (int j = 0; j < result[i].size(); j++){
			cout << result[i][j] << " ";
		}
		cout << endl;
	}
	return 0;
}
#endif