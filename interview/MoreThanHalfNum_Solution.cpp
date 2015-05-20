/*
��������һ�����ֳ��ֵĴ����������鳤�ȵ�һ�룬���ҳ�������֡�
��������һ������Ϊ9������{1,2,3,2,2,2,5,4,2}��
��������2�������г�����5�Σ��������鳤�ȵ�һ�룬������2��
*/
#include<iostream>
#include<vector>
using namespace std;
# if 0
class Solution {
public:
	int MoreThanHalfNum_Solution(vector<int> numbers) {
		if (numbers.size() == 0)
			return 0;
		int result=moreThanHalf(numbers);
		if (check(numbers, result))
			return result;
		else
			return 0;
	}
	bool check(vector<int>numbers,int result){
		int count = 0;
		for (int i = 0; i < numbers.size(); i++){
			if (numbers[i] == result){
				count++;
			}
		}
		if (count>numbers.size() >> 1){
			return true;
		}
		else {
			return false;
		}
	}
	int moreThanHalf(vector<int>numbers){
		vector<int>result;
		for (int i = 1; i < numbers.size(); i += 2){
			if (numbers[i] == numbers[i - 1]){
				result.push_back(numbers[i]);
			}
		}
		if (numbers.size()&1){
			result.push_back(numbers[numbers.size() - 1]);
		}
		if (result.size() == 3){
			if (result[0] == result[1])
				return result[0];
			else
				return result[2];
		}
		else if (result.size() == 2||result.size()==1){
			return result[0];
		}
		else{
			return moreThanHalf(result);
		}
	}
};
#endif
class Solution {
public:
	int MoreThanHalfNum_Solution(vector<int> numbers) {
		if (numbers.size() == 0)
			return 0;
		int result = moreThanHalf(numbers);
		if (check(numbers, result))
			return result;
		else
			return 0;
	}

	int moreThanHalf(vector<int> v){
		int times = 1;
		int number = v[0];
		for (int i = 1; i < v.size(); i++){
			if (0==times){
				times = 1;
				number = v[i];
			}
			else if (v[i] == number){
				times++;
			}
			else if(v[i]!=number){
				times--;
			}
		}
		return number;
	}

	bool check(vector<int>numbers, int result){
		int count = 0;
		for (int i = 0; i < numbers.size(); i++){
			if (numbers[i] == result){
				count++;
			}
		}
		if (count>numbers.size() >> 1){
			return true;
		}
		else {
			return false;
		}
	}
};
#if 0
int main(){
	Solution*s = new Solution;
	//int array[] = { 1, 2, 3, 2, 2, 2, 5, 2,4};
	int array[] = { 1, 2, 3, 2, 4, 2, 5, 2, 5 };
	vector<int>v(array,array+9);
	cout << s->MoreThanHalfNum_Solution(v)<<endl;
	return 0;
}
#endif