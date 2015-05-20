/*
题目描述
给定一个数组A[0,1,...,n-1],请构建一个数组B[0,1,...,n-1],
其中B中的元素B[i]=A[0]*A[1]*...*A[i-1]*A[i+1]*...*A[n-1]。
不能使用除法。
*/
#include<iostream>
#include<vector>
using namespace std;


class Solution {
public:
	vector<int> multiply(const vector<int>& A) {
		vector<int>result;
		if (A.size() <=1)
			return result;

		int *left = new int[A.size()];
		init(left, A.size());

		int *right = new int[A.size()];
		init(right, A.size());

		for (int i = 0; i < A.size()-1; i++){
			left[i+1] = left[i] * A[i];
		}

		for (int i = A.size() - 1; i > 0; i--){
			right[i-1] = right[i] * A[i];
		}

		for (int i = 0; i < A.size(); i++){
			int sum = left[i] * right[i];
			result.push_back(sum);
		}

		return result;
	}

	void init(int *array,int length){
		for (int i = 0; i < length; i++){
			array[i] = 1;
		}
	}

	void print(int *array, int length){
		for (int i = 0; i < length; i++){
			cout << array[i] << " ";
		}
		cout << endl;
	}
};

#if 0
int main(){
	int array[] = { 2 };
	vector<int>A(array, array + 1);
	Solution*s = new Solution;
	vector<int>result = s->multiply(A);
	for (int i = 0; i < result.size(); i++){
		cout << result[i] << " ";
	}
	return 0;
}
#endif