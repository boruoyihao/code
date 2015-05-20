/*
把只包含因子2、3和5的数称作丑数（Ugly  ）。
例如6、8都是丑数，但14不是，因为它包含因子7。
习惯上我们把1当做是第一个丑数。求按从小到大的顺序的第N个丑数。
*/
#include<iostream>
#include<algorithm>
using namespace std;

class Solution {
public:
	int GetUglyNumber_Solution(int index) {
		if (index <= 0)
			return 0;
		int *ugly = new int[index];
		ugly[0] = 1;
		int*ugly2 = ugly;
		int*ugly3 = ugly;
		int*ugly5 = ugly;
		for (int i = 1; i < index; i++){
			int min = threemin(*ugly2 * 2, *ugly3 * 3,*ugly5*5);
			ugly[i] = min;
			while (*ugly2*2<=min)
				ugly2++;

			while (*ugly3*3<=min)
				ugly3++;

			while (*ugly5*5<=min)
				ugly5++;
		}
		int temp = ugly[index-1];
		delete ugly;
		return temp;
	}

	int threemin(int a, int b, int c){
		return min(min(a, b),min(b,c));
	}
};
#if 0
int main(){
	Solution*s = new Solution;
	cout << s->GetUglyNumber_Solution(8) << endl;
	return 0;
}
#endif