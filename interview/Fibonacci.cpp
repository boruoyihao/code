/*
��Ҷ�֪��쳲��������У�����Ҫ������һ������n���������쳲��������еĵ�n�
*/

#include<iostream>
using namespace std;

class Solution {
public:
	int Fibonacci(int n) {
		if (n <= 0)
			return 0;
		int num1 = 1;
		int num2 = 1;
		int sum = num1;
		for (int i = 2; i < n; i++){
			sum = num1 + num2;
			num1 = num2;
			num2 = sum;
		}
		return sum;
	}
};

#if 0
int main(){
	Solution*s = new Solution;
	cout << s->Fibonacci(6);
	return 0;
}
#endif