/*
请实现两个函数，分别用来序列化和反序列化二叉树
*/

#include<iostream>
#include<string>
#include<sstream>
using namespace std;
namespace tree12{
	struct TreeNode {
		int val;
		struct TreeNode *left;
		struct TreeNode *right;
		TreeNode(int x) :
			val(x), left(NULL), right(NULL) {
		}
	};
	class Solution {
	public:
		char* Serialize(TreeNode *root) {
			stringstream ss;
			Tree2char(root,ss);
			string *str = new string(ss.str());
			return const_cast<char*>(str->c_str());
		}
		void Tree2char(TreeNode*root,stringstream&ss){
			if (!root){
				ss << "#" << " ";
				return;
			}
			ss << root->val << " ";
			Tree2char(root->left,ss);
			Tree2char(root->right,ss);
		}

		TreeNode* Deserialize(char *str) {
			if (!str)
				return NULL;
			stringstream ss(str);
			TreeNode*root = createTree(ss);
			return root;
		}

		TreeNode*createTree(stringstream &ss){
			string data;
			ss >> data;
			if (data == "#")
				return NULL;
			TreeNode*temp = new TreeNode(atoi(data.c_str()));
			temp->left = createTree(ss);
			temp->right = createTree(ss);
			return temp;
		}
		
	};

	TreeNode*createTree(){
		int data;
		cin >> data;
		TreeNode*temp = NULL;
		if (-1 == data)
			return NULL;
		else{
			temp = new TreeNode(data);
			temp->left = createTree();
			temp->right = createTree();
		}
		return temp;
	}

	void print(TreeNode*root){
		if (!root)
			return;
		print(root->left);
		cout << root->val << " ";
		print(root->right);
	}

}

char*getStr(){
	char *str= "zhaolizhen";
	return str;
}


int main(){
	//using namespace tree12;
	//Solution*s = new Solution;
	//TreeNode*root=createTree();
	//char*str = getStr();
	////str[0] = 3;
	//cout << str << endl;

	using namespace tree12;
	Solution*s = new Solution;
	
	TreeNode*root=s->Deserialize("100 2 # # 3 5 # # 60000000 # #");
	cout << s->Serialize(root)<<endl;
	//TreeNode*root = createTree();
	//char*result=s->Serialize(root);
	//cout << result << endl;
	//TreeNode*root = s->Deserialize("12##35##6##");
	//print(root);
	//cout << endl;
	//cout << s->getNum(root) << endl;
	//char*result = s->Serialize(root);
	//cout << result << endl;
	return 0;
}