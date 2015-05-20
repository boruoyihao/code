/*
输入一个链表，输出该链表中倒数第k个结点。
*/

#include<iostream>
using namespace std;
namespace s2{
	struct ListNode {
		int val;
		struct ListNode *next;
		ListNode(int x) :
			val(x), next(NULL) {
		}
	};
	class Solution {
	public:
		ListNode* FindKthToTail(ListNode* pListHead, unsigned int k) {
			if (k <= 0 || !pListHead)
				return NULL;
			ListNode*p = pListHead;
			int count = k;
			while (p&&count)
			{
				p = p->next;
				count--;
			}
			ListNode*pre = pListHead;
			if (p == NULL&&count > 0){
				return NULL;
			}
			else{
				while (p)
				{
					p = p->next;
					pre = pre->next;
				}
			}
			return pre;

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
}
#if 0
int main(){
	int array[] = {1,2,3,4,5,6,7,8};
	ListNode*head = createLink(array,8);
	Solution*s = new Solution;
	cout << s->FindKthToTail(head,9)->val<<endl;
	return 0;
}
#endif