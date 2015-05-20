/*
����ջ�����ݽṹ�����ڸ�������ʵ��һ���ܹ��õ�ջ��СԪ�ص�min������
*/
#include<iostream>
#include<stack>
using namespace std;
class Solution {
public:
	void push(int value) {
		s1.push(value);
		if (s2.empty()){
			s2.push(value);
		}
		else{
			int temp = s2.top();
			if (temp > value){
				s2.push(value);
			}
			else{
				s2.push(temp);
			}
		}
	}
	void pop() {
		if (s1.empty())
			return;
		s1.pop();
		s2.pop();
	}
	int top() {
		return s1.top();
	}
	int min() {
		return s2.top();
	}
private:
	stack<int>s1;
	stack<int>s2;
};

#if 0
int main(){
	Solution*s = new Solution;
	s->push(4);
	s->push(1);
	s->push(5);
	s->push(0);
	cout << s->min() << "  " << s->top() << endl;
	s->pop();
	cout << s->min() << "  " << s->top() << endl;
	s->pop();
	cout << s->min() << "  " << s->top() << endl;
	s->pop();
	cout << s->min() << "  " << s->top() << endl;
	s->pop();
	cout << s->min() << "  " << s->top() << endl;
	return 0;
}
#endif