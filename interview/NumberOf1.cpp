/*
����һ��������������������Ʊ�ʾ��1�ĸ��������и����ò����ʾ��
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