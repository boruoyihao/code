/*
一只青蛙一次可以跳上1级台阶，也可以跳上2级……它也可以跳上n级。求该青蛙跳上一个n级的台阶总共有多少种跳法。
*/
#include<iostream>
using namespace std;
class Solution {
public:
	int jumpFloorII(int number) {
		if (number < 0)
			return 0;
		int sum = 1;
		for (int i = 1; i < number; i++){
			sum = sum<<1;
		}
		return sum;
	}
};
#if 0
int main(){
	Solution*s = new Solution;
	cout << s->jumpFloorII(4) << endl;
	return 0;
}
#endif