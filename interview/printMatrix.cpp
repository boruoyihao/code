/*
输入一个矩阵，按照从外向里以顺时针的顺序依次打印出每一个数字，
例如，如果输入如下矩阵： 
 1  2  3  4 
 5  6  7  8 
 9 10 11 12 
13 14 15 16 
则依次打印出数字1,2,3,4,8,12,16,15,14,13,9,5,6,7,11,10.
*/

#include<iostream>
#include<vector>
using namespace std;
class Solution {
public:
	vector<int> printMatrix(vector<vector<int> > matrix) {
		vector<int>result;
		int line = matrix.size();
		int row = matrix[0].size();
		if (0 == line||0==row)
			return result;
		int line1 = line-1, row1 = row-1;
		int line2 = 0, row2 = 0;
		while (line2<=line1&&row2<=row1)
		{
			for (int i = row2; i <= row1; i++){
				result.push_back(matrix[line2][i]);
			}
			line2++;

			if (line2 <= line1&&row1>=row2){
				for (int i = line2; i <= line1; i++){
					result.push_back(matrix[i][row1]);
				}
				row1--;
			}
			if (line2 <= line1&&row1 >= row2){
				for (int i = row1; i >= row2; i--){
					result.push_back(matrix[line1][i]);
				}
				line1--;
			}

			if (line2 <= line1&&row1 >= row2){
				for (int i = line1; i >= line2; i--){
					result.push_back(matrix[i][row2]);
				}
				row2++;
			}
		}
		return result;
	}
};

#if 0
int main(){
	vector<vector<int>>v;
	int array1[] = {1};
	vector<int>v1(array1,array1+1);
	int array2[] = {5};
	vector<int>v2(array2,array2+1);
	int array3[] = { 9 };
	vector<int>v3(array3,array3+1);
	int array4[] = { 13 };
	vector<int>v4(array4,array4+1);
	int array5[] = { 21 };
	vector<int>v5(array5,array5+1);
	v.push_back(v1);
	v.push_back(v2);
	v.push_back(v3);
	v.push_back(v4);
	v.push_back(v5);
	Solution*s = new Solution;
	vector<int>result = s->printMatrix(v);
	for (int i = 0; i < result.size(); i++){
		cout <<result[i] << " ";
	}
	cout << endl;
	return 0;
}
#endif