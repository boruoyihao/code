/*
��Ŀ����
�������һ����Ա��Fish��ÿ���糿���ǻ�����һ��Ӣ����־��дЩ�����ڱ����ϡ�
ͬ��Cat��Fishд�������ĸ���Ȥ����һ������Fish������������ȴ������������˼��
���磬��student. a am I����
��������ʶ������һ�ԭ���Ѿ��ӵ��ʵ�˳��ת�ˣ���ȷ�ľ���Ӧ���ǡ�I am a student.����
Cat��һһ�ķ�ת��Щ����˳��ɲ����У����ܰ�����ô��
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