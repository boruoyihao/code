/*
如何得到一个数据流中的中位数？
如果从数据流中读出奇数个数值，那么中位数就是所有数值排序之后位于中间的数值。
如果从数据流中读出偶数个数值，那么中位数就是所有数值排序之后中间两个数的平均值。
*/

#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
	void Insert(int num)
	{
		if (v.size() == 0){
			v.push_back(num);
		}
		else{
			v.push_back(num);
			int i = v.size() - 1;
			for (; i >0; i--){
				if (v[i-1] > num){
					v[i] = v[i - 1];
				}
				else{
					break;
				}
			}
			v[i] = num;
		}
	}

	double GetMedian()
	{
		if (v.size() == 0)
			return 0;
		if (v.size() & 1){
			return v[v.size()/2];
		}
		else{
			return (v[v.size() / 2 - 1] + v[v.size() / 2])/2.0;
		}
	}
private:
	vector<int>v;
};

#if 0
int main(){
	Solution*s = new Solution;

	for (int i = 0; i < 2; i++){
		s->Insert(i);
	}

	cout << s->GetMedian() << endl;
	return 0;
}
#endif