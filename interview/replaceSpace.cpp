/*
��ʵ��һ����������һ���ַ����еĿո��滻�ɡ�%20�������磬���ַ���ΪWe Are Happy.�򾭹��滻֮����ַ���ΪWe%20Are%20Happy��
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