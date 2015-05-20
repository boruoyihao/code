/*
题目描述
汇编语言中有一种移位指令叫做循环左移（ROL），现在有个简单的任务，就是用字符串模拟这个指令的运算结果。
对于一个给定的字符序列S，请你把其循环左移K位后的序列输出。
例如，字符序列S=”abcXYZdef”,要求输出循环左移3位后的结果，即“XYZdefabc”。
是不是很简单？OK，搞定它！
*/
#include<iostream>
#include<string>
using namespace std;
class Solution {
public:
	string LeftRotateString(string str, int n) {
		if (str==""){
			return "";
		}

		int bits = str.size()-n%str.size();
		ajust(str, 0, str.size());
		ajust(str,0,bits);
		ajust(str, bits, str.size());
		return str;
	}

	void ajust(string& str, int start, int end){
		if (start >= end)
			return;
		for (int i = start; i < (end+start)/2; i++){
			swap(str[i],str[end-i-1+start]);
		}
	}

	void swap(char &ch1,char &ch2){
		char temp = ch1;
		ch1 = ch2;
		ch2 = temp;
	}

};
#if 0
int main(){
	Solution *s = new Solution;
	cout << s->LeftRotateString("abcXYZdef",8);
	return 0;
}
#endif