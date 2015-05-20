/*
求出1~13的整数中1出现的次数,并算出100~1300的整数中1出现的次数？
为此他特别数了一下1~13中包含1的数字有1、10、11、12、13因此共出现6次,但是对于后面问题他就没辙了。
ACMer希望你们帮帮他,并把问题更加普遍化,可以很快的求出任意非负整数区间中1出现的次数。
*/

#include<iostream>
#include<vector>
using namespace std;
#if 1
//普通方法
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
//比《剑指Offer》的解法更容易理解
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