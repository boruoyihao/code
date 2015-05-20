/*
�����һ�������������ж���һ���������Ƿ����һ������ĳ�ַ��������ַ���·����
·�����ԴӾ����е�����һ�����ӿ�ʼ��ÿһ�������ھ������������ң����ϣ������ƶ�һ�����ӡ�
���һ��·�������˾����е�ĳһ�����ӣ����·�������ٽ���ø��ӡ�
����3*4�ľ���     a b c e s f c s a d e e 
�����а���һ���ַ���"bcced"��·�������Ǿ����в�����"abcb"·����
��Ϊ�ַ����ĵ�һ���ַ�bռ���˾����еĵ�һ�еڶ�������֮��·�������ٴν���ø��ӡ�
*/
#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
	bool hasPath(char* matrix, int rows, int cols, char* str)
	{
		if (matrix == NULL || rows <= 0 || cols <= 0 || str == NULL)
			return false;
		vector<vector<char>>v;
		char*p = matrix;
		vector<char>vv;
		while (*p!='\0')
		{
			vv.push_back(*p);
			if (vv.size() % cols == 0){
				v.push_back(vv);
				vv.clear();
			}
			p++;
		}
		bool**status = new bool*[rows];
		for (int i = 0; i < rows; i++){
			status[i] = new bool[cols];
			memset(status[i], 0, sizeof(bool)* cols);
		}

		for (int i = 0; i < rows; i++){
			for (int j = 0; j < cols; j++){
				if (v[i][j] == *str){
					bool flag = false;
					DFS(v,i,j,status,str,flag);
					if (flag)
						return flag;
					else
						init(status,rows,cols);
				}
			}
		}
		return false;
	}
	void init(bool**&status, int rows, int cols){
		for (int i = 0; i < rows; i++){
			for (int j = 0; j < cols; j++){
				status[i][j] = false;
			}
		}
	}
	void DFS(vector<vector<char>>&v, int i, int j,bool**&status,char*str,bool&flag){
		if (*str == '\0')
			flag = true;

		if (i < 0 || i >= v.size() || j < 0 || j >= v[0].size())
			return;

		if (status[i][j]==true||*str != v[i][j])
			return;
		
		status[i][j] = true;
		DFS(v, i+1, j, status, str+1,flag);
		DFS(v, i-1, j, status, str+1,flag);
		DFS(v, i, j-1, status, str+1,flag);
		DFS(v, i, j+1, status, str+1,flag);

	}

};

#if 0
int main(){
	Solution*s = new Solution;
	cout<<s->hasPath("abcesfcsadee",3,4,"abcb")<<endl;
	return 0;
}
#endif