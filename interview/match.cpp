/*
��ʵ��һ����������ƥ�����'.'��'*'��������ʽ��
ģʽ�е��ַ�'.'��ʾ����һ���ַ�����'*'��ʾ��ǰ����ַ����Գ�������Σ�����0�Σ��� 
�ڱ����У�ƥ����ָ�ַ����������ַ�ƥ������ģʽ��
���磬�ַ���"aaa"��ģʽ"a.a"��"ab*ac*a"ƥ�䣬������"aa.a"��"ab*a"����ƥ��
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
				return true;  //�൱��0����ʱ��
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
