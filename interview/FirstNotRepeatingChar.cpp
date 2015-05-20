/*
题目描述
在一个字符串(1<=字符串长度<=10000)中找到第一个只出现一次的字符。
返回:
1.字符在字符串的位置
2.当字符串长度为0时，返回-1
*/
#include<iostream>
#include<string>
using namespace std;
class Solution {
public:
	int FirstNotRepeatingChar(string str) {
		if (str.length() <= 0)
			return -1;
		int count[256];
		memset(count,0,256*sizeof(int));
		for (int i = 0; i < str.length(); i++){
			count[str[i]]++;
		}

		for (int i = 0; i < str.length(); i++){
			if (count[str[i]] == 1){
				return i;
			}
		}
		return -1;
	}
};
#if 0
int main(){
	Solution*s = new Solution;
	cout << s->FirstNotRepeatingChar("zhaolizhenaolien");
	return 0;
}
#endif