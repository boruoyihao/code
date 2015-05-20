/*
地上有一个m行和n列的方格。
一个机器人从坐标0,0的格子开始移动，每一次只能向左，右，上，下四个方向移动一格，
但是不能进入行坐标和列坐标的数位之和大于k的格子。
例如，当k为18时，机器人能够进入方格（35,37），因为3+5+3+7 = 18。
但是，它不能进入方格（35,38），因为3+5+3+8 = 19。
请问该机器人能够达到多少个格子？
*/
#include<iostream>
using namespace std;


class Solution {
public:
	int movingCount(int threshold, int rows, int cols)
	{
		bool**status = new bool*[rows];
		for (int i = 0; i < rows; i++){
			status[i] = new bool[cols];
			memset(status[i],false,sizeof(bool)*cols);
		}
		int sum = DFS(status,0,0,rows,cols,threshold);
		return sum;
	}

	int DFS(bool**&status,int i,int j,int rows,int cols,int threshold){
		if (i < 0 || i>rows - 1 || j < 0 || j > cols - 1)
			return 0;
		if (status[i][j])
			return 0;
		if (getBitsSum(i) + getBitsSum(j) <= threshold)
			status[i][j] = 1;
		else
			return 0;
		return 1+DFS(status, i-1, j, rows, cols,threshold) + 
			DFS(status, i+1, j, rows, cols,threshold) + 
			DFS(status, i, j-1, rows, cols,threshold)
			+ DFS(status, i, j+1, rows, cols,threshold);
	}

	int getBitsSum(int number){
		int sum = 0;
		while (number)
		{
			sum += number % 10;
			number /= 10;
		}
		return sum;
	}
};


#if 0
int main(){
	Solution*s = new Solution;
	cout<<s->movingCount(5,4,6)<<endl;
	return 0;
}
#endif