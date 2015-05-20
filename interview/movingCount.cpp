/*
������һ��m�к�n�еķ���
һ�������˴�����0,0�ĸ��ӿ�ʼ�ƶ���ÿһ��ֻ�������ң��ϣ����ĸ������ƶ�һ��
���ǲ��ܽ�������������������λ֮�ʹ���k�ĸ��ӡ�
���磬��kΪ18ʱ���������ܹ����뷽��35,37������Ϊ3+5+3+7 = 18��
���ǣ������ܽ��뷽��35,38������Ϊ3+5+3+8 = 19��
���ʸû������ܹ��ﵽ���ٸ����ӣ�
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