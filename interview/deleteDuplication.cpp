/*
在一个排序的链表中，存在重复的结点，请删除该链表中重复的结点，重复的结点不保留，返回链表头指针。 
例如，链表1->2->3->3->4->4->5 处理后为 1->2->5
*/
#include<iostream>
using namespace std;

namespace link7{
	struct ListNode {
		int val;
		struct ListNode *next;
		ListNode(int x) :
			val(x), next(NULL) {
		}
	};
	class Solution {
	public:
		ListNode* deleteDuplication(ListNode* pHead)
		{
			if (!pHead)
				return NULL;
			ListNode*head = new ListNode(-1);
			head->next = pHead;
			ListNode*pre = head;
			while (pre->next)
			{
				ListNode*temp = NULL;
				if (pre&&pre->next&&pre->next->next&&pre->next->val == pre->next->next->val){
					while (pre&&pre->next&&pre->next->next&&pre->next->val == pre->next->next->val)
					{
						temp = pre->next;
						pre->next = temp->next;
						delete temp;
						temp = NULL;
					}
					temp = pre->next;
					pre->next = temp->next;
					delete temp;
					temp = NULL;
				}
				else{
					pre = pre->next;
				}
			}
			ListNode*result = head->next;
			delete head;
			head = NULL;
			return result;
		}
	};

	ListNode*createLink(int array[], int n){
		ListNode*head = NULL, *p = NULL;
		for (int i = 0; i < n; i++){
			ListNode*temp = new ListNode(array[i]);
			temp->next = NULL;
			if (NULL == head){
				head = temp;
				p = head;
			}
			else{
				p->next = temp;
				p = p->next;
			}
		}
		return head;
	}

	void printLink(ListNode*head){
		ListNode*p = head;
		while (p)
		{
			cout << p->val << " ";
			p = p->next;
		}
	}
}

#if 0
int main(){
	int array[] = { 2 ,2,1};
	using namespace link7;
	ListNode*root=createLink(array,3);
	Solution*s = new Solution;
	ListNode*result=s->deleteDuplication(root);
	if (result)
		printLink(result);
	else
	{
		cout << "NULL" << endl;
	}
	return 0;
}
#endif