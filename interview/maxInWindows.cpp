/*
����һ������ͻ������ڵĴ�С���ҳ����л�����������ֵ�����ֵ��
���磬�����������{2,3,4,2,6,2,5,1}���������ڵĴ�С3��
��ôһ������6���������ڣ����ǵ����ֵ�ֱ�Ϊ{4,4,6,6,6,5}��
�������{2,3,4,2,6,2,5,1}�Ļ�������������6����
{[2,3,4],2,6,2,5,1}��
{2,[3,4,2],6,2,5,1}�� 
{2,3,[4,2,6],2,5,1}��
{2,3,4,[2,6,2],5,1}��
{2,3,4,2,[6,2,5],1}�� 
{2,3,4,2,6,[2,5,1]}��
*/
#include<iostream>
#include<vector>
#include<stack>
using namespace std;

#if 0
class S {
public:
	void push(int value) {
		s1.push(value);
		if (s2.empty()){
			s2.push(value);
		}
		else{
			int temp = s2.top();
			if (temp < value){
				s2.push(value);
			}
			else{
				s2.push(temp);
			}
		}
	}
	void pop() {
		if (s1.empty())
			return;
		s1.pop();
		s2.pop();
	}
	int top() {
		return s1.top();
	}
	int max() {
		return s2.top();
	}
private:
	stack<int>s1;
	stack<int>s2;
};

class Solution {
public:
	vector<int> maxInWindows(const vector<int>& num, unsigned int size)
	{
		vector<int>result;
		if (num.size() == 0 || size <= 0||size>num.size())
			return result;
		S*s = new S;
		int i, j;
		for (i = 0; i < size; i++){
			s->push(num[i]);
		}
		i = 0, j = size-1;
		while (j<num.size())
		{
			int max = s->max();
			result.push_back(max);
			s->pop();
			s->push(num[j]);
			i++, j++;
		}
		return result;
	}
};
#endif

class Solution {
public:
	vector<int> maxInWindows(const vector<int>& num, unsigned int size)
	{
		vector<int>result;
		if (num.size() == 0 || size <= 0 || size>num.size())
			return result;

		int i = 0,j = size-1;
		while (j<num.size())
		{
			int istart = i;
			int max = INT_MIN;
			while (istart<=j)
			{
				if (num[istart]>max)
					max = num[istart];
				istart++;
			}
			result.push_back(max);
			i++, j++;
		}

		return result;
	}
};

#if 0
int main(){
	Solution*s = new Solution;
	int array[] = { 2, 3, 4, 2, 6, 2, 5, 1 };
	vector<int>v(array,array+8);
	vector<int>result = s->maxInWindows(v,3);
	for (int i = 0; i < result.size(); i++){
		cout << result[i] << " ";
	}
	cout << endl;
	return 0;
}
#endif