/*
���1~13��������1���ֵĴ���,�����100~1300��������1���ֵĴ�����
Ϊ�����ر�����һ��1~13�а���1��������1��10��11��12��13��˹�����6��,���Ƕ��ں�����������û���ˡ�
ACMerϣ�����ǰ����,������������ձ黯,���Ժܿ���������Ǹ�����������1���ֵĴ�����
*/

#include<iostream>
#include<vector>
using namespace std;
#if 1
//��ͨ����
class Solution1 {
public:
	int NumberOf1Between1AndN_Solution(int n)
	{
		int sum = 0;
		for (int i = 1; i <= n; i++){
			
			int result=numofbits(i);
			//if(result)
			//	cout << i << " ";
			sum += result;
		}
		//cout << endl;
		return sum;
	}
	int numofbits(int number){
		int count = 0;
		while (number)
		{
			if (number % 10 == 1)
				count++;
			number /= 10; 
		}
		return count;
	}
};
#endif
//�ȡ���ָOffer���Ľⷨ���������
class Solution {
public:
	int NumberOf1Between1AndN_Solution(int n)
	{
		if (n <= 0)
			return 0;
		int number = n;
		vector<int>v;
		while (number)
		{
			v.push_back(number%10);
			number /= 10;
		}
		int sum = 0;
		for (int i = v.size() - 1; i >= 0; i--){
			if (i == v.size() - 1){
				if (v[i] == 1){
					sum += getNum(v,i)+1;
				}
				else{
					sum += pow(10,v.size()-1);
				}
			}
			else if (i == 0){
				if (v[i] == 0){
					sum += getNum(v, i);
				}
				else{
					sum += getNum(v,i)+1;
				}
			}
			else{
				int temp = pow(10, i);
				if (v[i] == 0){
					sum += (getNum(v, i) /temp) * temp;
				}
				else if(v[i]==1){
					sum += getNum(v, i)+1;
				}
				else{
					sum += (getNum(v, i)/temp+1)*temp;
				}
			}
		}
		return sum;
	}

	int getNum(vector<int>&v, int index){
		int sum = 0;
		for (int i = v.size() - 1; i >= 0; i--){
			if (index != i){
				sum = sum * 10 + v[i];
			}
		}
		return sum;
	}

};
#if 0
int main(){
	Solution1*s1 = new Solution1;

	//cout << s1->NumberOf1Between1AndN_Solution(3675)<<endl;
	//cout << endl;

	Solution *s = new Solution;
	//cout << s->NumberOf1Between1AndN_Solution(3675) << endl;
	//cout << endl;

	for (int i = 0; i < 21345; i++){
		if (s1->NumberOf1Between1AndN_Solution(i) != s->NumberOf1Between1AndN_Solution(i)){
			cout << i << " ";
		}
	}
	return 0;
}
#endif