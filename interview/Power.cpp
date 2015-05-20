/*
给定一个double类型的浮点数base和int类型的整数exponent。求base的exponent次方。
*/

#include<iostream>
using namespace std;
class Solution {
public:
	double Power(double base, int exponent) {
		if (0 == exponent)
			return 1;
		if (0==base)
			return 0;
		if (exponent < 0){
			return 1 / pow(base, -exponent);
		}
		else{
			return pow(base, exponent);
		}
		
	}
	double power(double base, int exponent){
		if (1 == exponent)
			return base;
		double result = 1;
		result = pow(base, exponent>>1);
		result *= result;
		if (exponent & 1){
			result *= base;
		}
		return result;
	}
};
#if 0
int main(){
	Solution*s = new Solution;
	//cout << s->power(3, 2) << endl;
	cout << s->Power(0.00004,-1) << endl;
	return 0;
}
#endif