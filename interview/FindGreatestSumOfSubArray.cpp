/*
HZż������Щרҵ������������Щ�Ǽ����רҵ��ͬѧ��
��������鿪����,���ַ�����:�ڹ��ϵ�һάģʽʶ����,
������Ҫ��������������������,������ȫΪ������ʱ��,����ܺý����
,��������а�������,�Ƿ�Ӧ�ð���ĳ������,�������Աߵ��������ֲ����أ�
����:{6,-3,-2,7,-15,1,2,2},����������������Ϊ8(�ӵ�0����ʼ,����3��Ϊֹ)����᲻�ᱻ������ס��
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