/*
写一个函数，求两个整数之和，要求在函数体内不得使用+、-、*、/四则运算符号。
*/
#include<iostream>
using namespace std;


class Solution {
public:
	int Add(int num1, int num2)
	{
		do{
			int sum = num1^num2;
			int carry = (num1&num2) << 1;
			num1 = sum;
			num2 = carry;
		} while (num2 != 0);
	  return num1;
	}
};
#if 0
int main(){
	Solution*s = new Solution;
	cout << s->Add(20,5) << endl;
	return 0;
}
#endif