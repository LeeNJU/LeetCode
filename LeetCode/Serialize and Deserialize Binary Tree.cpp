#include "TreeNode.h"
#include<string>
#include<sstream>
//题目描述:给定一个二叉树，将其序列化成字符串，然后由字符串反序列化成二叉树
//解法描述:用先序遍历的方法进行序列化，#代替nullptr,用空格作为每个节点之间的分隔符。反序列化的时候，利用
//        istringstream来读取每个节点的值，istringstream会一直读取直到遇到空格或者换行符。

class Codec 
{
private:
	TreeNode* deserialize(std::istringstream& in)//这里必须是引用
	{
		std::string value;
		in >> value;
		if (value == "#")
			return nullptr;
		else
		{
			TreeNode* root = new TreeNode(stoi(value));
			root->left = deserialize(in);//读取完左子树的值，in的下一个值就是右子树的值
			root->right = deserialize(in);
			return root;
		}
	}
public:

	// Encodes a tree to a single string.
	std::string serialize(TreeNode* root) 
	{
		if (root == nullptr)
			return "# ";

		std::string left = serialize(root->left);
		std::string right = serialize(root->right);
		return std::to_string(root->val) + " " + left + right;
	}

	// Decodes your encoded data to tree.
	TreeNode* deserialize(std::string data) 
	{
		std::istringstream in(data);
		return deserialize(in);
	}
};