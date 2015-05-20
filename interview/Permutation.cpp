/*  Hard
输入一个字符串,按字典序打印出该字符串中字符的所有排列。
例如输入字符串abc,则打印出由字符a,b,c所能排列出来的所有字符串abc,acb,bac,bca,cab和cba。
输入描述:
输入一个字符串,长度不超过9(可能有字符重复),字符只包括大小写字母。
按字典序打印出该字符串中字符的所有排列。
*/
#include<iostream>
#include<vector>
#include<string>
#include<hash_set>
#include<set>
using namespace std;

class Solution {
public:
	vector<string> Permutation(string str) {
		vector<string>v;
		if (0 == str.length()){
			return v;
		}
		set<string>s;
		Permutation(str,s,0);
		set<string>::iterator it;
		for (it = s.begin(); it != s.end(); it++){
			v.push_back(*it);
		}
		return v;
	}

	void Permutation(string str,set<string>&s,int begin){
		if (begin == str.length()){
			s.insert(str);
			return;
		}
		for (int i = begin; i < str.length(); i++){
			swap(str[i], str[begin]);
			Permutation(str, s, begin + 1);
			swap(str[i], str[begin]);
		}
	}

	void swap(char &ch1, char &ch2){
		char temp = ch1;
		ch1 = ch2;
		ch2 = temp;
	}
};
#if 0
int main(){
	Solution*s = new Solution;
	vector<string>result = s->Permutation("abc");
	for (int i = 0; i < result.size(); i++){
		cout << result[i] << " ";
	}
	cout << endl;

	/*
	set<string>h;
	h.insert("abc");
	h.insert("cab");
	h.insert("cab");
	h.insert("bac");
	set<string>::iterator it;
	for (it = h.begin(); it != h.end(); it++){
		cout << *it << " ";
	}
	cout << endl;


	set<int>number;
	number.insert(2);
	number.insert(1);
	number.insert(3);
	for (set<int>::iterator itt = number.begin(); itt != number.end(); itt++){
		cout << *itt << " ";
	}
	cout << endl;*/
	
	return 0;
}
#endif