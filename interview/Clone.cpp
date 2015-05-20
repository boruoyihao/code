/*
输入一个复杂链表（每个节点中有节点值，以及两个指针，一个指向下一个节点，另一个特殊指针指向任意一个节点）。
*/
#include<iostream>
using namespace std;
namespace tree3{
	
	struct RandomListNode {
	int label;
	struct RandomListNode *next, *random;
	RandomListNode(int x) :
		label(x), next(NULL), random(NULL) {
		}
	};

	class Solution {
	public:
		RandomListNode* Clone(RandomListNode* pHead)
		{
			if (!pHead)
				return NULL;

			RandomListNode*head = doubleClone(pHead);
			head = ajustrandom(head);
			head = getFinal(head);
			return head;
		}

		RandomListNode*doubleClone(RandomListNode*pHead){
			RandomListNode*p = pHead;
			RandomListNode*temp = NULL;
			while (p)
			{
				temp = new RandomListNode(p->label);
				temp->next = p->next;
				p->next = temp;
				p = p->next->next;
			}
			return pHead;
		}

		RandomListNode*ajustrandom(RandomListNode*pHead){
			RandomListNode*p = pHead;
			RandomListNode*pnext =NULL;
			while (p)
			{
				pnext = p->next;
				if (p->random!=NULL)
					pnext->random = p->random->next;
				else
					pnext->random = NULL;
				p = p->next->next;
			}
			return pHead;
		}

		RandomListNode*getFinal(RandomListNode*pHead){
			RandomListNode*p = pHead;
			RandomListNode*head =NULL,*q=NULL;
			RandomListNode*temp=NULL;
			while (p)
			{
				temp = p->next;
				p->next = temp->next;
				temp->next = NULL;
				p = p->next;
				if (!head){
					head = temp;
					q = head;
				}
				else{
					q->next = temp;
					q = q->next;
				}
			}
			return head;
		}
	};

	void printLink(RandomListNode*head){
		RandomListNode*p = head;
		while (p)
		{
			cout << p->label << " ";
			p = p->next;
		}
		
	}
}
#if 0
int main(){
	using namespace tree3;
	Solution*s = new Solution;
	RandomListNode*head = new RandomListNode(2);
	RandomListNode*head1 = new RandomListNode(1);
	RandomListNode*head2 = new RandomListNode(3);
	head->next = head1;
	head->random = NULL;
	head1->random = head2;
	head1->next = head2;
	head2->random = head;
	head2->next = NULL;
	RandomListNode*result = s->Clone(head);
	printLink(result);
	return 0;
}
#endif