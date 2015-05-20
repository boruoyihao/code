/*
题目描述
最近来了一个新员工Fish，每天早晨总是会拿着一本英文杂志，写些句子在本子上。
同事Cat对Fish写的内容颇感兴趣，有一天他向Fish借来翻看，但却读不懂它的意思。
例如，“student. a am I”。
后来才意识到，这家伙原来把句子单词的顺序翻转了，正确的句子应该是“I am a student.”。
Cat对一一的翻转这些单词顺序可不在行，你能帮助他么？
*/
#include<iostream>
#include<string>
using namespace std;
class Solution {
public:
	string ReverseSentence(string str) {
		if (str == "")
			return str;
		ajust(str,0,str.size());
		int start = 0;
		int i = 0;
		for (; i < str.length(); i++){
			if (str[i] == ' '){
				ajust(str,start,i);
				start = i + 1;
			}
		}
		ajust(str, start, i);
		return str;
	}

	void ajust(string& str, int start, int end){
		if (start >= end)
			return;
		for (int i = start; i < (end + start) / 2; i++){
			swap(str[i], str[end - i - 1 + start]);
		}
	}
};
#if 0
int main(){
	Solution*s = new Solution;
	cout << s->ReverseSentence("zhao yu   uv it")<<endl;
	return 0;
}
#endif