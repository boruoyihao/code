/*
请实现一个函数用来判断字符串是否表示数值（包括整数和小数）。
例如，字符串"+100","5e2","-123","3.1416"和"-1E-16"都表示数值。 
但是"12e","1a3.14","1.2.3","+-5"和"12e+4.3"都不是。
*/
#include<iostream>
using namespace std;


class Solution {
public:
	bool isNumeric(char* string)
	{
		if (string == NULL)
			return false;
		char*p = string;
		if (*p == '+' || *p == '-')
			p++;

		int dotcount = 0;
		int ecount = 0;

		while (*p!='\0')
		{
			if (*p == '.'&&dotcount<1){
				dotcount++;
				if (*(p + 1) != '\0' && (*(p + 1) == 'e' || *(p + 1) == 'E')){
					return false;
				}
			}
			else if ((*p == 'E' || *p == 'e')&&ecount<1){
				ecount++;
				dotcount = 1;
				if (*(p + 1) != '\0' && (*(p + 1) == '+' || *(p + 1) == '-')){
					p++;
				}
				if (*(p + 1) == '\0')
					return false;
			}
			else if (*p>= '0'&&*p<='9'){
				
			}
			else{
				return false;
			}
			p++;
		}
		if (*p == '\0')
			return true;
		else
			return false;
	}

};
#if 0
int main(){
	Solution*s = new Solution;
	cout<<s->isNumeric("4.5666.");
	return 0;
}
#endif