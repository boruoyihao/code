/*
�������е��������֣����ǰ��һ�����ִ��ں�������֣����������������һ������ԡ�
����һ�����飬�����������е�����Ե�������
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