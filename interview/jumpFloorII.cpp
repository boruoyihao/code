/*
һֻ����һ�ο�������1��̨�ף�Ҳ��������2��������Ҳ��������n���������������һ��n����̨���ܹ��ж�����������
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