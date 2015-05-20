/*
����һ�������������е�һ����㣬���ҳ��������˳�����һ����㲢�ҷ��ء�
ע�⣬���еĽ�㲻�����������ӽ�㣬ͬʱ����ָ�򸸽���ָ�롣
*/

#include<iostream>
using namespace std;

struct TreeLinkNode {
	int val;
	struct TreeLinkNode *left;
	struct TreeLinkNode *right;
	struct TreeLinkNode *next;
	TreeLinkNode(int x) :val(x), left(NULL), right(NULL), next(NULL) {

	}
};

class Solution {
public:
	TreeLinkNode* GetNext(TreeLinkNode* pNode)
	{
		if (!pNode)
			return NULL;

		if (pNode->right){
			TreeLinkNode*p = pNode->right;
			while (p->left)
			{
				p = p->left;
			}
			return p;
		}
		else{
			if (pNode->next == NULL){
				return NULL;
			}
			if (pNode->next->left == pNode){
				return pNode->next;
			}
			else if (pNode->next->right == pNode){
				TreeLinkNode*p = pNode->next->next;
				if (p&&p->right&&p->right->right == pNode)
					return NULL;
				return p;
			}	
		}
	}
};
#if 0
int main(){
	Solution*s = new Solution;
	return 0;
}
#endif