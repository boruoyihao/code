/*
���ǿ�����2*1��С���κ��Ż�������ȥ���Ǹ���ľ��Ρ�������n��2*1��С�������ص��ظ���һ��2*n�Ĵ���Σ��ܹ��ж����ַ�����
*/

#include<iostream>
using namespace std;
class Solution {
public:
	int rectCover(int number) {
		if (number <= 0)
			return 0;
		int num1 = 1;
		int num2 = 1;
		int sum = num1;
		for (int i = 1; i < number; i++){
			sum = num2+num1;
			num1 = num2;
			num2 = sum;
		}
		return sum;
	}
};
#if 0
int main(){
	Solution*s = new Solution;
	cout << s->rectCover(4) << endl;
	return 0;
}
#endif