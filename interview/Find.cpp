/*
��һ����ά�����У�ÿһ�ж����մ����ҵ�����˳������
ÿһ�ж����մ��ϵ��µ�����˳�����������һ������������������һ����ά�����һ���������ж��������Ƿ��и�������
*/
#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
	bool Find(vector<vector<int> > array, int target) {
		bool flag = false;
		if (array.size() <= 0){
			return flag;
		}
		int line = 0,row=array[0].size()-1;
		while (line<array.size()&&row>=0)
		{
			if (array[line][row]>target){
				row--;
			}
			else if (array[line][row] < target){
				if (array[line][0] < target){
					line++;
					continue;
				}
				else if (array[line][0]>target){
					continue;
				}
				else{
					flag = true;
					break;
				}
			}
			else{
				flag = true;
				break;
			}
		}

		return flag;
	}
};
#if 0
int main(){
	vector<vector<int>>v;
	//int array1[] = {1,4,7};
	//vector<int>v1(array1,array1+3);
	//int array2[] = {2,5,8};
	//vector<int>v2(array2,array2+3);
	//int array3[] = {3,6,9};
	//vector<int>v3(array3, array3 + 3);
	//v.push_back(v1);
	//v.push_back(v2);
	//v.push_back(v3);

	int array1[] = {1};
	vector<int>v1(array1,array1+1);
	int array2[] = {2};
	vector<int>v2(array2,array2+1);
	int array3[] = {3};
	vector<int>v3(array3, array3 + 1);
	v.push_back(v1);
	v.push_back(v2);
	v.push_back(v3);
	Solution*s = new Solution;
	cout << s->Find(v,0)<<endl;
	return 0;
}
#endif