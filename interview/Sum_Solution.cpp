/*
��Ŀ����
��1+2+3+...+n��Ҫ����ʹ�ó˳�����for��while��if��else��switch��case�ȹؼ��ּ������ж���䣨A?B:C����
*/
#include<iostream>
using namespace std;

class A{
public:
	A(){
		++num;
		sum += num;
	}
	static unsigned int num;
	static unsigned int sum;

	static int getSum(){
		return sum;
	}

	static void setSum(){
		num = 0;
		sum = 0;
	}
};
unsigned int A::num = 0;
unsigned int A::sum = 0;

class Solution {
public:
	int Sum_Solution(int n) {
		A::setSum();
		A *a = new A[n];
		delete []a;
		a = NULL;
		return A::getSum();
	}
};

#if 0
int main(){

	Solution*s = new Solution;
	cout << s->Sum_Solution(5)<<endl;
	return 0;
}
#endif