/*
输入两个链表，找出它们的第一个公共结点。
*/
#include<iostream>
#include<stack>
using namespace std;
namespace Link0{
	struct ListNode {
		int val;
		struct ListNode *next;
		ListNode(int x) :
			val(x), next(NULL) {
		}
	};
	class Solution {
	public:
		ListNode* FindFirstCommonNode(ListNode *pHead1, ListNode *pHead2) {
			if (!pHead1 || !pHead2)
				return NULL;
			stack<ListNode*>s1;
			stack<ListNode*>s2;
			ListNode*p1 = pHead1;
			while (p1)
			{
				s1.push(p1);
				p1 = p1->next;
			}

			ListNode*p2 = pHead2;
			while (p2)
			{
				s2.push(p2);
				p2 = p2->next;
			}
			if (s1.top() != s2.top())
				return NULL;
			ListNode*p = NULL;
			while (!s1.empty()&&!s2.empty())
			{
				if (s1.top() == s2.top()){
					p = s1.top();
					s1.pop();
					s2.pop();
				}
				else{
					break;
				}
			}
			return p;
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
	using namespace Link0;
	int array[] = { 1, 2, 3, 4, 5, 6, 7 };
	ListNode*h1 = createLink(array,7);

	int array1[] = { 90, 43 };
	ListNode*h2 = createLink(array1,2);

	int array3[] = { 5, 6, 7, 8 };
	ListNode*h3 = createLink(array3,4);

	h2->next = h1;
	h3->next = h1;
	Solution*s = new Solution;
	ListNode*result=s->FindFirstCommonNode(h3,h2);
	cout << result->val << endl;
	return 0;
}
#endif