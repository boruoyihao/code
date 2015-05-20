/*
输入一个整数数组，实现一个函数来调整该数组中数字的顺序，使得所有的奇数位于数组的前半部分，
所有的偶数位于位于数组的后半部分，并保证奇数和奇数，偶数和偶数之间的相对位置不变。
*/

#include<iostream>
#include<vector>
using namespace std;
#if 0
//不保留奇书内部或者偶数内部的相对顺序
class Solution {
public:
	void reOrderArray(vector<int> &array) {
		if (array.size() <= 1)
			return;
		int start = 0;
		int end = array.size() - 1;
		while (start<end)
		{
			while (start <end&&array[start]%2==1)
				start++;
			while (start <end&&(array[end]%2==0))
				end--;
			swap(array[start],array[end]);
		}
	}

	void swap(int &data1, int &data2){
		int temp = data1;
		data1 = data2;
		data2 = temp;
	}
};
#endif
class Solution {
public:
	void reOrderArray(vector<int> &array) {
		vector<int>v;
		for (int i = 0; i < array.size(); i++){
			if (array[i]&0x1){
				v.push_back(array[i]);
			}
		}

		for (int i = 0; i < array.size(); i++){
			if ((array[i]&0x1) == 0){
				v.push_back(array[i]);
			}
		}

		for (int i = 0; i < v.size(); i++){
			array[i] = v[i];
		}
	}
};
#if 0
int main(){
	int array[] = {1,2,3,4,5,6,7,8,10};
	vector<int>v(array,array+9);
	Solution*s = new Solution;
	s->reOrderArray(v);
	for (int i = 0; i < v.size(); i++){
		cout << v[i] << " ";
	}
	cout << endl;
	return 0;
}
#endif