/*
һֻ����һ�ο�������1��̨�ף�Ҳ��������2���������������һ��n����̨���ܹ��ж�����������
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