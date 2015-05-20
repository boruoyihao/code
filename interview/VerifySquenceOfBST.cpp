/*
输入一个整数数组，判断该数组是不是某二叉搜索树的后序遍历的结果。
如果是则输出Yes,否则输出No。
假设输入的数组的任意两个数字都互不相同。
*/

#include<iostream>
#include<vector>
using namespace std;
namespace tree2{
	class Solution {
	public:
		bool VerifySquenceOfBST(vector<int> sequence) {
			if (0==sequence.size())
				return false;
			return vertify(sequence,0,sequence.size()-1);
		}

		bool vertify(vector<int>&sequence, int start, int end){
			if (start >= end){
				return true;
			}
			int middle = sequence[end];
			int i=start;
			for (; i < end; i++){
				if (sequence[i] > middle)
					break;

			}
			int mark = i;
			for (; i < end; i++){
				if (sequence[i] < middle){
					return false;
				}
			}
			return vertify(sequence,start,mark-1)&&vertify(sequence,mark,end-1);
		}
	};
}
#if 0
int main(){
	using namespace tree2;
	int array[] = {0,3,2,9,8,4,1};
	vector<int>v(array,array+7);
	Solution*s = new Solution;
	cout << s->VerifySquenceOfBST(v)<<endl;
}
#endif