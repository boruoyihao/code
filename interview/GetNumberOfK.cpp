/*
题目描述
统计一个数字在排序数组中出现的次数。
*/
#include<iostream>
#include<vector>
using namespace std;
class Solution {
public:
	int GetNumberOfK(vector<int> data, int k) {
		if (data.size() < 1)
			return 0;
		
		int mark=find(data,k);
		if (mark == -1)
			return 0;
		int i = mark,j=mark;
		while (i-1 >= 0 && data[i-1] == data[mark])
			i--;
		while (j +1< data.size() && data[j+1] == data[mark])
			j++;
		return j - i + 1;
	}

	int find(vector<int>data,int k){
		int start = 0;
		int end = data.size()-1;
		int middle = 0;
		while (start<=end)
		{
			middle = (start + end) >> 1;
			if (data[middle] < k){
				start = middle + 1;
			}
			else if (data[middle]>k){
				end = middle - 1;
			}
			else{
				return middle;
			}
		}
		return -1;
	}
};
# if 0
int main(){
	Solution*s = new Solution;
	int array[] = {1,2,3,4,5,6,7,8};
	vector<int>v(array,array+8);
	cout << s->GetNumberOfK(v,0);
	return 0;
}
#endif