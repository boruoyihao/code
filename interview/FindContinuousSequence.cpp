/*
��Ŀ����
С����ϲ����ѧ,��һ����������ѧ��ҵʱ,Ҫ������9~16�ĺ�,�����Ͼ�д������ȷ����100��
���������������ڴ�,�����뾿���ж������������������еĺ�Ϊ100(���ٰ���������)��
û���,���͵õ���һ������������Ϊ100������:18,19,20,21,22��
���ڰ����⽻����,���ܲ���Ҳ�ܿ���ҳ����к�ΪS��������������? Good Luck!
�������:
������к�ΪS�������������С������ڰ��մ�С�����˳�����м䰴�տ�ʼ���ִ�С�����˳��
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