/*
给定一个二叉树和其中的一个结点，请找出中序遍历顺序的下一个结点并且返回。
注意，树中的结点不仅包含左右子结点，同时包含指向父结点的指针。
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