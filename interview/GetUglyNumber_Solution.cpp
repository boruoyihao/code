/*
��ֻ��������2��3��5��������������Ugly  ����
����6��8���ǳ�������14���ǣ���Ϊ����������7��
ϰ�������ǰ�1�����ǵ�һ���������󰴴�С�����˳��ĵ�N��������
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