/*
把一个数组最开始的若干个元素搬到数组的末尾，我们称之为数组的旋转。
输入一个递增排序的数组的一个旋转，输出旋转数组的最小元素。
例如数组{3,4,5,1,2}为{1,2,3,4,5}的一个旋转，该数组的最小值为1。
*/
#include<iostream>
#include<vector>
using namespace std;
class Solution {
public:
	int minNumberInRotateArray(vector<int> rotateArray) {
		int start = 0;
		int size = rotateArray.size();
		int end = size-1;
		if (0 == rotateArray.size())
			return 0;
		if (rotateArray[start] < rotateArray[end]){
			return rotateArray[start];
		}
		int middle;
		while (start<end)
		{
			while (start+1<size&&rotateArray[start]==rotateArray[start+1])
			{
				start++;
			}
			while (end-1>=0&&rotateArray[end-1]==rotateArray[end])
			{
				end--;
			}
			middle = (start + end)>>1;
			if (rotateArray[middle]>rotateArray[end]){
				start = middle + 1;
			}
			else if (rotateArray[middle] <=rotateArray[end]){
				end = middle;
			}
		}
		return rotateArray[start];
	}
};
#if 0
int main(){
	int array[] = { 2, 2, 2, 2, 1, 2 };
	vector<int>v(array,array+6);
	Solution*s = new Solution;
	cout << s->minNumberInRotateArray(v)<<endl;
	return 0;
}
#endif