/*
��Ŀ����

��һ��ͯ�ڿ�Ҫ����,ţ��ΪС�����׼����һ��С��Ϸ��ѧ���˿��Խ�һ��С����ѱ�����������̣��ɹ���~
��һ��������Ҫ׼��һ��С��Ʒ������һ��һ��������С���Ѷ�ϲ���ģ�����㶮��~��
�ڶ�������С������Χ��һ����Ȧ�������ָ��һ����m���ñ��Ϊ0��С���ѿ�ʼ������
���������涨ÿ�κ���m���Ǹ�С����Ҫ���г��׸裬Ȼ���������Ʒ�����������ѡ���
���Ҳ��ٻص�Ȧ�У���������һ��С���ѿ�ʼ����������....������ȥ....ֱ��ʣ�����һ��С���ѣ�
���Բ��ñ��ݲ����õ����ܻ�ӭ��С��Ʒ������С��Ϸ������
��ô�������ˣ�����β��ܰ����ܻ�ӭ��С��Ʒ�⣨�ģ�����������Ϣ�����͸�����ϲ����С�����أ�
*/
#include<iostream>
using namespace std;


class Solution {
public:
	int LastRemaining_Solution(unsigned int n, unsigned int m)
	{
		if (n<=0||m<=0)
			return -1;
		int *array = new int[n];
		memset(array,0,sizeof(int)*n);
		int count = 0;
		int index = 0;
		m = m - 1;
		while (count<n)
		{
			int i = 0;
			while (i<=m)
			{
				if (array[index%n] == 0){
					i++;
				}
				index++;
			}

			array[(index-1)%n] = 1;
			count++;
		}

		return (index-1)%n;
	}
};


#if 0
int main(){
	Solution*s = new Solution;
	cout << s->LastRemaining_Solution(5,3);
	return 0;
}

#endif