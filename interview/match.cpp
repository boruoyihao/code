/*
请实现一个函数用来匹配包括'.'和'*'的正则表达式。
模式中的字符'.'表示任意一个字符，而'*'表示它前面的字符可以出现任意次（包含0次）。 
在本题中，匹配是指字符串的所有字符匹配整个模式。
例如，字符串"aaa"与模式"a.a"和"ab*ac*a"匹配，但是与"aa.a"和"ab*a"均不匹配
*/
#include<iostream>
using namespace std;

class Solution {
public:
	bool match(char* str, char* pattern)
	{
		if (!str || !pattern)
			return false;
		if (*str == '\0'&&*pattern == '\0')
			return true;
		if (*(pattern+1) == '*'){
			if (match(str, pattern + 2)){
				return true;  //相当于0个的时候
			}
			else{
				if (*str == *pattern||*pattern=='.'){
					if (match(str + 1, pattern + 2))
						return true;
					else
						return match(str+1, pattern)&&(*str!='\0');
				}
				else{
					return false;
				}
			}
		}
		else if (*str == *pattern||(*pattern=='.'&&*str!='\0')){
			return match(str+1,pattern+1);
		}
		else{
			return false;
		}


	}
};

#if 0
int main(){
	Solution*s = new Solution;
	cout << s->match("",".*")<<endl;
	return 0;
}
#endif
