/*
��Ŀ����

��ʵ��һ�����������ҳ��ַ����е�һ��ֻ����һ�ε��ַ������磬�����ַ�����ֻ����ǰ�����ַ�"go"ʱ����һ��ֻ����һ�ε��ַ���"g"�����Ӹ��ַ����ж���ǰ�����ַ���google"ʱ����һ��ֻ����һ�ε��ַ���"l"��
�������:
�����ǰ�ַ���û�д��ڳ���һ�ε��ַ�������#�ַ���
*/

#include<iostream>
#include<string>
#include<map>
using namespace std;

class Solution
{
public:
	//Insert one char from stringstream
	void Insert(char ch)
	{
		s += ch;
	}
	//return the first appearence once char in current stringstream
	char FirstAppearingOnce()
	{
		map<char,int>m;
		for (int i = 0; i < s.length(); i++){
			m[s[i]]++;
		}

		for (int i = 0; i < s.length(); i++){
			if (m[s[i]] == 1){
				return s[i];
			}
		}
		return '#';
	}

private:
	string s;
};
#if 0
int main(){
	Solution*s = new Solution;
	s->Insert('g');
	s->Insert('o');
	s->Insert('o');
	//s->Insert('g');
	//s->Insert('l');
	//s->Insert('e');
	cout << s->FirstAppearingOnce()<<endl;
	return 0;
}
#endif