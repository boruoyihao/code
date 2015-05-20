/*
题目描述
小明很喜欢数学,有一天他在做数学作业时,要求计算出9~16的和,他马上就写出了正确答案是100。
但是他并不满足于此,他在想究竟有多少种连续的正数序列的和为100(至少包括两个数)。
没多久,他就得到另一组连续正数和为100的序列:18,19,20,21,22。
现在把问题交给你,你能不能也很快的找出所有和为S的连续正数序列? Good Luck!
输出描述:
输出所有和为S的连续正数序列。序列内按照从小至大的顺序，序列间按照开始数字从小到大的顺序
*/
#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
	vector<vector<int> > FindContinuousSequence(int sum) {
		vector<vector<int>>v;
		if (sum <= 0)
			return v;
		int index=getIndex(sum);
		for (int i = index; i >= 1; i--){
			int total=getsum(i);
			if ((sum - total) % (i+1) == 0){
				int start = (sum - total) / (i+1);
				vector<int>vv;
				for (int j = start; j <= start + i; j++){
					if (j == 0)
						continue;
					vv.push_back(j);
				}
				v.push_back(vv);
			}
		}
		return v;
	}
	int getIndex(int n){
		int sum = 0;
		int i = 0;
		while (sum+i<n)
		{
			sum = sum + i;
			i++;
		}
		return i-1;
	}
	int getsum(int n){
		int sum = 0;
		for (int i = 0; i <=n; i++){
			sum += i;
		}
		return sum;
	}
};

#if 0
int main(){
	Solution*s = new Solution;
	s->getIndex(105);
	vector<vector<int>>result=s->FindContinuousSequence(1);
	for (int i = 0; i < result.size(); i++){
		for (int j = 0; j < result[i].size(); j++){
			cout << result[i][j] << "  ";
		}
		cout << endl;
	}
	return 0;
}
#endif