/*
LL���������ر��,��Ϊ��ȥ����һ���˿���,���������Ȼ��2������,2��С��(һ����ԭ����54��^_^)...
��������г����5����,�����Լ�������,�����ܲ��ܳ鵽˳��,����鵽�Ļ�,������ȥ��������Ʊ,�ٺ٣���
������A,����3,С��,����,��Ƭ5��,��Oh My God!������˳��.....
LL��������,��������,������\С �����Կ����κ�����,����A����1,JΪ11,QΪ12,KΪ13��
�����5���ƾͿ��Ա�ɡ�1,2,3,4,5��(��С���ֱ���2��4),��So Lucky!����
LL����ȥ��������Ʊ����
����,Ҫ����ʹ�������ģ������Ĺ���,Ȼ���������LL��������Ρ�
Ϊ�˷������,�������Ϊ��С����0��
*/
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int comp(int num1, int num2){
	return num1 < num2;
}
class Solution {
public:
	bool IsContinuous(vector<int> numbers) {
		if (numbers.size() < 5)
			return false;
		sort(numbers.begin(),numbers.end(),comp);
		int zerocount = 0;
		for (int i = 0; i < numbers.size(); i++){
			if (numbers[i] == 0){
				zerocount++;
			}
		}
		if (zerocount == 4)
			return true;
		int interval = 0;
		for (int i = zerocount+1; i < numbers.size(); i++){
			if (numbers[i] == numbers[i - 1]){
				return false;
			}
			else if(numbers[i]-numbers[i-1]>1){
				interval += numbers[i] - numbers[i - 1]-1;
			}
		}

		if (interval!=zerocount)
			return false;
		return true;
	}
};
# if 0
int main(){
	Solution*s = new Solution;
	int array[] = {1,3,8,0,0};
	vector<int>v(array,array+5);
	cout << s->IsContinuous(v)<<endl;
	return 0;
}
#endif