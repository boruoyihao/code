/*
输入一个链表，从尾到头打印链表每个节点的值。返回新链表的头结点。
*/

#include<iostream>
#include<vector>
#include<stack>
using namespace std;
namespace s1{
	struct ListNode {
		int val;
		struct ListNode *next;
		ListNode(int x) :
			val(x), next(NULL) {
		}
	};

	class Solution {
	public:
		vector<int> printListFromTailToHead(struct ListNode* head) {
			stack<int>s;
			vector<int>v;
			if (NULL == head)
				return v;
			ListNode*p = head;
			while (p)
			{
				s.push(p->val);
				p = p->next;
			}
			while (!s.empty())
			{
				v.push_back(s.top());
				s.pop();
			}
			return v;
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
	int array[] = { 1};
	ListNode*head = createLink(array,1);
	Solution*s = new Solution;
	vector<int>v = s->printListFromTailToHead(head);
	for (int i = 0; i < v.size(); i++){
		cout << v[i] << " ";
	}
	cout << endl;
	return 0;
}
#endif