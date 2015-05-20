/*
输入一个正整数数组，把数组里所有数字拼接起来排成一个数，打印能拼接出的所有数字中最小的一个。
例如输入数组{3，32，321}，则打印出这三个数字能排成的最小数字为321323。
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