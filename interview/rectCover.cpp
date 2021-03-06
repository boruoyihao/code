/*
我们可以用2*1的小矩形横着或者竖着去覆盖更大的矩形。请问用n个2*1的小矩形无重叠地覆盖一个2*n的大矩形，总共有多少种方法？
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