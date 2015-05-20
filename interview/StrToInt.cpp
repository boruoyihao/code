/*
将一个字符串转换成一个整数，要求不能使用字符串转换整数的库函数。如果是非法的整数字符，比如1aa3，则返回0。
*/
#include<iostream>
#include<string>
using namespace std;
class Solution {
public:
	int StrToInt(string str) {
		if (0 == str.length())
			return 0;
		int sum = 0;
		int i = 0;
		bool flag = true;
		if (str[0] == '+'){
			i=1;
		}
		else if (str[0] == '-'){
			i = 1;
			flag = false;
		}

		for (; i < str.length(); i++){
			if (str[i] >= '0'&&str[i] <= '9'){
				sum = sum * 10 + (str[i] - '0');
			}
			else{
				return 0;
			}
		}

		if (sum == INT_MIN&&flag==false)
			return sum;
		else if (sum < 0){
			return 0;
		}

		if (flag)
			return sum;
		else
			return 0 - sum;

	}
};
#if 0
int main(){
	Solution*s = new Solution;
	cout << s->StrToInt("-2147483646")<<endl;

	cout << INT_MAX +2<< endl;
	cout << INT_MIN << endl;
	
	return 0;
}
#endif