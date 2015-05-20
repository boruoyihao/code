/*
输入一个链表，反转链表后，输出反转链表后头节点
*/
#include<iostream>
#include<vector>
using namespace std;
namespace sp3{
	struct ListNode {
		int val;
		struct ListNode *next;
		ListNode(int x) :
			val(x), next(NULL) {
		}
	};
	class Solution {
	public:
		ListNode* ReverseList(ListNode* pHead) {
			if (!pHead || !pHead->next)
				return pHead;
			ListNode*p = pHead->next;
			pHead->next = NULL;
			ListNode*temp = NULL;
			while (p){
				temp = p;
				p = p->next;
				temp->next = pHead;
				pHead = temp;

			}
			return pHead;
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
# if 0
int main(){
	int array[] = {1};
	ListNode*head=createLink(array,1);
	Solution*s = new Solution;
	head=s->ReverseList(head);
	printLink(head);
	return 0;
}
#endif