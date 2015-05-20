/*
输入两个单调递增的链表，输出两个链表合成后的链表，当然我们需要合成后的链表满足单调不减规则。
*/

#include<iostream>
using namespace std;
struct ListNode {
	int val;
	struct ListNode *next;
	ListNode(int x) :
		val(x), next(NULL) {
	}
};
class Solution {
public:
	ListNode* Merge(ListNode* pHead1, ListNode* pHead2)
	{
		ListNode*p=pHead1,*q=pHead2;
		ListNode*head=new ListNode(-1);
		ListNode*r = head;
		while (p&&q)
		{
			if (p->val < q->val){
				r->next = p;
				p = p->next;
			}
			else{
				r->next = q;
				q = q->next;
			}
			r = r->next;
		}
		if (p){
			r->next = p;
		}
		if (q){
			r->next = q;
		}
		r = head->next;
		delete head;
		head = NULL;
		return r;
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
#if 0
int main(){
	int array1[] = { 1};
	int array2[] = {2,5};
	ListNode*h1=createLink(array1,0);
	ListNode*h2 = createLink(array2,2);
	Solution*s = new Solution;
	ListNode*h3=s->Merge(h1,h2);
	printLink(h3);
	return 0;
}
#endif