/*
HZ偶尔会拿些专业问题来忽悠那些非计算机专业的同学。
今天测试组开完会后,他又发话了:在古老的一维模式识别中,
常常需要计算连续子向量的最大和,当向量全为正数的时候,问题很好解决。
,如果向量中包含负数,是否应该包含某个负数,并期望旁边的正数会弥补它呢？
例如:{6,-3,-2,7,-15,1,2,2},连续子向量的最大和为8(从第0个开始,到第3个为止)。你会不会被他忽悠住？
*/
#include<iostream>
#include<vector>
using namespace std;
class Solution {
public:
	int FindGreatestSumOfSubArray(vector<int> array) {
		if (array.size() == 0)
			return 0;
		int*result = new int[array.size()];
		memset(result,0,4*array.size());
		result[0] = array[0];
		for (int i = 1; i < array.size(); i++){
			if (result[i - 1] + array[i]>array[i]){
				result[i] = result[i - 1] + array[i];
			}
			else{
				result[i] = array[i];
			}
		}

		int max = result[0];
		for (int i = 1; i < array.size(); i++){
			if (max < result[i]){
				max = result[i];
			}
		}
		return max;
	}
};
#if 0
int main(){
	int array[] = { 6, -3, -2, 7, -15, 1, 2, 2 };
	vector<int>v(array,array+8);
	Solution*s = new Solution;
	cout << s->FindGreatestSumOfSubArray(v);
	cout << endl;
	return 0;
}
#endif