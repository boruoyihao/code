/*
一个链表中包含环，请找出该链表的环的入口结点。
*/

#include<iostream>
#include<map>
using namespace std;
namespace link6{

	struct ListNode {
		int val;
		struct ListNode *next;
		ListNode(int x) :
			val(x), next(NULL) {
		}
	};

	class Solution {
	public:
		ListNode* EntryNodeOfLoop(ListNode* pHead)
		{
			if (!pHead)
				return NULL;
			map<ListNode*,int>m;
			ListNode*p = pHead;
			while (p)
			{
				if (m.find(p) != m.end()){
					return p;
				}
				else{
					m.insert(pair<ListNode*,int>(p,1));
				}
				p = p->next;
			}

			return NULL;
		}

		bool check(ListNode* pHead){
			ListNode*p1 = pHead, *p2 = pHead->next;
			while (p1&&p1->next&&p2&&p2->next&&p2->next->next)
			{
				if (p1 == p2){
					break;
				}
				else{
					p1 = p1->next;
					p2 = p2->next->next;
				}
			}

			if (p1 == p2){
				return true;
			}
			else{
				return false;
			}
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
	int array[] = { 1, 2, 3, 4, 5, 6 };
	using namespace link6;
	ListNode*head = createLink(array,6);
	ListNode*p = head;
	while (p->next)
	{
		p = p->next;
	}
	p->next = head->next->next->next->next->next;
	Solution*s = new Solution;
	ListNode*result=s->EntryNodeOfLoop(head);
	if (result == NULL){
		cout << "NULL" << endl;
	}
	else{
		cout << result->val;
	}
	return 0;
}
#endif