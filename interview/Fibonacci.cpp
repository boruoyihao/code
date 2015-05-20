/*
大家都知道斐波那契数列，现在要求输入一个整数n，请你输出斐波那契数列的第n项。
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