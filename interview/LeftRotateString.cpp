/*
��Ŀ����
�����������һ����λָ�����ѭ�����ƣ�ROL���������и��򵥵����񣬾������ַ���ģ�����ָ�����������
����һ���������ַ�����S���������ѭ������Kλ������������
���磬�ַ�����S=��abcXYZdef��,Ҫ�����ѭ������3λ��Ľ��������XYZdefabc����
�ǲ��Ǻܼ򵥣�OK���㶨����
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