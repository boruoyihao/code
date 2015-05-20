/*
题目描述
一个整型数组里除了两个数字之外，其他的数字都出现了两次。请写程序找出这两个只出现一次的数字。
*/
#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
	void FindNumsAppearOnce(vector<int> data, int* num1, int *num2) {
		if (data.size()<=1)
			return;
		int sum = getNum(data);
		int i = 0;
		for (; i < 32; i++){
			if (sum &0x1){
				break;
			}
			else{
				sum = sum >> 1;
			}
		}

		int mark = 1;
		mark <<= 1;
		int a = 0;
		int b = 0;
		for (int i = 0; i < data.size(); i++){
			if (data[i]&mark){
				a = a^data[i];
			}
			else{
				b = b^data[i];
			}
		}
		*num1 = a>b ? b : a;
		*num2 = a > b ? a : b;

	}

	int getNum(vector<int>data){
		int sum = 0;
		for (int i = 0; i < data.size(); i++){
			sum = sum^data[i];
		}
		return sum;
	}


};
#if 0
int main(){
	int array[] = { 1,1,3,4};
	Solution*s = new Solution;
	vector<int>v(array,array+4);
	int *num1 = new int();
	int *num2 = new int();
	s->FindNumsAppearOnce(v,num1,num2);
	cout << "num1=" << *num1 << ",num2=" << *num2 << endl;
	return 0;
}
#endif