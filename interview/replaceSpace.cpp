/*
请实现一个函数，将一个字符串中的空格替换成“%20”。例如，当字符串为We Are Happy.则经过替换之后的字符串为We%20Are%20Happy。
*/

#include<iostream>
#include<string>
using namespace std;
class Solution {
public:
	string replaceSpace(string str) {
		string result;
		for (int i = 0; i < str.length(); i++){
			if (str[i] != ' '){
				result += str[i];
			}
			else{
				result += "%20";
			}
		}
		return result;
	}
};
#if 0
int main(){
	string str = "We Are Happy";
	Solution*s = new Solution;
	cout << s->replaceSpace(str)<<endl;
	return 0;
}
#endif