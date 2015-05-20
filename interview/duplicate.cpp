/*
��һ������Ϊn����������������ֶ���0��n-1�ķ�Χ�ڡ� 
������ĳЩ�������ظ��ģ�����֪���м����������ظ��ġ�
Ҳ��֪��ÿ�������ظ����Ρ�
���ҳ�����������һ���ظ������֡�
���磬������볤��Ϊ7������{2,3,1,0,2,5,3}����ô��Ӧ��������ظ�������2����3��
*/
#include<iostream>
using namespace std;
class Solution {
public:
	// Parameters:
	//        numbers:     an array of integers
	//        length:      the length of array numbers
	//        duplication: (Output) the duplicated number in the array number
	// Return value:       true if the input is valid, and there are some duplications in the array number
	//                     otherwise false
	bool duplicate(int numbers[], int length, int* duplication) {
		if (numbers ==NULL || length <= 1)
			return false;

		int*array = new int[length];
		memset(array,0,sizeof(int)*length);
		for (int i = 0; i < length; i++){
			array[numbers[i]]++;
		}

		for (int i = 0; i < length; i++){
			if (array[i] >= 2){
				*duplication = i;
				return true;
			}
		}
		return false;
	}
};

#if 0
int main(){
	Solution*s = new Solution;
	int *dup = new int();
	int array[] = { 2, 7, 1, 0, 9, 5, 3 };
	cout<<s->duplicate(array,7,dup)<<endl;
	cout << *dup << endl;
	return 0;
}
#endif