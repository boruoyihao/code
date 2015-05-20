/*
������ջ��ʵ��һ�����У���ɶ��е�Push��Pop������ �����е�Ԫ��Ϊint����
*/

#include<iostream>
#include<stack>
using namespace std;
class Solution
{
public:
	void push(int node) {
		stack1.push(node);
	}

	int pop() {
		if (!stack2.empty()){
			int data = stack2.top();
			stack2.pop();
			return data;
		}
		else{
			while (!stack1.empty()){
				int temp = stack1.top();
				stack2.push(temp);
				stack1.pop();
			}
			int data = stack2.top();
			stack2.pop();
			return data;
		}
	}

private:
	stack<int> stack1;
	stack<int> stack2;
};
#if 0
int main(){
	Solution*s = new Solution;
	for (int i = 0; i < 5; i++){
		s->push(i);
	}
	for (int i = 0; i < 5; i++){
		cout << s->pop() << " ";
	}
	cout << endl;
	return 0;
}
#endif