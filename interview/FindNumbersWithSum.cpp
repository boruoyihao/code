/*
��Ŀ����
����һ����������������һ������S���������в������������ǵ����ǵĺ�������S������ж�����ֵĺ͵���S������������ĳ˻���С�ġ�
�������:
��Ӧÿ�����԰����������������С���������
*/

#include<iostream>
#include<vector>
using namespace std;
class Solution {
public:
	vector<int> FindNumbersWithSum(vector<int> array, int sum) {
		vector<int>result;
		if (array.size() == 0)
			return result;
		int i = 0, j = array.size() - 1;
		int x=INT_MAX, y=1;
		while (i<j)
		{
			if (array[i] + array[j]>sum){
				j--;
				continue;
			}
			else if (array[i] + array[j] < sum){
				i++;
				continue;
			}
			else{
				if (array[i] * array[j] < x*y){
					x = array[i];
					y = array[j];
				}
				i++, j--;
				continue;
			}
		}
		if (x == INT_MAX&&y == 1)
			return result;
		result.push_back(x);
		result.push_back(y);
		return result;
	}
};

#if 0
int main(){
	Solution*s = new Solution;
	int array[] = { 1, 2, 4, 7, 11, 16 };
	vector<int>v(array,array+6);
	vector<int>result = s->FindNumbersWithSum(v,10);
	//cout << result[0] << " " << result[1]<<endl;
	return 0;
}
#endif