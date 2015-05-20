/*
输入一个整数，输出该数二进制表示中1的个数。其中负数用补码表示。
*/

#include<iostream>
using namespace std;

class Solution {
public:
	int  NumberOf1(int n) {
		if (0 == n)
			return 0;
		int count = 1;
		while (n&(n-1))
		{
			n = n&(n - 1);
			count++;
		}
		return count;
	}
};
#if 0
int main(){
	Solution*s = new Solution;
	cout << s->NumberOf1(1)<<endl;
	return 0;
}
#endif