/*
��һ�������ʼ�����ɸ�Ԫ�ذᵽ�����ĩβ�����ǳ�֮Ϊ�������ת��
����һ����������������һ����ת�������ת�������СԪ�ء�
��������{3,4,5,1,2}Ϊ{1,2,3,4,5}��һ����ת�����������СֵΪ1��
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