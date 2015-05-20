/*
����һ�����������飬����������������ƴ�������ų�һ��������ӡ��ƴ�ӳ���������������С��һ����
������������{3��32��321}�����ӡ���������������ųɵ���С����Ϊ321323��
*/
#include<iostream>
#include<vector>
#include<string>
#include<sstream>
#include<algorithm>
using namespace std;
bool compare(string s1, string s2){
	string str1 = s1 + s2;
	string str2 = s2 + s1;
	return str1<str2;
}
class Solution {
public:
	string getString(int num){
		ostringstream s1;
		s1 << num;
		string s2 = s1.str();
		return s2;
	}

	string PrintMinNumber(vector<int> numbers) {
		string result = "";
		if (numbers.size() == 0){
			return result;
		}

		vector<string>num;
		for (int i = 0; i < numbers.size(); i++){
			num.push_back(getString(numbers[i]));
		}

		sort(num.begin(),num.end(),compare);

		for (int i = 0; i < num.size(); i++){
			result += num[i];
		}
		return result;
	}
};
#if 0
int main(){
	int array[] = { 3, 5, 1, 4, 2 };
	vector<int>v(array,array+5);

	Solution*s = new Solution;
	cout << s->PrintMinNumber(v);
	return 0;
}
#endif