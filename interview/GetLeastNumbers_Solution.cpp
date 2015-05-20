/*
输入n个整数，找出其中最小的K个数。例如输入4,5,1,6,2,7,3,8这8个数字，则最小的4个数字是1,2,3,4,。
*/

#include<iostream>
#include<vector>
#include<set>
#include <functional>
using namespace std;
class Solution {
public:
	vector<int> GetLeastNumbers_Solution(vector<int> input, int k) {
		vector<int>v;
		if (input.size() == 0||k<=0||k>input.size())
			return v;
		multiset<int,greater<int>>s;
		for (int i = 0; i < input.size(); i++){
			if (s.size() < k){
				s.insert(input[i]);
			}
			else{
				int begindata = *(s.begin());
				if (input[i] <= begindata){
					s.erase(begindata);
					s.insert(input[i]);
				}
			}
		}

		for (multiset<int>::const_reverse_iterator it = s.rbegin(); it != s.rend(); it++){
			v.push_back(*it);
		}
		s.clear();
		return v;
	}
};
#if 0
int main(){
	int array[] = {9,8,7,6,5,4,3,2,1};
	vector<int>v(array,array+9);
	Solution*s = new Solution;
	vector<int>result=s->GetLeastNumbers_Solution(v,40);
	for (int i = 0; i < result.size(); i++){
		cout << result[i] << " ";
	}
	cout << endl;
	return 0;
}
#endif