/*
题目描述

六一儿童节快要到了,牛妹为小伙伴们准备了一个小游戏，学会了可以将一堆小盆友驯（调）服（教）成功噢~
第一步：你需要准备一堆小礼品，其中一份一定是所有小盆友都喜欢的，这个你懂哒~；
第二步：让小盆友们围成一个大圈，你随机指定一个数m，让编号为0的小盆友开始报数；
第三步：规定每次喊到m的那个小朋友要出列唱首歌，然后可以在礼品箱中任意的挑选礼物，
并且不再回到圈中，从他的下一个小朋友开始，继续报数....这样下去....直到剩下最后一个小朋友，
可以不用表演并且拿到最受欢迎的小礼品，至此小游戏结束；
那么问题来了，你如何才能把最受欢迎的小礼品光（悄）明（声）大（息）的送给你最喜欢的小盆友呢？
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