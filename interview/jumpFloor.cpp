/*
一只青蛙一次可以跳上1级台阶，也可以跳上2级。求该青蛙跳上一个n级的台阶总共有多少种跳法。
*/
#include<iostream>
using namespace std;
class Solution {
public:
	int jumpFloor(int number) {
		if (number < 0)
			return 0;
		int num1 = 1;
		int num2 = 1;
		int sum = num1;
		for (int i = 1; i < number; i++){
			sum =num1+num2;
			num1 = num2;
			num2 = sum;
		}
		return sum;
	}
};
#if 0
int main(){
	Solution*s = new Solution;
	cout<<s->jumpFloor(6)<<endl;
	return 0;
}
#endif