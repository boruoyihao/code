/*
输入两个整数序列，第一个序列表示栈的压入顺序，
请判断第二个序列是否为该栈的弹出顺序。假设压入栈的所有数字均不相等。
例如序列1,2,3,4,5是某栈的压入顺序，
序列4，5,3,2,1是该压栈序列对应的一个弹出序列，
但4,3,5,1,2就不可能是该压栈序列的弹出序列。
*/
#include<iostream>
#include<vector>
#include<stack>
using namespace std;

class Solution {
public:
	bool IsPopOrder(vector<int> pushV, vector<int> popV) {
		int pushLength = pushV.size();
		int popLength = popV.size();
		bool flag = false;
		if (0 == pushLength&&0 == popLength)
		{
			flag = true;
			return flag;
		}
		if (pushLength != popLength){
			return flag;
		}
		stack<int>s;
		int startpop = 0;
		for (int i = 0; i < pushV.size(); i++){
			if (pushV[i] == popV[startpop]){
				startpop++;
				int temp;
				while (!s.empty())
				{
					temp = s.top();
					if (temp == popV[startpop]){
						startpop++;
						s.pop();
					}
					else
						break;
				}
			}
			else{
				s.push(pushV[i]);
			}
		}
		if (s.empty() && startpop == pushLength){
			flag = true;
		}
		return flag;

	}
	
};

#if 0
int main(){
	int array1[] = {1,2,3,4,5};
	int array2[] = {2,1,3,5,4};
	vector<int>v1(array1,array1+5);
	vector<int>v2(array2,array2+5);
	Solution*s = new Solution;
	cout << s->IsPopOrder(v1,v2)<<endl;
	return 0;
}
#endif