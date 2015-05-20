/*
����һ���������飬ʵ��һ�����������������������ֵ�˳��ʹ�����е�����λ�������ǰ�벿�֣�
���е�ż��λ��λ������ĺ�벿�֣�����֤������������ż����ż��֮������λ�ò��䡣
*/

#include<iostream>
#include<vector>
using namespace std;
#if 0
//�����������ڲ�����ż���ڲ������˳��
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