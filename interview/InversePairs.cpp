/*
在数组中的两个数字，如果前面一个数字大于后面的数字，则这两个数字组成一个逆序对。
输入一个数组，求出这个数组中的逆序对的总数。
*/
#include<iostream>
#include<vector>
using namespace std;


class Solution {
public:
	int InversePairs(vector<int> data) {
		if (data.size() <= 1)
			return 0;
		int count = 0;
		for (int i = 0; i < data.size(); i++){
			for (int j = i + 1; j < data.size(); j++){
				if (data[i]>data[j]){
					count++;
				}
			}
		}

		return count;
	}
};


#if 0
int main(){
	Solution*s = new Solution;
	int array[] = {1,2};
	vector<int>v(array,array+2);
	cout << s->InversePairs(v)<<endl;
	return 0;
}
#endif